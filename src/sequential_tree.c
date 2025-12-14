#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sequential_tree.h"

void initTreeS(STree* tree) {
    tree->MaxNode = 0;

    for (int i = 0; i < MAXLENGTH; i++)
        strcpy(tree->index[i], EMPTY_NODE);
} 

int isTreeEmptyS(STree tree) {
    return strcmp(tree.index[0], EMPTY_NODE) == 0;
}

void initRoot(STree* tree, const char* label) {
    strcpy(tree->index[0], label);
    tree->MaxNode = 1;

    printf("Create root with label '%s'.\n", label);
}

void updateMaxNode(STree* tree, int idx) {
    if (idx >= tree->MaxNode) {
        tree->MaxNode = idx + 1;
    }
}

void createChildLabelS(const char* fatherLabel, int childType, char* childLabel) {
    strcpy(childLabel, fatherLabel);

    strcat(childLabel, ".");
    if (childType == 1)
        strcat(childLabel, "1");
    else
        strcat(childLabel, "2");
}

int isNodeExist(STree tree, int idx) {
    if (idx >= 0 && idx <= MAXLENGTH)
        return strcmp(tree.index[idx], EMPTY_NODE) != 0;
    
    return 0;
}

void insertLeft(STree* tree, int fatherIdx) {
    int childIdx = 2 * fatherIdx + 1;
    char childLabel[MAX_LABEL_LEN];

    if (!isNodeExist(*tree, fatherIdx)) {
        printf("Error: Father node in index %d doesn't exist!\n", fatherIdx);
        return;
    }

    if (childIdx >= MAXLENGTH) {
        printf("Error: Surpass tree limit!\n");
        return;
    }

    createChildLabelS(tree->index[fatherIdx], 1, childLabel);

    strcpy(tree->index[childIdx], childLabel);
    updateMaxNode(tree, childIdx);
    printf("Inserted left child with label '%s'\n", childLabel);
}

void insertRight(STree* tree, int fatherIdx) {
    int childIdx = 2 * fatherIdx + 2;
    char childLabel[MAX_LABEL_LEN];

    if (!isNodeExist(*tree, fatherIdx)) {
        printf("Error: Father node in index %d doesn't exist!\n", fatherIdx);
        return;
    }

    if (childIdx >= MAXLENGTH) {
        printf("Error: Surpass tree limit!\n");
        return;
    }

    createChildLabelS(tree->index[fatherIdx], 2, childLabel);

    strcpy(tree->index[childIdx], childLabel);
    updateMaxNode(tree, childIdx);
    printf("Inserted right child with label '%s'\n", childLabel);
}

void trav(STree tree, int mode, int idx) {
    if (idx < MAXLENGTH && isNodeExist(tree, idx)) {
        if (mode < 0) printf("%s ", tree.index[idx]);
        trav(tree, mode, 2 * idx + 1);
        if (mode == 0) printf("%s ", tree.index[idx]);
        trav(tree, mode, 2 * idx + 2);
        if (mode > 0) printf("%s ", tree.index[idx]);
    }
}

void sequentialTree() {
    printf("\n--------- Sequential Binary Tree ----------\n");
    STree tree;
    initTreeS(&tree);
    printf("Tree is %sEmpty.\n", isTreeEmptyS(tree) ? "" : "Not ");

    initRoot(&tree, "A");

    insertLeft(&tree, 0);   // "A.1"
    insertRight(&tree, 0);  // "A.2"
    insertLeft(&tree, 1);   // "A.1.1"
    insertRight(&tree, 1);  // "A.1.2"
    insertLeft(&tree, 2);   // "A.2.1"
    insertRight(&tree, 2);  // "A.2.2"

    printf("Tree is %sEmpty.\n", isTreeEmptyS(tree) ? "" : "Not ");
    printf("Duyet theo phuong thuc truoc: \n");
    trav(tree, preOrder, 0);
    printf("\nDuyet theo phuong thuc giua: \n");
    trav(tree, inOrder, 0);
    printf("\nDuyet theo phuong thuc sau: \n");
    trav(tree, postOrder, 0);
    printf("\n");
}