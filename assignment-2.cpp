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
using std::string;

//Constants


int main()
{
  //Variables
  string full_list;
  string my_data; //string called "my_data" to store all data in file
  int counter{0}; //counter initialised at 0

  //Read in data file
  std::ifstream read_file("course_marks.dat");

  //Check if file opened correctly
  if(!read_file.good())
  {
    std::cerr<<"Error: File could not be opened"<<std::endl;
    return(1);
  }




  std::cout<<"\nThe number of data entries in the file is "<<counter<<std::endl;
  return 0;
}
