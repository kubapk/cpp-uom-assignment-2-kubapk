/*
________________TITLE_______________________
PHYS30762 Assignment 2 - Course Marks Data
____________________________________________
This C++ script reads data from a file containing course grades,
and calculates the mean, standard deviation and standard error 
of the grades.

Created by Kuba Kane (ID: 11019699)
Created on Tue 24 Feb 2026
Last updated on XX XX Feb 2026
*/

#include<iostream> //input output stream
#include<fstream> //file stream
#include<string> //to use C++ strings
#include<vector> //to use vectors
using std::string;
using std::vector;

//Constants


int main()
{
  //Variables
  vector<double> marks; //vector "marks" with entries of type double
  double mark; //vector "mark" of type double
  int course_code; //integer "course_code"
  string course_name; 

  //Read in data file
  std::ifstream read_file("course_marks.dat");

  //Check if file opened correctly
  if(!read_file.good())
  {
    std::cerr<<"Error: File could not be opened"<<std::endl;
    return(1);
  }

  //Read the file line by line



  std::cout<<"\nThe number of data entries in the file is "<<counter<<std::endl;
  return 0;
}
