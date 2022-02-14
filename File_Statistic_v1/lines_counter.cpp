/*
 * lines_counter.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: tomek93
 */

#include "line_counter.hpp"

inline std::mutex counter_mutex;
thread_pool pool;

void count_lines(std::string dir_entry,  unsigned *counteralllines, unsigned *counterallnonemptylines)
{
    std::ifstream input2;
    unsigned counterlines = 0;
    unsigned counternonemptylines = 0;
    std::string line;

    input2.open(dir_entry);  //opening file
    if(!input2.fail())       //Checking the correct opening
    {
        while (std::getline(input2 , line))
        {
            ++counterlines;// increamenting counter of lines
            if(line.size()) //If lines non-empty
            ++counternonemptylines; //increamenting counter of non-empty lines
        }

       //std::cout<< std::setw(110)<<std::left << dir_entry<< std::setw(30)<< counterlines << std::setw(30)<< counternonemptylines << std::endl;

        const std::lock_guard<std::mutex> lock(counter_mutex); //
        *counteralllines += counterlines;
        *counterallnonemptylines += counternonemptylines;
     }
    else
        std::cout<<"FILE OPEN ERROR!!!"<<std::endl;
    input2.close();
}



void directory_browsing(std::string defaultpath, unsigned &counterfiles, unsigned* counteralllines, unsigned* counterallnonemptylines)
{
    std::string filepath;
    for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(defaultpath)) // Recursive searching files
    {
        if (!dir_entry.is_directory()) // if is not catalog
        {
            counterfiles++;  //increment counters of files
            filepath = dir_entry.path().string();// conversion from path to string
            pool.push_task(count_lines, filepath, counteralllines, counterallnonemptylines); //push function to queue task for threats
        }
    }
    pool.wait_for_tasks();// waiting for end of queue task
}