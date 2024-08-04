#include "cdList.h"
#include "random.h"

void populateList(struct dNode** list, int nodeCount, int isRandom)
{
	if (isRandom == 1)
	{
		int min = 0;
		int max = 100;
		seedRand();
		for (int i = 0; i < nodeCount; i++)
		{
			addBack(list, getRandNum(min, max));
		}
	}
	else
	{
		for (int i = 0; i < nodeCount; i++)
		{
			addBack(list, pow(i, 5));
		}
	}

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
	printf("Circular Doubly Linked List v0.0.8\n\n");
	int result = 0;
	int data = 0;
	int position = 0;
	struct dNode* list = NULL;
	struct dNode* ptr = NULL;
	
	populateList(&list, 10, 0);
	/// test code here: ////////////////////////////////////////

	////////////////////////////////////////////////////////////
	evaluateList(list);
}