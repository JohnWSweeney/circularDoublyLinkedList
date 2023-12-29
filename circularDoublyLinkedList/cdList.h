#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

struct dNode* init(int data);
int addFront(struct dNode** list, int data);
int addBack(struct dNode** list, int data);
int deleteFront(struct dNode** list);
int deleteBack(struct dNode** list);
int clear(struct dNode** list);
int isEmpty(struct dNode* list);
int size(struct dNode* list, int* nodeCount);
int print(struct dNode* list);