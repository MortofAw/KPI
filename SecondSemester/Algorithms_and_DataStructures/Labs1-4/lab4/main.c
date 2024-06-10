#include <stdio.h>
#include <stdlib.h>

typedef struct doublyLinkedList
{
	float info;
	struct doublyLinkedList *next;
	struct doublyLinkedList *previous;
} LinkedList;

void ListCreation(int SIZE, LinkedList **Beg2L, LinkedList **End2L)
{
	printf("\n-- Doubly Linked List Create with 2*n elements  --\n");

	*Beg2L = NULL;
	*End2L = NULL;
	LinkedList *P;
	
	P = (LinkedList*)malloc(sizeof(LinkedList));
	
	P->next = NULL;
	P->info = 1;
	P->previous = NULL;
	
	*Beg2L = P;
	*End2L = P;

	for(int i = 2; i <= SIZE; i++)
	{
		P = (LinkedList*)malloc(sizeof(LinkedList));
		P->next = NULL;
		P->info = i;
		P->previous = *End2L;

		(*End2L)->next = P;
		*End2L = P;
	}
}

void printList(LinkedList *Beg2L)
{
	if(!Beg2L) return;
	
	LinkedList *current = Beg2L;
	while(current)
	{
		double info = current->info;
		LinkedList *next = current->next;
		LinkedList *previous = current->previous;

		printf("info = %lf pointer = %p previous = %p next = %p\n", info, current, previous, next);

		current = next;
	}
}

void listModification(LinkedList *Beg2L)
{
	float tempInfo;
	int SIZE = 0;

	//count of elements
	LinkedList *current = Beg2L;
	while(current != NULL)
	{
		current = current->next;
		SIZE++;
	}

	printf("count of el = %d", SIZE);

	//look for a mid of list + 1
	LinkedList *mid = Beg2L;
	for(int i = 0; i < SIZE/2; i++)
	{
		mid = mid->next;
	}

	int i, j;
	current = Beg2L;
    for (i = 0; i < SIZE / 2; i++) {
        tempInfo = mid->info;

		LinkedList *moving = mid; 
        for (int j = i + SIZE / 2; j > i * 2 + 1; j--) {
            moving->info = moving->previous->info;
			moving = moving->previous;
        }

    	current->next->info = tempInfo;
		current = current->next->next;

		mid = mid->next;
    }
}

void ListRemoving(LinkedList *Beg2L)
{
    while (Beg2L != NULL) {
    	LinkedList *temp = Beg2L;
        Beg2L = Beg2L->next;
        free(temp);
    }
}

int main(void){
	int n;

	do{
		printf("\nEnter n > 0 -->");
		scanf("%d", &n);	
	}
	while(n <= 0);

	LinkedList *End2L;
	LinkedList *Beg2L;
	ListCreation(2*n, &Beg2L, &End2L);
	printf("\nYour Doubly Linked List before modification\n");

	printList(Beg2L);
	
	listModification(Beg2L);

	printf("\nYour Doubly Linked List after modification\n");
	printList(Beg2L);
	ListRemoving(Beg2L);

	return 0;
}
