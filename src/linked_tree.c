#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked_tree.h"

Node* newNode(const char* label) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    strncpy(newNode->label, label, MAX_LABEL_LEN - 1);
    newNode->label[MAX_LABEL_LEN - 1] = '\0';
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initTreeL(LTree* tree) {
    tree->root = NULL;
}

int isTreeEmptyL(LTree tree) {
    return tree.root == NULL;
}

void createChildLabelL(const char* fatherLabel, int childType, char* childeLabel) {
    strcpy(childeLabel, fatherLabel);
    strcat(childeLabel, ".");
    if (childType == 1) 
        strcat(childeLabel, "1");
    else
        strcat(childeLabel, "2");
}

void insertLeftL(Node* father) {
    if (father == NULL) {
        printf("Error: Node father doens't exist!\n");
        return;
    }
    if (father->left != NULL) {
        printf("Error: Left node already exist!\n");
        return;
    }

    char childLabel[MAX_LABEL_LEN];
    createChildLabelL(father->label, 1, childLabel);
    father->left = newNode(childLabel);
    father->left->left = NULL;
    father->left->right = NULL;
    printf("Inserted left child with label '%s'\n", childLabel);
}

void insertRightL(Node* father) {
    if (father == NULL) {
        printf("Error: Node father doens't exist!\n");
        return;
    }
    if (father->right != NULL) {
        printf("Error: Left node already exist!\n");
        return;
    }

    char childLabel[MAX_LABEL_LEN];
    createChildLabelL(father->label, 2, childLabel);
    father->right = newNode(childLabel);
    father->right->left = NULL;
    father->right->right = NULL;
    printf("Inserted right child with label '%s'\n", childLabel);
}

void travL(Node* root, int mode) {
    if (root == NULL) return;

    if (mode < 0) printf("%s ", root->label);
    travL(root->left, mode);
    if (mode == 0) printf("%s ", root->label);
    travL(root->right, mode);
    if (mode > 0) printf("%s ", root->label);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void linkedTree() {
    printf("\n--------- Linked Binary Tree ----------\n");
    LTree tree;
    initTreeL(&tree);
    printf("Tree is %sEmpty.\n", isTreeEmptyL(tree) ? "" : "Not ");

    if (isTreeEmptyL(tree)) {
        tree.root = newNode("A");
        printf("Create root with label '%s'.\n", tree.root->label);
    }

    Node* root = tree.root;
    Node *nodeL1, *nodeR1;

    insertLeftL(root);   // A.1
    insertRightL(root);  // A.2
    nodeL1 = root->left;
    nodeR1 = root->right;

    insertLeftL(nodeL1);     // A.1.1
    insertRightL(nodeL1);    // A.1.2
    insertLeftL(nodeR1);     // A.2.1
    insertRightL(nodeR1);    // A.2.2

    printf("Tree is %sEmpty.\n", isTreeEmptyL(tree) ? "" : "Not ");
    printf("Duyet theo phuong thuc truoc: \n");
    travL(tree.root, preOrder);
    printf("\nDuyet theo phuong thuc giua: \n");
    travL(tree.root, inOrder);
    printf("\nDuyet theo phuong thuc sau: \n");
    travL(tree.root, postOrder);
    printf("\n");
}