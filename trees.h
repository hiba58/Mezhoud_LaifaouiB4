#ifndef TREES_H
#define TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedLists.h"
#include "stacks.h"
 typedef struct treenode {
    int id;
    char timestamp[20];
    char message[100];
    int severity;
    struct treenode* left;
    struct treenode* right;
}treenode; 
treenode* insertlog(treenode *root,int id,char *timestamp,char *message,int severity);
treenode* searchlog(treenode *root,int id);
treenode* findmin(treenode* node);
treenode* deletelog(treenode* root,int id);
void inorder(treenode* root);
void preorder(treenode* root);
void postorder(treenode* root);
bool isBST(treenode *root, int min , int max);
treenode *find_bst(treenode *root, int value); 
 // part 2 
 typedef struct TTree {
    char word[50];
    char synonym[50];
    char antonym[50];
    int charCount;     
    int vowelCount;   
    struct TTree *left, *right;
} TTree;
TTree *createNode(char *word, char *syn, char *ant);
Stacknode* pop(TStack *stk);
TTree *insertTree(TTree *root, TTree *newNode);
TTree *toTree(TStack *stk);
TTree *getInfWordTree(TTree *tr, char *word);
void  pushS(TStack *stk, const char *word, const char *syn, const char *ant);
TTree *findMin(TTree *root);
TTree *deleteWordBST(TTree *tr,char *word);
TTree *TraversalBSTinOrder(TTree *tr);
TTree *TraversalBSTpostOrder(TTree *tr);
TTree *LowestCommonAncestor(TTree *tr, char *word1, char *word2);
TTree *inOrderSuccessor(TTree *tr, char *word);
TTree *AddWordBST(TTree *root, char *word, char *syne, char *anton);
TTree *fillTree(FILE *f);
TTree *UpdateWordBST(TTree *tr, char *word, char *syne, char *anton);
void preOrder(TTree *tr);
int height(TTree *tr);
int size(TTree *tr);
void HighSizeBST(TTree *tr);
int CountNodesRanges(TTree *root, int l, int h);
bool isMirror(TTree *t1, TTree *t2);
bool isSymmetric(TTree *root);
#endif // TREES_H
