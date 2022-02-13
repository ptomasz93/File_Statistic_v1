#include "pch.h"
#include "../File_Statistic_v1/lines_counter.cpp"
#include "Create_test_catalog.hpp"

std::string testpath = "C:\\katalogtestowy";

TEST(count_lines, CountLines) {
	int numberlines = 20000;
	
	create_catalog(testpath, 10, 10, numberlines); //Function create testing folders.


	unsigned counterfiles = 0;//global counter number of files
	unsigned counteralllines = 0; //global counter number of lines
	unsigned counterallnonemptylines = 0; //global counter number of non-empty lines
	
	count_lines(testpath+"\\folder0\\file.txt", &counteralllines, &counterallnonemptylines);
	
  EXPECT_EQ(counteralllines, 2*numberlines);
  EXPECT_EQ(counterallnonemptylines, numberlines);
  EXPECT_TRUE(true);
}