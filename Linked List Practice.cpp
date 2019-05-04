// Linked List Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <malloc.h>

//creating a linked list
struct Node
{
	//stored info
	int info;
	//pointer to next node in list
	struct Node *link;
}*head; //pointer to front of list

//forward declaration of functions
void CreateNode(int); //creates nodes
void Display();  //displays contents
void InsertAtBeginning(int);
void InsertAtPosition(int, int);
void InsertAtEnd(int); //inserts node at end of list

int main()
{
	//info
	int choice;
	int data;
	int choice1;
	int pos;

	head = NULL;

	while (1)
	{
		//system("cls");
		std::cout << "\n1. Create Linked List" << std::endl;
		std::cout << "2. Display Linked List" << std::endl;
		std::cout << "3. Insert Node in Linked List" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Enter Your Choice: ";
		scanf_s("%d", &choice);

		//takes input from user and execute the following
		switch (choice)
		{
			case 1:
				printf("Enter how many nodes: ");
				scanf_s("%d", &data);  //takes data from user
				CreateNode(data);  //puts data in info portion of node
				break;
			case 2:
				Display();  //display list contents
				break;
			case 3:
				system("cls");  //clears screen
				std::cout << "1. Insert Node at beginning" << std::endl;
				std::cout << "2. Insert Node at specific location" << std::endl;
				std::cout << "3. Insert Node at end of list" << std::endl;
				std::cout << "4. Previous Menu" << std::endl;
				std::cout << "Enter Your Choice: ";
				scanf_s("%d", &choice1);
				
				switch (choice1)
				{
					case 1:
						printf("Enter data for Node: ");
						scanf_s("%d", &data);
						InsertAtBeginning(data);
						break;
					case 2:
						printf("Enter data for Node: ");
						scanf_s("%d", &data);
						printf("Enter position for Node: ");
						scanf_s("%d", &pos);
						InsertAtPosition(data, pos);
						break;
					case 3:
						printf("Enter data for Node: ");
						scanf_s("%d", &data);
						InsertAtEnd(data);
						break;
					case 4:
						break;
				}
				break;
			case 4:
				exit(1);  //exits
			default:
				printf(" \nInvalid Entry!");  //non-valid option was input
		}
	}

	return 0;
}

//creates node in list
void CreateNode(int no)
{	
	int data;  //data given by user

	system("cls");  //equivalent to clrscr(); "clear screen function"

	struct Node *temp;  //creates temp node to start list

	//malloc() function allocats memory space the size of the node and 
	//returns a pointer to the first byte of allocated memory if allocation succeeds
	temp = (struct Node *) malloc(sizeof(struct Node)); 

	//adds multiple nodes
	for (int i = 0; i < no; i++)
	{
		//if we are creating the first node then do this
		if (head == NULL)
		{
			printf("Enter data for node %d: ", i);  //asks for data from user
			scanf_s("%d", &data); //gets data from user
			temp->info = data; //copy data part in info part of the temp
			temp->link = NULL; //makes link NULL since it is the last one as well as the first
			head = temp;  //copy the address of temp to the head 
		}
		//otherwise add to end of list
		else
		{
			printf("Enter data for node %d: ", i);  //asks for data
			scanf_s("%d", &data);  //gets data
			InsertAtEnd(data);  //inserts data at end of list
		}
	}

	std::cout << "List Created!" << std::endl;  //prints message confirming creation
}

//lets display what is in our Nodes
void Display()
{
	struct Node *ptr;  //points to the nodes
	ptr = head;  //makes ptr point at the head of the list

	//checks if list is empty
	if (head == NULL)
	{
		printf("\nThe list is empty!\n");
		return;
	}

	//if not empty prints this followed by contents of list
	printf("\nLinked List \n");

	//runs until ptr is NULL which means its the end of the list
	while (ptr != NULL)
	{
		printf("\n%d->", ptr->info);  //prints info in current node
		ptr = ptr->link;  //moves to next node
	}

	//once out of while loop, print "end of list"
	printf("End of List!\n\n");
	//system("cls");  //clrscr();
}

void InsertAtEnd(int data)
{
	struct Node *ptr;
	struct Node *tempNode;

	ptr = head;

	//travers to the end of the list
	while (1)
	{
		if (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		else
		{
			break;
		}
	}

	//malloc() function allocats memory space the size of the node and 
	//returns a pointer to the first byte of allocated memory if allocation succeeds
	tempNode = (struct Node *)malloc(sizeof(struct Node));
	tempNode->info = data;  //puts data into info spot in node
	tempNode->link = NULL;  //points link to NULL meaning end of list
	ptr->link = tempNode;  //inserts tempNode into end of List
}

//insert node at beginning of list
void InsertAtBeginning(int data)
{
	struct Node *tempNode;  //temp storage of node
	tempNode = (struct Node *)malloc(sizeof(struct Node));  //allocate memory for node
	tempNode->info = data;  //store data
	tempNode->link = head;  //store link
	head = tempNode;  //insert node as head
}

void InsertAtPosition(int data, int pos)
{
	struct Node *ptr;
	struct Node *tempNode;

	ptr = head;

	//travers list
	for (int i = 0; i < pos; i++)
	{
		//ensure valid position
		if (ptr == NULL)
		{
			printf("Invalid Position Entered!");
			return;
		}

		ptr = ptr->link;  //points to next node
	}

	//last node?
	if (ptr->link == NULL)
	{
		InsertAtEnd(data);
	}
	else
	{
		tempNode = (struct Node *)malloc(sizeof(struct Node));  //allocate memory
		tempNode->info = data;  //store data
		tempNode->link = ptr->link;  //store link to next node after insertion
		ptr->link = tempNode;  //link previous node to temp node
	}
}