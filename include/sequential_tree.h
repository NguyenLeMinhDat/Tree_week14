#pragma once

#define MAX_LABEL_LEN 10
#define MAXLENGTH 100
#define NIL -1
#define EMPTY_NODE "EMPTY"

enum TraversalOrderMode {
    preOrder = -1,  // truoc
    inOrder,    // giua
    postOrder   // sau
};

typedef char DataType[MAX_LABEL_LEN];

typedef struct {
    DataType index[MAXLENGTH];
    int MaxNode;
} Tree;

void initTree(Tree* tree);
int emptyTree(Tree tree);
void initRoot(Tree* tree, const char* label);
void updateMaxNode(Tree* tree, int idx);
void createChildLabel(const char* fatherLabel, int childType, char* childLabel);
int isNodeExist(Tree tree, int idx);
void insertLeft(Tree* tree, int fatherIdx);
void insertRight(Tree* tree, int fatherIdx);
void trav(Tree tree, int mode, int idx);
void sequentialTree();