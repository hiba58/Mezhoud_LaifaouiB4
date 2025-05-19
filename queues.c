#include "queues.h"

 queue *creatqueue(){
 	queue *newqueue ; 
 	newqueue=(queue *)malloc(sizeof(queue));  
 	newqueue->front=NULL;
 	newqueue->rear=NULL; 
 	return newqueue ; 
 } 
void enqueue(queue *q ,node *newnode){
	if(q->front==NULL){
		q->front=newnode; 
		q->rear=newnode; 
	} 
	else {
	q->rear->next=newnode;  
	q->rear=newnode; 
	}
} 
node *dequeue(queue *q){
	if(q->front==NULL){
	
	printf("it's empty");  
	return NULL; }
	else 
	{
node *temp=q->front;  
		q->front=q->front->next; 
		free(temp); 
	} return q->front;
} 
node *peek_queue(queue *q){
	if(q->front==NULL){
		return NULL ;
	}  
	 	else {
			node *temp=q->front;   

 return temp ;}
} 
bool is_empty_queue(queue* Q){ 

if (Q->front==NULL){
return true; 
}	 
else return false ; 
 }   
  
