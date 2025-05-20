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
 
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader() {
    printf("\n=====================================================\n");
    printf("            LOG ENTRY MANAGEMENT SYSTEM              ");
    printf("\n=====================================================\n");
}
void printFooter() {
    printf("\n=====================================================\n");
    printf("Press Enter to continue...");
    getchar();
}
int main() {
    node* head = NULL;
    int choice, id, severity, position;
    char timestemp[50], describtion[100], keyword[50];
    
    while (1) {
   clearScreen();
   printHeader();
    printf("\nMAIN MENU:\n");
    printf("1. Add Log Entry (at beginning)\n");
	printf("2. Add Log Entry (at specific position)\n");
    printf("3. Add Log Entry (at end)\n");
    printf("4. Delete First Log Entry\n");
    printf("5. Delete Last Log Entry\n");
    printf("6. Delete Log Entry by ID\n");
    printf("7. Delete Log Entry by Timestamp\n");
    printf("8. Search Log Entry by ID\n");
    printf("9. Search Log Entry by Timestamp\n");
    printf("10. Search Log Entry by Keyword\n");
    printf("11. Sort Log Entries by Date\n");
    printf("12. Sort Log Entries by Severity\n");
    printf("13. Reverse Log Entries\n");
    printf("14. Count Log Entries\n");
    printf("15. Display All Log Entries\n");
    printf("16. Exit\n");
printf("\nEnter your choice: ");
 scanf("%d", &choice);
getchar(); 
   switch (choice) {
     case 1:
     clearScreen();
     printf("=== ADD NEW LOG ENTRY (AT BEGINNING) ===\n\n");      
      printf("Enter Log ID: ");
   scanf("%d", &id);     
  printf("Enter Severity (1-5, where 5 is most severe): ");
  scanf("%d", &severity);
   getchar(); 
   printf("Enter Timestamp (YYYY-MM-DD HH:MM:SS): ");
  fgets(timestemp, sizeof(timestemp), stdin);
   timestemp[strcspn(timestemp, "\n")] = 0;
   printf("Enter Description: ");
 fgets(describtion, sizeof(describtion), stdin);
describtion[strcspn(describtion, "\n")] = 0;
  node* newNode = creat_node_CLL(id, severity, timestemp, describtion);
  head = insert_at_beg_CLL(head, newNode);
  printf("\nLog entry added successfully at the beginning!");
 printFooter();
  break; 
 case 2:
  clearScreen();
  printf("=== ADD NEW LOG ENTRY (AT SPECIFIC POSITION) ===\n\n"); 
  printf("Enter position to insert: ");
  scanf("%d", &position);
  printf("Enter Log ID: ");
 scanf("%d", &id); 
   printf("Enter Severity (1-5, where 5 is most severe): ");
   scanf("%d", &severity);
  getchar(); 
  printf("Enter Timestamp (YYYY-MM-DD HH:MM:SS): ");
  fgets(timestemp, sizeof(timestemp), stdin);
   timestemp[strcspn(timestemp, "\n")] = 0;
  printf("Enter Description: ");
  fgets(describtion, sizeof(describtion), stdin);
  describtion[strcspn(describtion, "\n")] = 0; 
   newNode = creat_node_CLL(id, severity, timestemp, describtion);
   head = insert_at_position_CLL(head, newNode, position);
    printf("\nLog entry added successfully at position %d!", position);
    printFooter();
   break;
  case 3:
  clearScreen();
   printf("=== ADD NEW LOG ENTRY (AT END) ===\n\n");   
 printf("Enter Log ID: ");
 scanf("%d", &id);     
      printf("Enter Severity (1-5, where 5 is most severe): ");
  scanf("%d", &severity);
   getchar();
 printf("Enter Timestamp (YYYY-MM-DD HH:MM:SS): ");
  fgets(timestemp, sizeof(timestemp), stdin);
  timestemp[strcspn(timestemp, "\n")] = 0;
  printf("Enter Description: ");
 fgets(describtion, sizeof(describtion), stdin);
 describtion[strcspn(describtion, "\n")] = 0;
   newNode = creat_node_CLL(id, severity, timestemp, describtion);
  head = insert_at_end_CLL(head, newNode);
  printf("\nLog entry added successfully at the end!");
 printFooter();
 break;       
  case 4:
  clearScreen();
  printf("=== DELETE FIRST LOG ENTRY ===\n\n");
                
 if (head == NULL) {
  printf("No log entries to delete!");
   } 
	else {
   head = delete_first_CLL(head);
   printf("First log entry deleted successfully!");
    }
   printFooter();
   break;
    case 5:
   clearScreen();
  printf("=== DELETE LAST LOG ENTRY ===\n\n");  
  if (head == NULL) {
    printf("No log entries to delete!");
   }
	 else {
   head = delete_last_CLL(head);
   printf("Last log entry deleted successfully!");
                }
  printFooter();
     break;   
     case 6:
    clearScreen();
    printf("=== DELETE LOG ENTRY BY ID ===\n\n"); 
      if (head == NULL) {
   printf("No log entries to delete!");
                } 
				else {
  printf("Enter ID to delete: ");
 scanf("%d", &id);       
   head = delete_by_id_CLL(head, id);
  printf("Log entry with ID %d deleted if found!", id);
   }
printFooter();
 break;   
  case 7:
 clearScreen();
    printf("=== DELETE LOG ENTRY BY TIMESTAMP ===\n\n");
  if (head == NULL) {
    printf("No log entries to delete!");
  } 
	else {
  printf("Enter timestamp to delete (YYYY-MM-DD HH:MM:SS): ");
 fgets(timestemp, sizeof(timestemp), stdin);
 timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline             
  head = delete_by_timestemp_CLL(head, timestemp);
 printf("Log entry with timestamp '%s' deleted if found!", timestemp);
                }
  printFooter();
  break;
            case 8:
     clearScreen();
    printf("=== SEARCH LOG ENTRY BY ID ===\n\n"); 
     if (head == NULL) {
        printf("No log entries to search!");
                }
		 else {
     printf("Enter ID to search: ");
       scanf("%d", &id);
        node* result = search_by_id_CLL(head, id);
      if (result != NULL) {
      printf("\nLog entry found:\n");
     printf("ID: %d\n", result->id);
     printf("Severity: %d\n", result->severity);
     printf("Timestamp: %s\n", result->timestemp);
    printf("Description: %s\n", result->describtion);
                    } 
					else {
    printf("No log entry found with ID %d!", id);
                    }
                }
      printFooter();
    break;
            case 9: 
   clearScreen();
    printf("=== SEARCH LOG ENTRY BY TIMESTAMP ===\n\n");
     if (head == NULL) {
    printf("No log entries to search!");
                }  
				else {
       printf("Enter timestamp to search (YYYY-MM-DD HH:MM:SS): ");
   fgets(timestemp, sizeof(timestemp), stdin);
   timestemp[strcspn(timestemp, "\n")] = 0;
	 node* result = search_by_timestemp_CLL(head, timestemp);
              if (result != NULL) {
     printf("\nLog entry found:\n");
     printf("ID: %d\n", result->id);
     printf("Severity: %d\n", result->severity);
    printf("Timestamp: %s\n", result->timestemp);
      printf("Description: %s\n", result->describtion);
                    } 
			else {
                      printf("No log entry found with timestamp '%s'!", timestemp);
                 }
                }
                printFooter();
                break;
            case 10:
                clearScreen();
                printf("=== SEARCH LOG ENTRY BY KEYWORD ===\n\n");
                if (head == NULL) {
                    printf("No log entries to search!");
                } 
				else {
                    printf("Enter keyword to search in descriptions: ");
                    fgets(keyword, sizeof(keyword), stdin);
                    keyword[strcspn(keyword, "\n")] = 0; 
                    node* result = search_by_keyword_CLL(head, keyword);
                 if (result != NULL) {
                        printf("\nLog entry found:\n");
                        printf("ID: %d\n", result->id);
                        printf("Severity: %d\n", result->severity);
                        printf("Timestamp: %s\n", result->timestemp);
                        printf("Description: %s\n", result->describtion);
                    } 
					else {
            printf("No log entry found containing keyword '%s'!", keyword);
                }
                }
        printFooter();
      break;
            case 11:
                clearScreen();
                printf("=== SORT LOG ENTRIES BY DATE ===\n\n");
                if (head == NULL) {
          printf("No log entries to sort!");
                } 
				else {
        head = sort_by_date_CLL(head);
          printf("Log entries sorted by date successfully!");
                }
        printFooter();
                break;
            case 12: 
                clearScreen();
                printf("=== SORT LOG ENTRIES BY SEVERITY ===\n\n");
        if (head == NULL) {
      printf("No log entries to sort!");
                }
	 else {
      head = sort_by_severity_CLL(head);
    printf("Log entries sorted by severity successfully!");
                }
           printFooter();
         break;
            case 13:
                clearScreen();
                printf("=== REVERSE LOG ENTRIES ===\n\n"); 
           if (head == NULL) {
            printf("No log entries to reverse!");
                } 
				else {
          head = reverse_CLL(head);
       printf("Log entries reversed successfully!");
           }
                printFooter();
                break;
            case 14:
          clearScreen();
        printf("=== COUNT LOG ENTRIES ===\n\n");
          int total = count_CLL(head);
         printf("Total number of log entries: %d", total);
        printFooter();
             break;
            case 15: 
              clearScreen();
                  printf("=== DISPLAY ALL LOG ENTRIES ===\n\n");
                if (head == NULL) {
                    printf("No log entries to display!");
			     } 
				else {
                    printCLL(head);
                      }
                printFooter();
                break;
            case 16:
   clearScreen();
           printf("=== EXITING LOG ENTRY MANAGEMENT SYSTEM ===\n\n");
             if (head != NULL) {
                 node* current = head;
                  node* firstNode = head;
             do {
                 node* temp = current;
                        current = current->next;
                          free(temp);
                       } while (current != firstNode);
                   }
                printf("All log entries freed from memory.\n");
                printf("Thank you for using the Log Entry Management System!\n");
                return 0;
            default:
                clearScreen();
                  printf("Invalid choice! Please enter a number between 1 and 16.\n");
                 printFooter();
            }
          }
    return 0;
}
