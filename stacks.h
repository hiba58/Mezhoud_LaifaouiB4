#ifndef STACKS_H
#define STACKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedLists.h"
 typedef struct stack{
 	struct node *top ;
 }stack;  
 void print(node *head); 
 node *creat_node(int id , int severity , char timestemp[] ,char describtion[] ) ;
 node *insert_at_beg(node *head , node *newnode ) ;
 node *insert_at_position (node *head,node *newnode ,int position);
 node *delet_by_id(node *head , int id);
 node *delet_by_timestemp(node *head , char timestemp[]);
  node *search_by_id (node *head , int id );
  node *search_by_timestemp(node *head , char timestemp[]);
  node *search_by_keyword(node *head , char keyword[]);
  node *sort_by_severity(node *head);
  node *reverse(node *head); 
  int count(node *head);
 // part 2 
 typedef struct Stacknode {
	char word[20];
	char synonym[20];
	char antonym[20];
	int charcount;
	int countvow;
	struct Stacknode *next;
}Stacknode;
typedef struct TStack{
	Stacknode *top;
}TStack;

typedef struct threeTstack{
  struct  TStack *shortWords;
   struct TStack *longWords;
   struct TStack *diphthongs;
} threeTstack; 

 Stacknode *pop(TStack *stk) ;
 void printStack(TStack *stk); 
 int countVowels(const char *str); 
 TStack *sortWordStack(TStack *stk); 
 TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton); 
 BList *StacktoList(TStack *stk);
 char *getSmallest(TStack *stk);
 bool isPalindromeStack(char *word);
 TStack *createStack();
 TStack *getInfWordStack(TStack *stk, char *word);
 TStack *deleteWordStack(TStack *stk, char *word) ;
 TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton);
 void enqueue(TQueue *queue, TList *node) ;
 TQueue *stackToQueue(TStack *stk);
 
 #endif // STACKS_H
