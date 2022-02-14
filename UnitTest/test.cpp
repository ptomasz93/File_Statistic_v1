#include "pch.h"
#include "../File_Statistic_v1/lines_counter.cpp"
#include "Create_test_catalog.hpp"

std::string testpath = "C:\\katalogtestowy";
int numberlines = 20000;
int numberfirstlevelcatalog = 10;
int depth = 10;

/*
Test for function:  void count_lines(std::string dir_entry,  unsigned *counteralllines, unsigned *counterallnonemptylines);
*/

TEST(count_lines, CountLines) {

	unsigned counterfiles = 0;//global counter number of files
	unsigned counteralllines = 0; //global counter number of lines
	unsigned counterallnonemptylines = 0; //global counter number of non-empty lines
	
	//create_catalog(testpath, numberfirstlevelcatalog, depth, numberlines); //Function create testing folders.
	
	count_lines(testpath+"\\folder0\\file.txt", &counteralllines, &counterallnonemptylines);
	
  EXPECT_EQ(counteralllines, 2*numberlines);
  EXPECT_EQ(counterallnonemptylines, numberlines);
  EXPECT_TRUE(true);
}

/*
Test for function:  void directory_browsing(std::string defaultpath, unsigned &counterfiles, unsigned* counteralllines, unsigned* counterallnonemptylines)
*/
TEST(count_lines, DirectoryBrowsing)
{
	unsigned counterfiles = 0;//global counter number of files
	unsigned counteralllines = 0; //global counter number of lines
	unsigned counterallnonemptylines = 0; //global counter number of non-empty lines
	directory_browsing(testpath, counterfiles, &counteralllines, &counterallnonemptylines);
	
	EXPECT_EQ(counterfiles, numberfirstlevelcatalog +numberfirstlevelcatalog * depth);
	EXPECT_EQ(counteralllines,  2 * numberlines*(numberfirstlevelcatalog + numberfirstlevelcatalog * depth));
	EXPECT_EQ(counterallnonemptylines, numberlines*(numberfirstlevelcatalog + numberfirstlevelcatalog * depth));
	EXPECT_TRUE(true);

}