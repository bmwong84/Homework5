//Bryant Wong
//CSCI 2421 Homework 5

#include "LinkedList.h"


LinkedList::LinkedList()
{
	headPtr = nullptr;
}

Node::Node()
{
	this->nextPtr = nullptr;		//to set the last node to point to nullptr
}

LinkedList::~LinkedList()
{
	Node* tempPtr;                //temp pointer
	while (headPtr != nullptr)        //while headPtr is pointing at a real node
	{
		tempPtr = headPtr->nextPtr;        //the tempPtr points to the address of the node after headPtr
		delete headPtr;        //delete the pointer to the node headPtr is pointing at
		headPtr = tempPtr;        //set headPtr to the node that was after original headPtr
	}

}


bool LinkedList::insertAtFront(std::string inputData)
{
	Node *currentPtr;
	if (headPtr == nullptr)			//if the headPtr is nullptr, the list is empty so add a new node
	{
		headPtr = new Node;				//create a new node named headPtr
		headPtr->data = inputData;		//set the new node's data to whatever the user input
		headPtr->nextPtr = nullptr;		//set node's nextPtr to nullptr to signify it's the end of the list
		std::cout << headPtr->data << " entered into front node" << std::endl;
		return true;
	}
	else if (headPtr != nullptr)
	{
		currentPtr = new Node;				//create new node named currentPtr
		currentPtr->data = inputData;		//set new node's data to user input
		std::cout << currentPtr->data << " entered into front node" << std::endl;
		currentPtr->nextPtr = headPtr;		//set the new node's nextPtr to whatever node headPtr was pointing at
		headPtr = currentPtr;				//set headPtr to the currentPtr
		return true;	
	}
	else
		return false;
}


bool LinkedList::insertBeforePosition(int index, std::string inputData)
{

	if (headPtr == nullptr)			//if the headPtr is nullptr, the list is empty so add a new node
	{
		headPtr = new Node;
		headPtr->data = inputData;		
		headPtr->nextPtr = nullptr;
		std::cout << headPtr->data << " entered into front node because list was empty" << std::endl;
		return true;
	}
	else if (headPtr != nullptr)
	{
		Node* previousPtr = new Node;		//create a new node to keep track of the previous node while traversing
		Node* currentPtr = new Node;		//create a new node named currentPtr
		Node* newPtr = new Node;			//create a new node named newPtr
		newPtr->data = inputData;
		currentPtr = headPtr;		//set currentPtr to point at headPtr
		int count = 1;
		while (currentPtr->nextPtr != nullptr && count != index)		//while currentPtr is not the last node and the counter is not index
		{
			previousPtr = currentPtr;			//point previousPtr to point at currentPtr
			currentPtr = currentPtr->nextPtr;	//step currentPtr to the next node
			count++;
		}
		if (currentPtr->nextPtr == nullptr && index == count + 1)	//if currentPtr is the last node and index is the length of the list
		{
			Node * tempPtr;			//create a new node pointed to by tempPtr
			tempPtr = new Node;
			tempPtr = headPtr;		//tempPtr is now headPtr
			while (tempPtr->nextPtr != nullptr)		//traverse the list until tempPtr is now pointing at the last node
				tempPtr = tempPtr->nextPtr;
			std::cout << newPtr->data << " entered into last node" << std::endl;
			newPtr->nextPtr = nullptr;		//set newPtr next to nullptr, effectively making it the last node
			tempPtr->nextPtr = newPtr;		//make tempPtr's nextPtr point at the new node tempPtr, making tempPtr the next-to-last node
			return true;
		}
		else if (index == 1)
		{
			//see function insertAtFront()
			std::cout << newPtr->data << " entered into front node" << std::endl;
			newPtr->nextPtr = headPtr;
			headPtr = newPtr;
			return true;
		}
		else if (index > count + 1)		//if the node they want to enter is beyond the number of nodes in the list
		{
			std::cout << "Cannot add at position " << index << " because list does not contain that many nodes" << std::endl;
			return false;
		}
		else
		{
			previousPtr->nextPtr = newPtr;		//the previousPtr nextPtr is now newPtr, adding the node newPtr into the list after previousPtr
			newPtr->nextPtr = currentPtr;		//newPtr-nextPtr set to currentPtr, so the back portion of the list is now connected to the front portion
			std::cout << "Node containing " << newPtr->data << " inserted into position " << index << std::endl;
			return true;
		}

	}
	else
		return false;
}



bool LinkedList::insertAtBack(std::string inputData)
{
	if (headPtr == nullptr)			//if the headPtr is nullptr, the list is empty so add a new node
	{
		headPtr = new Node;		//creates a new node that headPtr now points at
		headPtr->data = inputData;		//populate with data
		headPtr->nextPtr = nullptr;		//set headPtr node's nextPtr to nullptr to make it the last node 
		std::cout << headPtr->data << " entered into last node" << std::endl;
		return true;
	}
	else if (headPtr != nullptr)
	{
		Node * tempPtr;				
		tempPtr = new Node;			//create a new node named tempPtr
		tempPtr = headPtr;			//point tempPtr at the start of the list
		while (tempPtr->nextPtr != nullptr)		//while tempPtr is not the last node
			tempPtr = tempPtr->nextPtr;		//step through the list until it is the last node
		Node * currentPtr;		
		currentPtr = new Node;		//create a new node currentPtr
		currentPtr->data = inputData;		//populate with data
		std::cout << currentPtr->data << " entered into last node" << std::endl;
		currentPtr->nextPtr = nullptr;		//make currentPtr's nextPtr be nullptr, making it the last node
		tempPtr->nextPtr = currentPtr;		//connect tempPtr's nextPtr to point at currentPtr, making tempPtr the second to last node
		return true;
	}
	else
		return false;
}





bool LinkedList::deleteAtFront()
{
	Node* currentPtr;
	if (headPtr == nullptr)		//if the list is empty
	{
		std::cout << "The linked list contains no nodes to delete" << std::endl;
		return false;
	}
	else if (headPtr != nullptr)		//if the list is not empty
	{
		currentPtr = headPtr;				//set currentPtr to headPtr
		headPtr = headPtr->nextPtr;			//headPtr is now pointing at the node after headPtr, cutting out the first node
		delete currentPtr;					//delete the node that was cut out
		std::cout << "First node removed" << std::endl;
		return true;
	}
	else
		return false;
}



bool LinkedList::deleteBeforePosition(int index)
{
	int count = 1;
	if (headPtr == nullptr)			//if the headPtr is nullptr, the list is empty so cannot delete any nodes
	{
		std::cout << "Linked list does not have any nodes to delete" << std::endl;
		return false;
	}
	else if (index <= 0)
	{
		std::cout << "Index is out of bounds" << std::endl;		
		return false;
	}
	else
	{
		Node* currentPtr, *previousPtr;		//create two pointers: current and previous
		previousPtr = nullptr;			//previous pointer is nullpointer
		for (currentPtr = headPtr; currentPtr != nullptr; previousPtr = currentPtr, currentPtr = currentPtr->nextPtr)	//currentPtr points to headPtr, if currentPtr is not nullptr, previousPtr points to currentPtr and currentPtr points to the next node
		{
			if (count == index)
			{
				if (previousPtr == nullptr)		//if previousPtr is nullptr, i.e. if currentPtr is at the first node...
				{
					headPtr = currentPtr->nextPtr;		//headPtr points to currentPtr's nextPtr, i.e. currentPtr has now been skipped
					std::cout << "Node " << index << " removed" << std::endl;
					delete currentPtr;		//delete the node that has been cut out
					return true;
				}
				else
				{
					previousPtr->nextPtr = currentPtr->nextPtr;		//previousPtr's nextPtr now points to currentPtr's nextPtr, i.e. currentPtr node has now been skipped
					std::cout << "Node " << index << " removed" << std::endl;
					delete currentPtr;		//delete the node that has been cut out
					return true;
				}
			}
			count++;
			
		}
		if (index > count)
		{
			std::cout << "Cannot delete; list does not contain that many nodes" << std::endl;
			return false;
		}

	}

}

bool LinkedList::deleteAtBack()
{
	if (headPtr == nullptr)			//if the headPtr is nullptr, the list is empty so cannot delete any nodes
	{
		std::cout << "Linked list does not have any nodes to delete" << std::endl;
		return false;
	}
	else if (headPtr->nextPtr == nullptr)			//if headPtr is the last node
	{
		delete headPtr;								//delete it, since it's the last node
		std::cout << "Last node removed" << std::endl;
		headPtr = nullptr;							//set headPtr to nullPtr
		return true;
	}
	else
	{
		Node * nextToLastPtr;			//create a new node that points at node headPtr is pointing at
		nextToLastPtr = new Node;
		nextToLastPtr = headPtr;
		Node * lastPtr;
		lastPtr = new Node;				//create a new node that points to node after headPtr
		lastPtr = headPtr->nextPtr;
		while (lastPtr->nextPtr != nullptr)		//while lastPtr is not the lastPtr
		{
			nextToLastPtr = lastPtr;		//traverse to the end of the list, keeping track of the next to last node
			lastPtr = lastPtr->nextPtr;		//traverse the list
		}
		delete lastPtr;				//delete the last node
		nextToLastPtr->nextPtr = nullptr;		//set nextToLastPtr to the last node 
		std::cout << "Last node removed" << std::endl;
		return true;
	}
}


void LinkedList::printData()
{
	Node *tempPtr = headPtr;		//make a new pointer pointing at headPtr

	if (tempPtr == nullptr)
	{
		std::cout << "List is empty, no data to print" << std::endl;
	}
	else
	{
		std::cout << "Displaying contents of list at address " << this << std::endl;
		while (tempPtr != nullptr)		//while tempPtr is not the last node
		{
			std::cout << tempPtr->data << " ";		//print the data in the list
			tempPtr = tempPtr->nextPtr;			//traverse the list
		}
		std::cout << std::endl;
	}


}


void LinkedList::printData(Node* head)		//same as above, except passed a pointer to the head of a list you wish to print
{
	Node *tempPtr = head;

	if (tempPtr == nullptr)
	{
		std::cout << "List is empty, no data to print" << std::endl;
	}
	else
	{
		std::cout << "Displaying contents of list at address " << this << std::endl;
		while (tempPtr != nullptr)
		{
			std::cout << tempPtr->data << " ";
			tempPtr = tempPtr->nextPtr;
		}
		std::cout << std::endl;
	}
}

void LinkedList::operator +(LinkedList & right)
{
	LinkedList tempList;					//create a new list tempList
	Node *currentAPtr, *currentBPtr;		//make new pointers to point at calling headPtr and right headPtr
	currentAPtr = headPtr;					//point temp pointer at left headPtr
	currentBPtr = right.headPtr;			//point another temp pointer at right headPtr

	while (currentAPtr != nullptr)			//while currentAPtr is not the nullptr, to traverse to the end of the left list
	{
		tempList.insertAtBack(currentAPtr->data);		//create a new node and add it to the back of tempList containing the data in currentAPtr
		currentAPtr = currentAPtr->nextPtr;				//step through the list
	}
	while (currentBPtr != nullptr)			//while currentBPtr is not nullptr, traverse to end of right list
	{
		tempList.insertAtBack(currentBPtr->data);		//create a new node and add it to the back of tempList containing the data in currentBPtr
		currentBPtr = currentBPtr->nextPtr;				//step through right list
	}
	std::cout << "Displaying concactenated lists" << std::endl;
	tempList.printData();
}


void LinkedList::operator -(LinkedList & right)
{
	LinkedList tempList;			//create a new tempList
	Node *tempHeadPtr, *tempCurrentPtr, *tempTempPtr, *currentPtr;		//create temp pointers for left head, left current, left head holder, and current pointer

	tempCurrentPtr = nullptr;		//initialize pointer
	tempHeadPtr = nullptr;			//initialize pointer
	tempTempPtr = nullptr;			//initialize pointer
	currentPtr = headPtr;			//initialize pointer

	//copy the left hand side list to tempList
	while (currentPtr != nullptr)						//traverse the left list
	{
		tempCurrentPtr = new Node;						//for each node in left list, create a new node as a copy
		if (tempTempPtr == nullptr)						//if this is the first node...
		{
			tempHeadPtr = tempCurrentPtr;				//set copy list's head pointer to point at the first node in the copy list
		}
		if (tempTempPtr != nullptr)						//if this is not the first node in the left list
		{
			tempTempPtr->nextPtr = tempCurrentPtr;		//else set the placeholder pointer (tempTempPtr)'s next pointer to point at the new node created in the last iteration
		}
		tempTempPtr = tempCurrentPtr;					//set placeholder pointer to the new node
		tempCurrentPtr->data = currentPtr->data;		//copy the new node's data as the data from the original left list data
		currentPtr = currentPtr->nextPtr;				//traverse to the next node in the left list
	}
	printData(tempHeadPtr);					//print the data starting from the copy list's headpointer

	tempList.headPtr = tempHeadPtr;			//make the new list's headpointer point at the first node in the copy list
	tempCurrentPtr = tempHeadPtr;			//reset the traversing pointer to point at the first node in the copy list
	Node* rightCurrentPtr;					//create a new pointer to traverse the right list
	rightCurrentPtr = right.headPtr;		//set the pointer that is traversing the right list to point at the node that the right list's head pointer is pointing at

	while (rightCurrentPtr != nullptr)			//while the right list's traversing pointer is not a nullptr, i.e. is not the last node in the list
	{
		tempCurrentPtr = tempHeadPtr;			//reset the pointer traversing the copy list back to the head of the copy list
		int count = 1;
		while (tempCurrentPtr != nullptr)		//while the copy list's traversing pointer is not a nullptr
		{
			if (rightCurrentPtr->data == tempCurrentPtr->data)			//if the data in the nodes are the same
			{
				tempList.deleteBeforePosition(count);			//delete the copy list's node at this position
				tempHeadPtr=tempList.headPtr;					//reset the copy list's head pointer to the first node of the copy list
				tempCurrentPtr = tempHeadPtr;					//set the copy list traversing pointer to point at the first node of the copy list
				rightCurrentPtr = right.headPtr;				//set the right list traversing pointer to point at the first node of the right list (to catch duplicate data)
				break;
			}
			tempCurrentPtr = tempCurrentPtr->nextPtr;		//step through the copy list
			count++;										//keep track of the position in the copy list that needs to be deleted
		}
		rightCurrentPtr = rightCurrentPtr->nextPtr;			//step through the right list
	}
	std::cout << "Displaying difference between the two lists" << std::endl;
	tempList.printData();
}