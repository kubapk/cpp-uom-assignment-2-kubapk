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
#include<sstream>
#include<cmath>
using std::string;
using std::vector;

//Constants

//Function to calculate mean
double compute_mean(vector<double> entries, int length)
{
  double sum{0.0};
  for(size_t j{0}; j < length; j++)
  {
    sum += entries[j]; //add entries[j] to sum for each j
  }
  double mean{sum / length};
  return mean;
}


//Function to calculate standard deviation
double compute_stan_dev(vector<double> entries, int length, double mean)
{
  double variance_sum{0.0};
  for(size_t k{0}; k < length; k++)
  {
    double difference = entries[k] - mean;
    variance_sum += difference*difference;
  }
  double standard_deviation{std::sqrt(variance_sum / (length-1))};
  return standard_deviation;
}


//Function to calculate standard error
double compute_standard_error(double standard_deviation, int length)
{
  return standard_deviation / (std::sqrt(length));
}


int main()
{
  //Variables
  vector<double> marks; //vector "marks" to store all of the marks in the file
  double mark; //vector "mark" to store each mark
  int course_code;
  string course_name; 
  string line; //string to read in one line from the data file
  int counter{0}; //counter intitialised at 0
  string full_list; //stores user choice "y" or "n" to print full list
  string year; //year to print out data for

  //Read in data file
  std::ifstream read_file("course_marks.dat");

  //Check if file opened correctly
  if(!read_file.good())
  {
    std::cerr<<"Error: File could not be opened"<<std::endl;
    return(1);
  }

  //Read the file line by line
  while (getline(read_file, line)) //getline(source, destination)
  {
      counter++; //increment counter by 1

      std::stringstream ss(line); //create string stream called ss and initialise it with "line"
      ss>>mark>>course_code; //up to first space of ss stored in "mark", up to second space stored in "course_code"
      getline(ss>>std::ws, course_name); //assign last part of ss to course_name, removing blank space using "ws"

      marks.push_back(mark); //add each mark to vector "marks"
  }
  
  read_file.close();

  //Print out number of data entries in file
  std::cout<<"The number of data entries in the file is "<<counter<<std::endl;

  //Ask user if all marks should be printed
  std::cout<<"Do you want to print out the full list of marks (y/n)? ";
  std::cin>>full_list;

  //Loop to ask for input again if input is not "y" or "n" (or contains extra characters)
  while(full_list!="y" && full_list!="n" || std::cin.peek() != '\n') 
  {
    std::cout<<" Enter only 'y' or 'n'. Try again: ";
    std::cin.ignore(1000, '\n');
    std::cin>>full_list;
  }


  //Print out full list of marks
  if(full_list=="y")
  {
    std::cout<<"\nList of all marks: "<<std::endl;
    for(size_t i{0}; i<marks.size(); i++)
    {
      std::cout<<marks[i]<<std::endl;
    }
    std::cout<<std::endl;
  }

  //Compute mean
  double total_mean{compute_mean(marks, counter)};
  std::cout<<"Mean of all marks = "<<total_mean<<std::endl;

  //Compute standard deviation
  double total_standard_deviation{compute_stan_dev(marks, counter, total_mean)};
  std::cout<<"Standard deviation of all marks = "<<total_standard_deviation<<std::endl;

  //Compute standard error
  double total_standard_error{compute_standard_error(total_standard_deviation, counter)};
  std::cout<<"Standard error of all marks = "<<total_standard_error<<std::endl;

  //List of marks for a year (DEFINE MEAN, STAND DEV, STAND ERROR SEPARATELY)
  std::cout<<"Enter an academic year (1, 2, 3, or 4) to print the marks for: ";
  std::cin>>year;

  //Loop to ask for input again if input is not "y" or "n" (or contains extra characters)
  while(year!="1" && year!="2" && year!="3" && year!="4" || std::cin.peek() != '\n') 
  {
    std::cout<<" Enter only '1', '2', '3', or '4'. Try again: ";
    std::cin.ignore(1000, '\n');
    std::cin>>year;
  }

  return 0;
}
