#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
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

struct dNode* init(int data);
int addFront(struct dNode** list, int data);
int addBack(struct dNode** list, int data);
int addPos(struct dNode** list, int pos, int data);
int deleteFront(struct dNode** list);
int deleteBack(struct dNode** list);
int deletePos(struct dNode** list, int pos);
int deletePtr(struct dNode** list, struct dNode* ptr);
int returnPosPtr(struct dNode* list, int pos, struct dNode** ptr);
int returnFrontData(struct dNode* list, int* data);
int returnBackData(struct dNode* list, int* data);
int returnPosData(struct dNode* list, int pos, int* data);
int returnPtrData(struct dNode* list, struct dNode* ptr, int* data);
int updatePosData(struct dNode* list, int pos, int data);
int returnDataPos(struct dNode* list, int data, int* pos);
int movePosFront(struct dNode** list, int pos);
int movePosUp(struct dNode** list, int pos);
int clear(struct dNode** list);
int isEmpty(struct dNode* list);
int size(struct dNode* list, int* nodeCount);
int print(struct dNode* list);