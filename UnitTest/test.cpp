#include "pch.h"
#include "../File_Statistic_v1/lines_counter.cpp"
#include "Create_test_catalog.hpp"

std::string testpath = "C:\\katalogtestowy";

TEST(count_lines, CountLines) {

	
	create_catalog(testpath, 1, 1, 10000); //Function create testing folders.
	//std::string testpath = "C:\\Users\\piotrowskit\\source\\repos\\File_Statistic_v1\\File_Statistic_v1\\katalog_testowy\\folder0\\file.txt";

	unsigned counterfiles = 0;//global counter number of files
	unsigned counteralllines = 0; //global counter number of lines
	unsigned counterallnonemptylines = 0; //global counter number of non-empty lines
	
	count_lines(testpath+"\\folder0\\file.txt", &counteralllines, &counterallnonemptylines);
	
  EXPECT_EQ(counteralllines, 20000);
  EXPECT_EQ(counterallnonemptylines, 10000);
  EXPECT_TRUE(true);
}