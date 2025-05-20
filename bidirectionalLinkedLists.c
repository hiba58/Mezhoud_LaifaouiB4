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

int main() {
    bnode* head = NULL;
    bnode* secondList = NULL;
    bnode* tail = NULL;
    int choice, id, severity;
    char time[20], desc[100];
    
    while (1) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        
printf("\n========== BIDIRECTIONAL LINKED LIST MANAGER ==========\n");
        printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
        printf("3. Delete by ID\n");
    printf("4. Display Forward\n");
        printf("5. Display Backward\n");
    printf("6. Create Second List\n");
printf("7. Merge Lists\n");
        printf("8. Exit\n");
printf("======================================================\n");
    printf("Enter your choice: ");
        scanf("%d", &choice);
    getchar();
        
        switch (choice) {
            case 1:
                printf("\n--- Insert at Beginning ---\n");
    printf("Enter ID: ");
                scanf("%d", &id);
    printf("Enter Severity (1-5): ");
                scanf("%d", &severity);
                getchar();
printf("Enter Timestamp (format: YYYY-MM-DD): ");
    fgets(time, sizeof(time), stdin);
    time[strcspn(time, "\n")] = 0;
                printf("Enter Description: ");
    fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc, "\n")] = 0;
                
                head = insertbegin(head, id, severity, time, desc);
    printf("\nNode inserted at beginning successfully!\n");
                
                if (tail == NULL) {
        tail = head;
    } else {
                    bnode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
                    }
        tail = temp;
    }
                break;
                
        case 2:
                printf("\n--- Insert at End ---\n");
    printf("Enter ID: ");
scanf("%d", &id);
    printf("Enter Severity (1-5): ");
                scanf("%d", &severity);
    getchar();
                printf("Enter Timestamp (format: YYYY-MM-DD): ");
    fgets(time, sizeof(time), stdin);
                time[strcspn(time, "\n")] = 0;
    printf("Enter Description: ");
                fgets(desc, sizeof(desc), stdin);
desc[strcspn(desc, "\n")] = 0;
                
head = insertend(head, id, severity, time, desc);
                printf("\nNode inserted at end successfully!\n");
                
                bnode* temp = head;
                while (temp->next != NULL) {
    temp = temp->next;
                }
                tail = temp;
break;
                
            case 3:
                if (head == NULL) {
    printf("\nList is empty. Nothing to delete.\n");
                } else {
                    printf("\n--- Delete by ID ---\n");
        printf("Enter ID to delete: ");
        scanf("%d", &id);
                    
                    head = deletebyiD(head, id);
        printf("\nNode with ID %d deleted successfully (if found)!\n", id);
                    
                    if (head == NULL) {
            tail = NULL;
        } else {
                        temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
                        tail = temp;
        }
                }
                break;
                
            case 4:
                if (head == NULL) {
                    printf("\nList is empty. Nothing to display.\n");
    } else {
                    printf("\n--- Display Forward ---\n");
        forward(head);
    }
                break;
                
case 5:
                if (tail == NULL) {
    printf("\nList is empty. Nothing to display.\n");
                } else {
                    printf("\n--- Display Backward ---\n");
        backward(tail);
    }
                break;
                
            case 6:
                printf("\n--- Create Second List ---\n");
    printf("How many nodes to add to the second list? ");
                int count;
    scanf("%d", &count);
                int i ;
                for ( i = 0; i < count; i++) {
                    getchar();
        printf("\nEnter details for node %d:\n", i+1);
        printf("Enter ID: ");
                    scanf("%d", &id);
                    printf("Enter Severity (1-5): ");
        scanf("%d", &severity);
                    getchar();
                    printf("Enter Timestamp (format: YYYY-MM-DD): ");
        fgets(time, sizeof(time), stdin);
        time[strcspn(time, "\n")] = 0;
                    printf("Enter Description: ");
                    fgets(desc, sizeof(desc), stdin);
        desc[strcspn(desc, "\n")] = 0;
                    
                    secondList = insertend(secondList, id, severity, time, desc);
    }
                printf("\nSecond list created successfully!\n");
                break;
                
            case 7:
                if (secondList == NULL) {
                    printf("\nSecond list is empty. Create a second list first.\n");
                } else {
printf("\n--- Merge Lists ---\n");
                    head = mergelists(head, secondList);
                    secondList = NULL;
                    
                    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
                    tail = temp;
                    
                    printf("\nLists merged successfully!\n");
                }
                break;
                
            case 8:
                printf("\nExiting program. Goodbye!\n");
                
                while (head != NULL) {
    bnode* temp = head;
       head = head->next;
    free(temp);
                }   
                return 0;
            default:
printf("\nInvalid choice. Please try again.\n");
        }
        
    printf("\nPress Enter to continue...");
getchar();
    }
    
return 0;
}
