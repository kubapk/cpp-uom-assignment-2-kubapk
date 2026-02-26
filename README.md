### Kuba Kane
# PHYS30762 Assignment 2 - Course Marks Data

### Compilation Guidlines
The source file is `assignment-2.cpp`. This code was run on VSC on a Windows 11 device, using the compilation line `g++ assignment-2.cpp -o assignment-2.exe`

### Program Reasoning
 - Separate functions were created to calculate mean, standard deviation and standard error since they were repeated for all data and for the filtered data. They use for loops to sum over all marks data.
 - Function `output_check(string* input_ptr)` created (using pointers to reduce memory usage) to check if valid input "y" or "n" was entered (since this is used twice in the code).
 - Most variables are initialised within the beggining of the main function. Variables which are only required depending on user input are initialised within an if loop so that they are initialised if user requests them to be.
 - File is read in, and checked if it cannot be opened. While loop is used to read line by line until there are no more lines to read, and mark, course code and course name stored separately.
 - String stream `ss` used to remove blank space in front of course name in file.
 - `counter` used to find number of data entries in the file.
 - User is asked for academic year, and this is compared to first character of course_codes (use year[0] so that it is of type "char" and allows comparison).
 - Mean, standard deviation, standard error is calculated for data within user-inputted year only.
 - If user requests to order data, a vector of indices is generated to keep track of the placement of the course names (parameter which is ordered).
 - A lambda function is used to compare the course names, and switch indices if the order is incorrect. This then gives a list of indices which correspond to the placement of the course names. These indices can be used to print out the marks, course codes and course in an order corresponding to the alphabetical order of the course names.
 - There was originally a function using `read_file.fail()` to see if there was an error while trying to read a line from the file, but the while loop sorts this out, since it stops once there are no more lines to read.



### Disclosure of Delegation to Generative AI
The author (Kuba Kane) declares the use of generative AI in the research and coding process, only where attempts to find information from a search engine were not successful.

The following tasks were delegated to GAI tools under full human supervision:

- Code optimisation 
  - *GAI suggested alternatives for finding number of data entries*
- Idea generation 
  - *GAI suggested ways of handling additional whitespace in front of course names in `course_marks.dat`, i.e. string stream and ws*
  - *GAI suggested ways of returning all fields once filtered data was sorted by course name, i.e. lambda function `&`*
  - *GAI suggested way of generating indices 0 to n for a length-n vector, i.e. `std::iota` function*

The GAI tool used for these tasks was: ChatGPT-5.2.

The author declares that the work does not contain any AI-generated code. GAI was used as a source of information for explaining code only.

Responsibility for the final manuscript lies entirely with the author.

GAI tools are not listed as authors and do not bear responsibility for the final outcomes.