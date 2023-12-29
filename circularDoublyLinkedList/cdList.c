#include "cdList.h"

struct dNode* init(int data)
{
	struct dNode* newNode = malloc(sizeof(struct dNode));
	newNode->data = data;
	newNode->next = newNode;
	newNode->prev = newNode;
	return newNode;
}

int addFront(struct dNode** list, int data)
{
	if (*list == NULL) // initialize empty list.
	{
		*list = init(data);
		return 0;
	}

	struct dNode* head = *list;
	struct dNode* before = head->prev;
	struct dNode* newNode = malloc(sizeof(struct dNode));
	newNode->data = data;
	before->next = newNode;
	newNode->prev = before;
	newNode->next = head;
	head->prev = newNode;
	*list = newNode; // assign new head.
	return 0;
}

int addBack(struct dNode** list, int data)
{
	if (*list == NULL) // initialize empty list.
	{
		*list = init(data);
		return 0;
	}

	struct dNode* head = *list;
	struct dNode* before = head->prev;
	struct dNode* newNode = malloc(sizeof(struct dNode));
	newNode->data = data;
	before->next = newNode;
	newNode->prev = before;
	newNode->next = head;
	head->prev = newNode;
	return 0;
}

int deleteFront(struct dNode** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct dNode* head = *list;
	struct dNode* before = head->prev;
	struct dNode* after = head->next;
	free(head);
	before->next = after;
	after->prev = before;
	*list = after; // assign new head.
	return 0;
}

int deleteBack(struct dNode** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct dNode* head = *list;
	struct dNode* tail = head->prev;
	struct dNode* before = tail->prev;
	free(tail);
	before->next = head;
	head->prev = before;
	return 0;
}

int clear(struct dNode** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct dNode* head = *list;
	do {
		struct dNode* dummy = *list;
		*list = dummy->next;
		free(dummy);
	} while (*list != head);
	*list = NULL;
	return 0;
}

int isEmpty(struct dNode* list)
{
	if (list == NULL) return 1; // list is empty.
	else return 0;
}

int size(struct dNode* list, int* nodeCount)
{
	if (list == NULL) return 1; // list is empty.

	*nodeCount = 0;
	struct dNode* head = list;
	do {
		++*nodeCount;
		list = list->next;
	} while (list != head);
	return 0;
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