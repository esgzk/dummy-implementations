#ifndef QUEUE_H

#define QUEUE_H
#define NULL 0 // ((void*)0)



struct node
{
	node *after;
	int data;
};



//first to out and last to out elements in the queue
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
		*head = (*head)->after;
		delete n;
	}
}
void inner_push(node **head, node **tail, int value)
{
	if (*head == NULL)
	{
		node *n = new node;
		n->data = value;
		n->after = NULL;
		*head = *tail = n;
	}
	else
	{
		node *n = new node;
		n->data = value;
		(*tail)->after = n;
		*tail = n;
		(*tail)->after = NULL;
	}
}
int inner_begin(node **head)
{
	return (*head == NULL) ? 0 : (*head)->data;
}
int inner_end(node **tail)
{
	return (*tail == NULL) ? 0 : (*tail)->data;
}



//interface
int begin()
{
	return inner_begin(&head);
}
int end()
{
	return inner_end(&tail);
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
