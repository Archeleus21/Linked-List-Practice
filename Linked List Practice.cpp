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
		std::cout << "1. Create Linked List" << std::endl;
		std::cout << "2. Display Linked List" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "Enter Your Choice: ";
		scanf_s("%d", &choice);

		//takes input from user and execute the following
		switch (choice)
		{
			case 1:
				printf("Enter Data for first Node: ");
				scanf_s("%d", &data);  //takes data from user
				CreateNode(data);  //puts data in info portion of node
				break;
			case 2:
				Display();  //display list contents
				break;
			case 3:
				exit(1);  //exits
			default:
				printf(" \nInvalid Entry!");  //non-valid option was input
		}
	}

	return 0;
}

//creates node in list
void CreateNode(int data)
{
	system("cls");  //equivalent to clrscr(); "clear screen function"

	struct Node *temp;  //creates temp node to start list

	temp = (struct Node *) malloc(sizeof(struct Node));  //allocating memory space

	//if we are creating the first node then do this
	if (head == NULL)
	{
		temp->info = data; //copy data part in info part of the temp
		temp->link = NULL; //makes link NULL since it is the last one as well as the first
		head = temp;  //copy the address of temp to the head 
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
		printf("The list is empty!");
		return;
	}

	//if not empty prints this followed by contents of list
	printf("Linked List ");

	//runs until ptr is NULL which means its the end of the list
	while (ptr != NULL)
	{
		printf("%d->", ptr->info);  //prints info in current node
		ptr = ptr->link;  //moves to next node
	}

	//once out of while loop, print "end of list"
	printf("End of List!\n");
	//system("cls");  //clrscr();
}