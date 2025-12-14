#pragma once

#include "util.h"

#define MAXLENGTH 100
#define NIL -1

typedef char DataType[MAX_LABEL_LEN];

typedef struct {
    DataType index[MAXLENGTH];
    int MaxNode;
} STree;

void initTreeS(STree* tree);
int isTreeEmptyS(STree tree);
void initRoot(STree* tree, const char* label);
void updateMaxNode(STree* tree, int idx);
void createChildLabelS(const char* fatherLabel, int childType, char* childLabel);
int isNodeExist(STree tree, int idx);
void insertLeft(STree* tree, int fatherIdx);
void insertRight(STree* tree, int fatherIdx);
void trav(STree tree, int mode, int idx);
void sequentialTree();