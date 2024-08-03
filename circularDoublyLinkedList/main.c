#include "cdList.h"
#include "random.h"

void populateList(struct dNode** list, int isRandom)
{
	if (isRandom == 1)
	{
		int min = 0;
		int max = 100;
		seedRand();
		for (int i = 0; i < 11; i++)
		{
			addBack(list, getRandNum(min, max));
		}
	}
	else
	{
		for (int i = 0; i < 11; i++)
		{
			addBack(list, pow(i, 5));
		}
	}

	int nodeCount = 0;
	size(*list, &nodeCount);
	printf("Node count: %d\n", nodeCount);
	print(*list);
}
void evaluateList(struct dNode* list)
{
	int nodeCount = 0;
	int result = size(list, &nodeCount);
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

int main()
{
	printf("Circular Doubly Linked List v0.0.7\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	int min = 0;
	int max = 100;
	struct dNode* list = NULL;
	struct dNode* ptr = NULL;
	
	populateList(&list, 0);
	/// test code here: ////////////////////////////////////////
	printf("Result: %d\n\n", result);
	////////////////////////////////////////////////////////////
	evaluateList(list);
}