/*
 * merge_list.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: abhishek
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};



/* Function to insert a node at the beginging of the
linked list */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
    printf("\n");
}

struct node* SortedMerge(struct node *first, struct node *second)
{
    struct node *result;
    if(!first)
        return second;

    if(!second)
        return first;

    if(first->data < second->data)
    {
        result = first;
        result->next = SortedMerge(first->next, second);
	}

    if(second->data < first->data)
    {
        result = second;
        result->next = SortedMerge(first, second->next);
    }

    return result;
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node *res = NULL;
	struct node* a = NULL;
	struct node* b = NULL;

	/* Let us create two sorted linked lists to test
	the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	printList(a);
	printList(b);
	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}
