#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    int severity;
    char timestemp[50];
    char describtion[100];
    struct node *next;
} node;  
node *creat_node(int id , int severity , char timestemp[] ,char describtion[]);
void print(node *head);
node *insert_at_beg(node *head , node *newnode);
node *insert_at_position(node *head,node *newnode ,int position);
node *delet_by_id(node *head , int id);
node *delet_by_timestemp(node *head , char timestemp[]);
node *search_by_id(node *head , int id);
node *search_by_timestemp(node *head , char timestemp[]);
node *search_by_keyword(node *head , char keyword[]);
node *sort_by_severity(node *head);
node *reverse(node *head);
int count(node *head);
// part 2 
typedef struct TList {
    char word[20];
    char related[20];
    int countchar;
    int countvow;
    struct TList *next;
} TList;

typedef struct BList {
    char word[20];
    char synonym[20];
    char antonym[20];
    int countchar;
    int countvow;
    struct BList *prev;
    struct BList *next;
} BList;

typedef struct TQueue {
    TList *front;
    TList *rear;
} TQueue;
TList *addWord(TList *syn, TList *ant, char *word, char *syne, char *anton);
TList *addlist(TList *list, char *word, char *related);
TQueue *syllable(TList *syn);
int isPalindrome(char *str);
TQueue *toQueue(BList *merged) ;
TList *similarWord(TList *syn, char *word, int rate);
int callculate_rate(char *a ,char *b);
TList *deleteWord(FILE *f, TList *syn, TList *ant, char *word) ;
TList *sortWord2(TList *syn);
void getInfWord2(TList *syn, TList *ant, char *inf);
TList *getAntoWords(FILE *f);
BList *merge(TList *syn, TList *ant);
TList *countWord(TList *syn, char *prt);
TList *updateWord(FILE *f , TList *syn, TList *ant, char *word, char *syne, char *anton);
TList *sortWord3(TList *syn);
TList *sortWord(TList *syn);
void getInfWord(TList *syn, TList *ant, char *word);
TList *getSynWords(FILE *f);
void swap(TList *i, TList *j);
int countvowel(char *word);
void enqueue(TQueue *queue, TList *node);
#endif // LINKEDLISTS_H
