#pragma once

#include "util.h"

typedef struct Node {
    char label[MAX_LABEL_LEN];
    struct Node* left;
    struct Node* right;
} Node;

typedef struct LTree {
    Node* root;
} LTree;

Node* newNode(const char* label);
void initTreeL(LTree* tree);
int isTreeEmptyL(LTree tree);
void createChildLabelL(const char* fatherLabel, int childType, char* childeLabel);
void insertLeftL(Node* father);
void insertRightL(Node* father);
void travL(Node* root, int mode);
void deleteTree(Node* root);
void linkedTree();