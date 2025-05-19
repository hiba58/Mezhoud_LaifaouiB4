#ifndef QUEUES_H
#define QUEUES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 typedef struct node{
 	int id; 
 	int severity ; 
 	char timestemp[50];   
 	char describtion[100]; // to describe what happened 
 	struct node *next; 
 }node;   

 typedef struct queue { 
 	struct node *front;
 	struct node *rear;
 }queue; 
queue * creatqueue();
void enqueue(queue *q ,node *newnode);
node *dequeue(queue *q);
node *peek_queue(queue *q);
bool is_empty_queue(queue* Q);

#endif // QUEUES_H
