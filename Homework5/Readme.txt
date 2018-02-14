*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2421           
*  HW#       :  5          
*  Due Date  :  Feb 22, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates linked lists, allows the user to add and delete nodes from a list
containing data to the front, back, and at a specified position.  Additionally, this reads
two lines of data, populates two different lists with these data, and gives the concactenated
list as well as the list of elements that remain after elements of the second list have been
removed from the first list.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This creates several lists and allows the user to manipulate them via member functions.


Name:  LinkedList.cpp
   Contains member functions that add and remove nodes from front, back, and a given position from a list
as well as overloaded operator functions that concactenate and give the difference between two lists read
from a file.

Name: LinkedList.h
   Contains the class definition of LinkedList class and the object definition of Struct Node.

   
*******************************************************
*  Circumstances of programs
*******************************************************
The program is complete and compiles and runs on visual studio community and csegrid.



Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongHW5]

   Now you should see a directory named homework with the files:
        main.cpp
	LinkedList.h
	LinkedList.cpp
        makefile
        Readme.txt
	analysis.txt
	input.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongHW5] 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw5

4. Delete the obj files, executables, and core dump by
   %./make clean
