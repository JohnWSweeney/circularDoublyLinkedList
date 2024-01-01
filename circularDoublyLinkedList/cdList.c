#include "cdList.h"
// sweeney's hand-rolled circular doubly linked list.
//
// pos = "position".
// ptr = "pointer".
//
// error codes:
// 0	no error.
// 1	list is NULL.
// 2	ptr is NULL.
// 5	list has only one node.
// -1	pos/ptr not in list.
// -2	no action needed.

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
	if (head->next == head) // check if list has only one node.
	{
		free(head);
		*list = NULL;
		return 0;
	}

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
	if (head->next == head) // check if list has only one node.
	{
		free(head);
		*list = NULL;
		return 0;
	}

	struct dNode* tail = head->prev;
	struct dNode* before = tail->prev;
	free(tail);
	before->next = head;
	head->prev = before;
	return 0;
}

int deletePos(struct dNode** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	struct dNode* head = *list;
	int tempPos = 0;
	do {
		struct dNode* curr = *list;
		if (tempPos == pos)
		{
			struct dNode* before = curr->prev;
			struct dNode* after = curr->next;
			before->next = after;
			after->prev = before;
			if (curr == head)
			{
				head = head->next;
			}
			free(curr);
			*list = head;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != head);
	*list = head; // position not in list, reset list.
	return -1;
}

int deletePtr(struct dNode** list, struct dNode* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct dNode* head = *list;
	do {
		struct dNode* curr = *list;
		if (curr == ptr)
		{
			struct dNode* before = curr->prev;
			struct dNode* after = curr->next;
			before->next = after;
			after->prev = before;
			if (ptr == head)
			{
				head = head->next;
			}
			free(ptr);
			ptr = NULL;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	*list = head; // pointer not in list, reset list.
	return -1;
}

int returnPosPtr(struct dNode* list, int pos, struct dNode** ptr)
{
	if (list == NULL) return 1; // list is empty.

	struct dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			*ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int returnFrontData(struct dNode* list, int* data)
{
	if (list == NULL) return 1; // list is empty.
	*data = list->data;
	return 0;
}

int returnBackData(struct dNode* list, int* data)
{
	if (list == NULL) return 1; // list is empty.
	*data = list->prev->data;
	return 0;
}

int returnPosData(struct dNode* list, int pos, int* data)
{
	if (list == NULL) return 1; // list is empty.

	struct dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			*data = list->data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1; // position not in list.
}

int returnPtrData(struct dNode* list, struct dNode* ptr, int* data)
{
	if (list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // pointer is null.

	struct dNode* head = list;
	do {
		if (list == ptr)
		{
			*data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return -1; // pointer not in list.
}

int updatePosData(struct dNode* list, int pos, int data)
{
	if (list == NULL) return 1; // list is empty.

	struct dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int returnDataPos(struct dNode* list, int data, int* pos)
{
	if (list == NULL) return 1; // list is empty.
	
	struct dNode* head = list;
	*pos = 0;
	do {
		if (list->data == data)
		{
			return 0;
		}
		++*pos;
		list = list->next;
	} while (list != head);
	return -1; // position not in list.
}

int movePosFront(struct dNode** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	if (pos == 0) return -2; // no action needed.

	struct dNode* head = *list;
	*list = head->next; // skep 
	int tempPos = 1;
	do {
		struct dNode* curr = *list;
		if (tempPos == pos)
		{
			struct dNode* before = curr->prev;
			struct dNode* after = curr->next;
			before->next = after;
			after->prev = before;
			struct dNode* tail = head->prev;
			tail->next = curr;
			curr->prev = tail;
			curr->next = head;
			head->prev = curr;
			*list = curr;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != head);
	*list = head; // position not in list, reset list.
	return -1;
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