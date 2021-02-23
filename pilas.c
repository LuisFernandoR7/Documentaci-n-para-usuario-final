#include <stdio.h>
#include <stdlib.h>

struct complejo
{
	int real;
	int img;
};

struct node
{
	struct node *siguiente;
	struct complejo *dato;
};


int isEmpty(struct node *head) 
{
	if(head == NULL)
		return 1;
	return 0;
}

void init(struct node *head)
{
	head = NULL;
}


struct node *push(struct node *head, struct complejo *dato) 
{
	struct node* nuevo = (sizeof node*) malloc(sizeof *  node);
	if(nuevo == NULL)
	{
		exit(0);
	}

	nuevo->dato = dato;
	nuevo->siguiente = head;
	head = nuevo;
	return head;

}

struct node *pop(struct node *head) 
{
	struct node* tmp = head;
	head = head->siguiente;
	free(tmp);
	return head;
}

struct node *newStack() {
	struct node *tos;
	tos = NULL;
	return tos;
}

int main(int argc, char* argv[]) 
{

	struct node *tos = newStack();
	struct complejo *cPtr, c1;
	cPtr = &c1;

	for(int i = 1; i < argc; i=i+2) {
		cPtr->real = atoi(argv[i]);
		cPtr->img = atoi(argv[i+1]);
		tos = push(tos, cPtr);		
	}


	while (!isEmpty(tos)) 
	{
		printf("Dato %d + %di\n", tos->dato->real, tos->dato->img);
		tos = pop(tos);
	}

	return 0;
}

