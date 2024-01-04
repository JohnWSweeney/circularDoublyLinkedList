#include "cdList.h"

int main()
{
	printf("Circular Doubly Linked List v0.0.4\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	struct dNode* list = NULL;
	struct dNode* ptr = NULL;

	for (int i = 0; i < 2; i++)
	{
		addBack(&list, pow(i, 5));
	}
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
		print(list);
	}
	else if (result == 1)
	{
		printf("List is empty.\n\n");
	}
	/// test code here: ////////////////////////////////////////
	position = 1;
	result = movePosUp(&list, position);
	printf("Result: %d\n\n", result);
	////////////////////////////////////////////////////////////
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
		print(list);
	}
	else if (result == 1)
	{
		printf("List is empty.\n\n");
	}
}