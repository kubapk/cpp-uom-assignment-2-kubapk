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

#include<iostream>
#include<fstream>
#include<string>
using std::string;

//Constants


int main()
{
  //Variables
  string full_list;

  std::ifstream read_file("course_marks.dat"); //reads in file

  //Errors in opening file
  
  string my_data; //define a string called "my_data" to store all data in file
  int counter{0}; //define a counter & initialise it at 0

  //Ask user if full list should be printed
  std::cout<<"Do you want to print out the full list of marks (y/n)? ";
  std::cin>>full_list;

  //Loop to ask for input again if input is not "y" or "n" (or contains extra characters)
  while(full_list!="y" && full_list!="n" || std::cin.peek() != '\n') 
  {
    std::cout<<" Enter only 'y' or 'n'. Try again: ";
    std::cin.ignore(1000, '\n');
    std::cin>>full_list;
  }
        
  while(getline (read_file, my_data))
  {
    counter++;
    if(full_list=="y")
    {
      std::cout<<my_data<<std::endl;
    }
  }

  std::cout<<"\nThe number of data entries in the file is "<<counter<<std::endl;
  return 0;
}
