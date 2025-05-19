#include "circularLinkedLists.h"

void printCLL(node *head){
 	node *current ;
 	if(head==NULL){
 		printf("there is no entry \n");
	 }
	 current= head;
	do{
	  printf("the id is : %d \n", current->id ); 
 		printf("severity is : %d \n", current->severity); 
 		printf("the timestemp is :%s\n", (current->timestemp)); 
 		printf("the describtion is :%s\n", (current->describtion));  
 		printf("\n");
current=current->next;	
	} while(current!=head);
 }
 node *creat_node_CLL(int id , int severity , char timestemp[] ,char describtion[] ){
 	node *newnode =(node *)malloc(sizeof(node));  
 	newnode->id=id ;
 	newnode->severity=severity; 
 	strcpy(newnode->describtion,describtion); 
 	strcpy(newnode->timestemp, timestemp);  
 	newnode->next=NULL;  
 	return newnode ;
 }
 node *insert_at_beg_CLL(node *head , node *newnode ){
    	if(head==NULL){
    		newnode->next=newnode;
    		return newnode;
		}
		node *current=head;
		while(current->next!=head){
			current=current->next;
		}
		current->next=newnode;
		newnode->next=head;
		head=newnode;
		return head;
	
 } 
 node *insert_at_position_CLL (node *head,node *newnode ,int position){ 
 if(head==NULL){
 	if(position==1){
 		newnode->next=newnode;
 		return newnode;
	 }
	 return NULL;
 }
 if (position==1){
 	return insert_at_beg_CLL(head, newnode);
 }
 node *current= head;
 int counter=1;
 while(counter<position-1 && current->next!=head){
 	current=current->next;
 	counter ++;
 }
 newnode->next=current->next;
 current->next=newnode;
 return head;
 
 } 
  node *insert_at_end_CLL (node *head,node *newnode ){
  	if(head==NULL){
  		newnode->next=newnode;
  		return newnode;
	  }
	  node *current= head;
	  while( current->next!=head){
	  	current = current->next;
	  }
	  current->next=newnode;
	  newnode->next=head; 
	  return head;
  }
 node *delete_first_CLL(node *head){
  	if(head== NULL){
  		return NULL;
	  }
	   node *current= head;
	 if(current->next==head){
	 	free(current);
	 	return NULL;
	 } 
	
	 while(current->next!=head){
	 	current=current->next;
	 }
	 node *temp= head;
	 head=head->next;
	 current->next= head;
	 free(temp);
	 return head;
  }
  node *delete_last_CLL(node *head){
  	if(head==NULL){
  		return NULL;
	  }
	if(head->next==head){
		node *temp=head;
		head=NULL;
		free(temp);
		return NULL;
	}  
	node *current=head;
	node *prev;
	while(current->next!=head){
		prev=current;
		current=current->next;
	}
	prev->next=head;
	free(current);
	return head;
	
  }
  node *delete_by_id_CLL(node *head , int id){
    node *current= head;  
  	 if (head==NULL){
  	 	return NULL;
	   }
     if (head->id == id){
        if (head->next == head){
        free(head);
        return NULL;
    }
    head=delete_first_CLL(head);
  return head;
}
		while(current->next!=head&&current->next->id!=id){
 			current=current->next; 
		 }  
		  if (current->next==head){
		 printf("the value does not exist\n"); 
		 return head ;
		 } 
		 node *temp =current->next; 
	 	current->next=temp->next; 
	 	free(temp); 
	 	return head ; 
  }
  node *delete_by_timestemp_CLL(node *head , char timestemp[]){ 
  		node *current=head ;   
 		    if (head == NULL){
			 return NULL;
	    	}
 		  if (strcmp(head->timestemp,timestemp)==0) {
 		  	head=delete_first_CLL(head);
        return head;
    } 
 	while(current->next!=head&&strcmp(current->next->timestemp, timestemp) != 0){
 			current=current->next; 
		 }   if (current->next==head){
		 printf("the value does not exist\n"); 
		 return head ;
		 } 
	 node *temp =current->next; 
	 	current->next=temp->next; 
	 	free(temp);  
	 	return head ; 
 }  
 node *search_by_id_CLL(node *head , int id ){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
	 do{
	 	if(current->id==id){
	 		return current;
		 }
		 current=current->next;
	 }while(current!=head);
	 return NULL;
 } 
  node *search_by_timestemp_CLL(node *head , char timestemp[]){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
	do{
	 	 if(strcmp(current->timestemp,timestemp)==0)
	 	 return current; 
	 	 else{
		   current=current->next;  
		    }
		}while(current!=head);
		return NULL;
	 } 
  node *search_by_keyword_CLL(node *head , char keyword[]){
 	node *current=head ; 
 	if(head==NULL){
 		return NULL; 
	 } 
	do{
		if(strstr(current->describtion,keyword)!=0){
	 	 return current; 
	 }
	 	 else{
		   current=current->next; 
		    }
	}while(current!=head);	
	  return NULL;
 }  
 node *sort_by_date_CLL(node *head) {
    if (head == NULL || head->next == head){
        return head ;
    }
    int swapped;
    node *current;
    node *last = NULL;
    do{
        swapped = 0;
        current = head;
        do{
            node *nextNode = current->next;
            if (nextNode == head) break;
            if (strcmp(current->timestemp, nextNode->timestemp) > 0) {
                int temp_id = current->id;
                int temp_severity = current->severity;
                char temp_timestemp[50];
                char temp_describtion[100];

                strcpy(temp_timestemp, current->timestemp);
                strcpy(temp_describtion, current->describtion);

                current->id = nextNode->id;
                current->severity = nextNode->severity;
                strcpy(current->timestemp, nextNode->timestemp);
                strcpy(current->describtion, nextNode->describtion);

                nextNode->id = temp_id;
                nextNode->severity = temp_severity;
                strcpy(nextNode->timestemp, temp_timestemp);
                strcpy(nextNode->describtion, temp_describtion);

                swapped = 1;
            }
            current = current->next;
        } while (current->next != head);
    } while (swapped);
    return head;
}
 node *sort_by_severity_CLL(node *head){
    if (head ==NULL){
        return NULL;
}
    int swapped;
    node *current;
    do{
        swapped = 0;
        current = head;
        do{
            if(current->severity > current->next->severity) {
                char temp_timestemp[50], temp_describtion[100];
                int temp_id = current->id;
                int temp_severity = current->severity;
                strcpy(temp_timestemp, current->timestemp);
                strcpy(temp_describtion, current->describtion);
                current->id = current->next->id;
                current->severity = current->next->severity;
                strcpy(current->timestemp, current->next->timestemp);
                strcpy(current->describtion, current->next->describtion);

                current->next->id = temp_id;
                current->next->severity = temp_severity;
                strcpy(current->next->timestemp, temp_timestemp);
                strcpy(current->next->describtion, temp_describtion);

                swapped = 1;
            }
            current = current->next;
        } while (current->next != head); 
    } while (swapped);

    return head;
}
node *reverse_CLL(node *head){
	if (head==NULL || head->next== NULL){
		return head;
	}
	 node *prev = NULL;
    node *current = head;
    node *next = NULL;
    node *last = head;
    while (last->next != head){
        last = last->next;
    }
    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head = prev;
    return head;
}
int count_CLL(node *head){
	node *current=head ; 
	int counter=0; 
	if(head==NULL){
		return 0;
	}
do{
	current=current->next;
	counter++;
}while(current!=head);
	return counter ;
} 
 
