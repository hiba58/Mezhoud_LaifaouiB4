#include "bidirectionalLinkedLists.h"

bnode* insertend(bnode* head,int id,int severity,char* time,char* desc){
  bnode* newnode=(bnode*)malloc(sizeof(bnode)) ;
    newnode->id=id ;
   newnode->severity=severity ;
  strcpy(newnode->timestemp,time) ;
  strcpy(newnode->describtion,desc) ;
    newnode->next=NULL ;
    newnode->prev=NULL ;
 if(head==NULL) 
    return newnode ;
      bnode* temp=head ;
        while(temp->next!=NULL) temp=temp->next ;
   temp->next=newnode ;
   newnode->prev=temp ;
return head ;
}
bnode* insertbegin(bnode* head,int id,int severity,char* time,char* desc){
    bnode* newnode=(bnode*)malloc(sizeof(bnode)) ;
  newnode->id=id ;
  newnode->severity=severity ;
    strcpy(newnode->timestemp,time) ;
    strcpy(newnode->describtion,desc) ;
 newnode->next=head ;
 newnode->prev=NULL ;
    if(head!=NULL)
  head->prev=newnode ;
return newnode ;
}
bnode* deletebyiD(bnode* head,int id){
if(head==NULL) 
  return NULL ;
bnode* temp=head ;
    while(temp!=NULL && temp->id!=id)
   temp=temp->next ;
  if(temp==NULL) 
    return head ;
if(temp->prev!=NULL)
temp->prev->next=temp->next ;
   else
  head=temp->next ;
if(temp->next!=NULL)
temp->next->prev=temp->prev ;
free(temp) ;
return head ;
}
void forward(bnode* head){
bnode* temp=head ;
   while(temp!=NULL){
   printf("ID:%d Time:%s Severity:%d Desc:%s\n",temp->id,temp->timestemp,temp->severity,temp->describtion) ;
   temp=temp->next ;
     }
  }
void backward(bnode* tail){
    bnode* temp=tail ;
  while(temp!=NULL){
  printf("ID:%d Time:%s Severity:%d Desc:%s\n",temp->id,temp->timestemp,temp->severity,temp->describtion) ;
    temp=temp->prev ;
    }
   }
bnode* mergelists(bnode* head1,bnode* head2){
if(head1==NULL) 
   return head2 ;
  if(head2==NULL) 
     return head1 ;
  bnode* temp=head1 ;
     while(temp->next!=NULL)
     temp=temp->next ;
     temp->next=head2 ;
    head2->prev=temp ;
return head1 ;
}
