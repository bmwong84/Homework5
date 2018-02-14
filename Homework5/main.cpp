//Bryant Wong
//CSCI 2421 Homework 5

#include "LinkedList.h"

int main()
{
	LinkedList listA;				//create a LinkedList object to hold first list imported from file
	LinkedList listB;				// to hold second list
	LinkedList listTest;			//to hold list for the member functions in the menu
	std::ifstream infile;			//create an inputfile stream
	std::string inputData;			//create a temp string to hold data to send to functions
	
	infile.open("input.txt");				//open the file containing data
	std::string line;
	if (std::getline(infile, line))			//reads the line from file until reaches the end of a line and keeps it in the string line
	{
		std::istringstream inss(line);		//creates a stringstream to input the line
		while (inss >> inputData)			//while data is read from the stringstream, skipping spaces
		{
			listA.insertAtBack(inputData);		//insert each data point into the back of listA one at a time
		}
	}
	if (std::getline(infile, line))				//same as above, except for 2nd line into listB
	{
		std::istringstream inss(line);
		while (inss >> inputData)
		{
			listB.insertAtBack(inputData);
		}
	}
	infile.close();								//close the file so resets the starting read point if opened again
	std::cout << "Data read from file" << std::endl;

	char menuChoice = '0';
	while (menuChoice != '9')			//menu loop 
	{
		std::cout << "Menu" << std::endl;
		std::cout << "1. Add a node to the front of a list" << std::endl;
		std::cout << "2. Add a node to a given position in a list" << std::endl;
		std::cout << "3. Add node to the end of a list" << std::endl;
		std::cout << "4. Delete front node of a list" << std::endl;
		std::cout << "5. Delete a node at a given position from the list" << std::endl;
		std::cout << "6. Delete the node at the end of a list" << std::endl;
		std::cout << "7. Concactenate the two lists read from the file" << std::endl;
		std::cout << "8. Give the difference of the two lists read from a file" << std::endl;
		std::cout << "9. Exit" << std::endl;

		int nodePosition = 0;
		std::cin >> menuChoice;
		switch (menuChoice)
		{
		case '1':
			std::cout << "Enter data to insert into front node of list" << std::endl;
			std::cin >> inputData;					//user inputs data
			listTest.insertAtFront(inputData);		//inserts the data the user inputted into the first node
			listTest.printData();					//displays the list
			break;
		case '2':
			std::cout << "Enter position you wish to insert a node" << std::endl;					//asks for the position in the list that the user wants to enter a new node
			std::cin >> nodePosition;
			std::cout << "Enter data to insert into node " << nodePosition << " of list" << std::endl;
			std::cin >> inputData;																	//asks for data
			listTest.insertBeforePosition(nodePosition, inputData);									//inserts the user data into the specified node
			listTest.printData();
			break;
		case'3':
			std::cout << "Enter data to last node of list" << std::endl;	
			std::cin >> inputData;
			listTest.insertAtBack(inputData);			//calls function to insert user data into the last node
			listTest.printData();
			break;
		case'4':
			listTest.deleteAtFront();			//deletes the first node containing data
			listTest.printData();
			break;
		case'5':
			std::cout << "Enter position of node you wish to delete" << std::endl;
			std::cin >> nodePosition;
			listTest.deleteBeforePosition(nodePosition);			//deletes the node at the position the user specified
			listTest.printData();
			break;
		case'6':
			listTest.deleteAtBack();				//deletes the last node
			listTest.printData();
			break;
		case'7':
			//concactenate two linked lists
			listA + listB;			//concactenates the two lists that were read from file 
			break;
		case '8':
			listA - listB;			//prints the data of listA with listB data removed from listA
			break;
		case'9':
			break;
		default:
			std::cout << "Invalid entry" << std::endl;
		}
	}

	std::cin.get();
	return 0;
}