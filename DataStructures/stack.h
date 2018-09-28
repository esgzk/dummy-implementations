#ifndef STACK_H

#define STACK_H
#define NULL 0 // ((void*)0)



struct node
{
	node *prev;
	int data;
};



//first and last elements on the stack
node* head;
node* tail;



//internal funcs
void inner_pop(node **head, node **tail)
{
	if (*head == NULL)
		return;
	else if (*head == *tail)
	{
		delete *head;
		*head = NULL;
		*tail = NULL;
	}
	else 
	{
		node* n = new node;
		n = *head;
		*head = (*head)->prev;
		delete n;
	}
}
void inner_push(node **head, node **tail, int value)
{
	if (*head == NULL)
	{
		node *n = new node;
		n->data = value;
		n->prev = NULL;
		*head = *tail = n;
	}
	else 
	{
		node *n = new node;
		n->data = value;
		n->prev = *head;
		*head = n;
	}
}
int inner_top(node **head)
{
	return (*head == NULL) ? 0 : (*head)->data;
}



//interface
int top()
{
	return inner_top(&head);
}
void pop()
{
	inner_pop(&head, &tail);
}
void push(int val)
{
	inner_push(&head, &tail, val);
}
#endif


