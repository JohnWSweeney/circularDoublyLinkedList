#include "cdList.h"
#include "random.h"

int main()
{
	printf("Circular Doubly Linked List v0.0.6\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	int min = 0;
	int max = 100;
	struct dNode* list = NULL;
	struct dNode* ptr = NULL;

	for (int i = 0; i < 9; i++)
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