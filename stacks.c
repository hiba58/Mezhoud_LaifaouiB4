#include "stacks.h"
 void print(node *head){ 
 if(head==NULL){
 	printf("there is no entry"); 
 }
 	node *current=head ;
 	while(current!=NULL){
 		printf("the id is : %d \n", current->id ); 
 		printf("severity is : %d \n", current->severity); 
 		printf("the timestemp is :%s\n", (current->timestemp)); 
 		printf("the describtion is :%s\n", (current->describtion));  
 		printf("\n");
current=current->next;
	 }
 }
 node *creat_node(int id , int severity , char timestemp[] ,char describtion[] ) {
 	node *newnode =(node *)malloc(sizeof(node));  
 	newnode->id=id ;
 	newnode->severity=severity; 
 	strcpy(newnode->describtion,describtion); 
 	strcpy(newnode->timestemp, timestemp);  
 	newnode->next=NULL;  
 	return newnode ;
 }
 node *insert_at_beg(node *head , node *newnode ) {
 	newnode->next=head; 
 	head=newnode; 
 	return head;
 } 
 node *insert_at_position (node *head,node *newnode ,int position) { // it includes insert at the end 
 	node *current=head ; 
	  	int counter=1;  
	  	for (current=head ; current!=NULL ; current=current->next){
	  		if (counter==position-1){ 
	  		newnode->next=current->next; 
	  		current->next=newnode;	
			  } 
			  counter++;
		  } return head ;
 } 
 node *delet_by_id(node *head , int id){
 		node *current=head ;   
 		    if (head == NULL) return NULL;
 		  if (head->id == id) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    } 
 	while(current->next!=NULL&&current->next->id!=id){
 			current=current->next; 
		 }   if (current->next==NULL){
		 
		 printf("the value does not exist\n"); 
		 return head ;
		 }

	 node *temp =current->next; 
	 	current->next=temp->next; 
	 	free(temp); 
	 	return head ; 
 } 
 node *delet_by_timestemp(node *head , char timestemp[]){ 
  		node *current=head ;   
 		    if (head == NULL) return NULL;
 		  if (strcmp(head->timestemp,timestemp)==0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    } 
 	while(current->next!=NULL&&strcmp(current->next->timestemp, timestemp) != 0){
 			current=current->next; 
		 }   if (current->next==NULL){
		
		 printf("the value does not exist\n"); 
		 return head ;
		 } 

	 node *temp =current->next; 
	 	current->next=temp->next; 
	 	free(temp);  
	 	return head ; 
 }  
 node *search_by_id (node *head , int id ){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
	 while (current!=NULL){
	 	 if(current->id==id)
	 	 return current; 
		   current=current->next;   
	}	   	   
	   return NULL;
 } 
 node *search_by_timestemp(node *head , char timestemp[]){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
	 while (current!=NULL){
	 	 if(strcmp(current->timestemp,timestemp)==0)
	 	 return current; 

		   current=current->next;   }
		   return NULL; 
		   

 } 
 node *search_by_keyword(node *head , char keyword[]){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
		 while (current!=NULL){
	 	 if(strstr(current->describtion,keyword)!=0)
	 	 return current; 
	 	
		   current=current->next;  }
		   return NULL; 
		    
	   
 }  
 node *sort_by_severity(node *head){ 
 int swapped ; 
 	node *current; 
 	if(head==NULL){
 		return NULL; 
	 }  
	 do {
	 
	 swapped=0; 
	 current=head ;
	 while(current!=NULL&&current->next!=NULL){
	 	if(current->severity>current->next->severity){
	 	 char temp_timestemp[10], temp_describtion[100] ;
	 int 	temp_id=current->next->id; 
	 int	temp_severity=current->next->severity; 
	 	strcpy(temp_timestemp, current->next->timestemp); 
	 	strcpy(temp_describtion, current->next->describtion); 
		 
		 current->next->severity=current->severity; 
		 current->next->id=current->id; 
		 strcpy(current->next->timestemp,current->timestemp); 
		 strcpy(current->next->describtion,current->describtion); 
		  
		 current->id=temp_id; 
		 current->severity=temp_severity; 
		 strcpy(current->timestemp, temp_timestemp); 
		 strcpy(current->describtion,temp_describtion);    
	 	swapped=1;
		 } 
		  current=current->next; 
	 }  
}	 while(swapped);
	 return head ;
 } 
node *reverse(node *head){
 node *current=head ; 
 node *prev=NULL;
 node *next=NULL;
 while(current!=NULL){
 	next=current->next; 
 	current->next=prev;  
 	prev=current; 
 	current=next ; 
 } 
 head=prev;  
 return head ;	
} 
int count(node *head){
	node *current=head ; 
	int counter=0; 
	while(current!=NULL){
		current=current->next; 
		counter++; 
	} 
	return counter ;
} 
