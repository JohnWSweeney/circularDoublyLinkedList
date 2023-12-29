#include "circularDoublyLinkedList.h"

struct dNode* init(int data)
{
	struct dNode* newNode = malloc(sizeof(struct dNode));
	newNode->data = data;
	newNode->next = newNode;
	newNode->prev = newNode;
	return newNode;
}

int addBack(struct dNode** list, int data)
{
	if (*list == NULL) // initialize empty list.
	{
		*list = init(data);
		return 0;
	}

	struct dNode* head = *list;
	do {
		struct dNode* curr = *list;
		if (curr->next == head)
		{
			struct dNode* newNode = malloc(sizeof(struct dNode));
			newNode->data = data;
			curr->next = newNode;
			newNode->prev = curr;
			newNode->next = head;
			head->prev = newNode;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
}

int print(struct dNode* list)
{
	if (list == NULL) return 1; // list is empty.

	struct dNode* head = list;
	int tempPos = 0;
	printf("#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n");
	do {
		printf("%d\t%d\t%p\t%p\t%p\n", tempPos, list->data, list, list->next, list->prev);
		++tempPos;
		list = list->next;
	} while (list != head);
	printf("\n");
	return 0;
}