//Bryant Wong
//CSCI 2421 Homework 5

#ifndef _LINKED_LIST
#define	_LINKED_LIST

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



struct Node						//structure declaration of a Node
{
	std::string data;			//each node contains a string data
	Node* nextPtr;				//each node contains a pointer to point to the next node 
	Node();
};


class LinkedList
{
	private:
		Node* headPtr;				//each list has a head pointer


	public:		
		~LinkedList();				//destructor declaration	
		LinkedList();				//constructor declaration

		bool insertAtFront(std::string inputData);						//member function declarations
		bool insertBeforePosition(int index, std::string inputData);
		bool insertAtBack(std::string);
		bool deleteAtFront();
		bool deleteBeforePosition(int index);
		bool deleteAtBack();
		void printData();						//overloaded function declaration to print data in a list
		void printData(Node * head);			//overloaded function declaration to print data in a list whose head pointer is given
		void operator +(LinkedList& right);		//overloaded operator + declaration to concactenate two lists
		void operator -(LinkedList& right);		//overloaded operator - declaration to give the difference between two lists
};

#endif