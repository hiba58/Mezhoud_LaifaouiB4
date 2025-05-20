#include "linkedLists.h"
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
// part 2 
void enqueue(TQueue *queue, TList *node) {
    TList *newnode = (TList *)malloc(sizeof(TList));
    *newnode = *node;
    newnode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newnode;
    } else {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}
int countvowel(char *word){
	int counter=0;
	int i;
	for(i=0; word[i]!='\0'; i++){
		char c=word[i];
		if(c=='a' || c=='e' || c=='o' || c=='u' || c=='i' ||c=='A' || c=='E' || c=='O' || c=='U' || c=='I' ){
			counter++;
		}
	}
	return counter;
}
void swap(TList *i, TList *j) {
    char tempWord[20], tempRelated[20];
    int tempChar, tempVow;

    strcpy(tempWord, i->word);
    strcpy(tempRelated, i->related);
    tempChar = i->countchar;
    tempVow = i->countvow;

    strcpy(i->word, j->word);
    strcpy(i->related, j->related);
    i->countchar = j->countchar;
    i->countvow = j->countvow;

    strcpy(j->word, tempWord);
    strcpy(j->related, tempRelated);
    j->countchar = tempChar;
    j->countvow = tempVow;
}
TList *getSynWords(FILE *f){
	if(f==NULL){
		return NULL;
	}
	TList *head= NULL;
	char buffer[50];
	char word[20], synonym[20]; 
    while(fgets(buffer, sizeof(buffer), f)){
    	if(sscanf(buffer, "%[^=]=%[^\n]", word, synonym)==2){
    		TList *newnode= (TList*)malloc(sizeof(TList));
    		strcpy(newnode->word, word);
    		strcpy(newnode->related, synonym);
    		newnode->countchar=strlen(word);
    		newnode->countvow=countvowel(word);
    		newnode->next= NULL;
    		if(head== NULL){
    			head=newnode;
			}
			else{
				TList *current= head;
				while(current->next!=NULL){
					current=current->next;
				}
				current->next=newnode;
			}
		}
	}
	return head;
}
void getInfWord(TList *syn, TList *ant, char *word){
	TList *tempsyn=syn;
	TList *tempant=ant;
	while(tempsyn !=NULL){
		if(strcmp(tempsyn->word, word)==0){
			printf("word: %s; synonym: %s; characters: %d; vowels: %d \n", tempsyn->word, tempsyn->related, tempsyn->countchar, tempsyn->countvow);
		}
		tempsyn =tempsyn->next;
	}
	while(tempant !=NULL){
		if(strcmp(tempant->word, word)==0){
			printf("word: %s; antonym: %s; characters: %d; vowels: %d \n", tempant->word, tempant->related, tempant->countchar, tempant->countvow);
		}
		tempant =tempant->next;
	}
	
}
TList *sortWord(TList *syn){
	if(syn==NULL || syn->next==NULL){
		return syn;
	}
	TList *i, *j;
	for(i=syn; i!=NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if( strcmp(i->word, j->word)>0){
			 swap(i ,j);
			}
		}
	}
	return syn;
}
TList *sortWord3(TList *syn){
	if(syn==NULL || syn->next==NULL){
		return syn;
	}
    TList *i, *j;
   	char *tempword, *tempsyn;
	int tempvowel, tempchar;
    for(i=syn; i!=NULL; i=i->next){
    	for(j=i->next; j!=NULL; j=j->next){
    		if(i->countvow > j->countvow){
    		swap(i ,j);
			}
		}
	}
	return syn;
}
TList *updateWord(FILE *f , TList *syn, TList *ant, char *word, char *syne, char *anton){
	TList *temp=syn;
	while(temp !=NULL){
		if(strcmp(temp->word, word)==0){
			strcpy(temp->related, syne);
			break;
		}
		temp=temp->next;
	}
	temp= ant;
	while(temp !=NULL){
		if(strcmp(temp->word, word)==0){
			strcpy(temp->related, anton);
			break;
		}
		temp=temp->next;
	}
	 rewind(f);
    FILE *tempFile = fopen("temp.txt", "w");
	 char buffer[50], fword[20], fsyn[20];
    while (fgets(buffer, sizeof(buffer), f)){
        if (sscanf(buffer, "%[^=]=%[^\n]", fword, fsyn) == 2){
            if (strcmp(fword, word) == 0) {
                fprintf(tempFile, "%s=%s\n", word, syne);  
            } 
			else {
                fprintf(tempFile, "%s=%s\n", fword, fsyn);
            }
        }
	    else if (sscanf(buffer, "%[^#]#%[^\n]", fword, fsyn) == 2){
            if (strcmp(fword, word) == 0) {
                fprintf(tempFile, "%s#%s\n", word, anton);  
            } 
			else {
                fprintf(tempFile, "%s#%s\n", fword, fsyn);
            }
        } 
		else {
            fputs(buffer, tempFile); 
        }
    }
    fclose(f);
    fclose(tempFile);
    remove("file.txt");         
    rename("temp.txt", "file.txt"); 
    return syn; 
}
TList *countWord(TList *syn, char *prt){
	TList *newlist=NULL, *temp=syn;
	while(temp!=NULL){
		if(strstr(temp->word, prt)!= NULL){
			TList *newnode=(TList *)malloc(sizeof(TList));
			strcpy(newnode->word, temp->word);
			strcpy(newnode->related, temp->related);
			newnode->countchar= temp->countchar;
			newnode->countvow= temp->countvow;
			newnode->next=NULL;
			if(newlist==NULL){
			newlist= newnode;
		}
		else{
			TList *current=newlist;
			while(current->next != NULL){
				current=current->next;
			}
			current->next=newnode;
		}
		}
		
		temp=temp->next;
	}
	return newlist;
	
}
BList *merge(TList *syn, TList *ant){
	BList *head=NULL;
    TList *synt= syn;
	TList *antt= ant;
    while(synt!= NULL){
    	TList *temp=antt;
    	while(temp!= NULL){
    		if(strcmp(synt->word, temp->word)){
    			BList *newnode=(BList *)malloc(sizeof(BList));
    			strcpy(newnode->word, synt->word);
    			strcpy(newnode->synonym, synt->related);
    			strcpy(newnode->antonym, temp->related);
    			newnode->countchar=synt->countchar;
    			newnode->countvow=synt->countvow;
    			newnode->prev=NULL;
    			newnode->next=head;
    			if(head!=NULL){
    				head->prev=newnode;
				}
				head=newnode;
				break; 
			}
			temp=temp->next;
		}
		synt=synt->next;
	}
	return head;
}
TList *getAntoWords(FILE *f){
	if(f==NULL){
		return NULL;
	}
	TList *head= NULL;
	char buffer[50];
  	char word[20], anto[20]; 
       while(fgets(buffer, sizeof(buffer), f)){
        	if(sscanf(buffer, "%[^#]#%[^\n]", word, anto)==2){
    	TList *newnode= (TList*)malloc(sizeof(TList));
    	strcpy(newnode->word, word);
    	strcpy(newnode->related, anto);
    	newnode->countchar=strlen(word);
    	newnode->countvow=countvowel(word);
    	newnode->next= NULL;
    		if(head== NULL){
    			head=newnode;
			}
			else{
				TList *current= head;
				while(current->next!=NULL){
					current=current->next;
			}
			current->next=newnode;
		}
	}
	}
	return head;
} 
 void getInfWord2(TList *syn, TList *ant, char *inf){
	TList *temp=syn;
	while(temp!=NULL){
		if(strcmp(temp->related, inf)==0){
			printf("word: %s; characters: %d; vowels: %d \n", temp->word, temp->countchar, temp->countvow);
	}
		temp =temp->next;
	} 
	temp=ant;
	while(temp!=NULL){
		if(strcmp(temp->related, inf)==0){
			printf("word: %s; characters: %d; vowels: %d \n", temp->word, temp->countchar, temp->countvow);
		}
		temp =temp->next;
	}
}  
TList *sortWord2(TList *syn){
	if(syn==NULL || syn->next==NULL){
		return syn;
	}
    TList *i, *j;
    for(i=syn; i!=NULL; i=i->next){
    	for(j=i->next; j!=NULL; j=j->next){
    		if(i->countchar < j->countchar){
    		swap(i ,j);
			}
		}
	}
	return syn;
} 
TList *deleteWord(FILE *f, TList *syn, TList *ant, char *word) {
    TList *prev = NULL, *temp = syn;
    while (temp) {
    if (strcmp(temp->word, word) == 0) {
     if (prev) prev->next = temp->next;
  else syn = temp->next;
    free(temp);
    break;
        }
    prev = temp;
    temp = temp->next;
    }
    prev = NULL;
    temp = ant;
    while (temp) {
    if (strcmp(temp->word, word) == 0) {
    if (prev) prev->next = temp->next;
   else ant = temp->next;
    free(temp);
    break;
        }
    prev = temp;
    temp = temp->next;
    }
    rewind(f);
       FILE *tempFile = fopen("temp.txt", "w");
   char buffer[100], w[20], rel[20];
    while (fgets(buffer, sizeof(buffer), f)) {
      if ((sscanf(buffer, "%[^=]=%[^\n]", w, rel) == 2 && strcmp(w, word) != 0) ||
         (sscanf(buffer, "%[^#]#%[^\n]", w, rel) == 2 && strcmp(w, word) != 0)) {
        fputs(buffer, tempFile);
        }
    }
      fclose(f);
      fclose(tempFile);
      remove("file.txt");
       rename("temp.txt", "file.txt");
    return syn;
}  
int callculate_rate(char *a ,char *b){
	int i , count=0; 
	int lonstrlen;
	int str1length = strlen(a); 
	int str2length = strlen(b); 
     	if(str1length>str2length) 
	        lonstrlen=str1length ; 
	    else  
	     lonstrlen=str2length ;  
	   for(i=0 ;a[i]!='\0' && b[i]!='\0';i++){
	   	if(a[i]==b[i]){
	   		count++;
		   }
	   } 
	   return (count*100)/lonstrlen;
} 
TList *similarWord(TList *syn, char *word, int rate) {
    TList *head = NULL;
    TList *tail = NULL;
    TList *temp = syn;
    while (temp != NULL) {
        if (callculate_rate(temp->word, word) >= rate) {
            TList *newNode = (TList *)malloc(sizeof(TList));
             strcpy(newNode->word, temp->word);
             strcpy(newNode->related, temp->related);
           newNode->countchar = temp->countchar;
           newNode->countvow = temp->countvow;
           newNode->next = NULL;
            if (head == NULL) {
                head = tail = newNode;
            } else {
             tail->next = newNode;
             tail = newNode;
           }
        }
        temp = temp->next;
    }
    return head;
} 
TQueue *toQueue(BList *merged) {
    TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
    queue->front = NULL;
     queue->rear = NULL;
      BList *temp = merged; 
     while (temp != NULL) {
        TList tempNode;
          strcpy(tempNode.word, temp->word);
          sprintf(tempNode.related, "%s/%s", temp->synonym, temp->antonym);
         tempNode.countchar = temp->countchar;
        tempNode.countvow = temp->countvow;
        tempNode.next = NULL;
        enqueue(queue, &tempNode); 
        temp = temp->next;
    }
    return queue;
}
int isPalindrome(char *str) { 
int i ;
      int len = strlen(str);
     for ( i = 0; i < len / 2; i++) {
      if (str[i] != str[len - i - 1]) return 0;
      }
     return 1;
}
TQueue *syllable(TList *syn) {
    TQueue *q = (TQueue *)malloc(sizeof(TQueue));
    q->front = q->rear = NULL;
    TList *temp = syn;
    while (temp != NULL) {
   TList *newnode = (TList *)malloc(sizeof(TList));
   *newnode = *temp;
    newnode->next = NULL;
    if (q->rear == NULL) {
    q->front = q->rear = newnode;
        }
		 else {
       q->rear->next = newnode;
       q->rear = newnode;
        }
   temp = temp->next;
    }
    return q;
}
TList *addlist(TList *list, char *word, char *related){
	TList *newnode=(TList *)malloc(sizeof(TList));
	strcpy(newnode->word, word);
	strcpy(newnode->related, related);
	newnode->countchar=strlen(word);
	newnode->countvow=countvowel(word);
	newnode->next=list;
	return newnode;
}
TList *addWord(TList *syn, TList *ant, char *word, char *syne, char *anton){
	syn=addlist(syn, word, syne);
	ant=addlist(ant, word, anton);
	FILE *f=fopen("file.txt", "a");
	fprintf(f, "%s=%s\n", word, syne);
    fprintf(f, "%s#%s\n", word, anton);
    fclose(f);
    return syn; 
}


int main() {
    node *head = NULL;
    TList *syn = NULL, *ant = NULL, *result = NULL;
    BList *merged = NULL;
    TQueue *queue = NULL;
    FILE *file = NULL;
    int choice, id, severity, position, rate;
    char timestemp[10], describtion[100], word[20], syne[20], anton[20], partOfWord[20], filename[50];
    
    printf("\n==== Linked List Management System ====\n");
    
    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Part 1: Log Entry Management\n");
        printf("2. Part 2: Word Dictionary Management\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                // Part 1 menu: Log Entry Management
                while (1) {
                    printf("\n===== LOG ENTRY MANAGEMENT =====\n");
                    printf("1. Create a new log entry\n");
                    printf("2. Insert at beginning\n");
                    printf("3. Insert at position\n");
                    printf("4. Delete by ID\n");
                    printf("5. Delete by timestamp\n");
                    printf("6. Search by ID\n");
                    printf("7. Search by timestamp\n");
                    printf("8. Search by keyword\n");
                    printf("9. Sort by severity\n");
                    printf("10. Reverse list\n");
                    printf("11. Count entries\n");
                    printf("12. Print all entries\n");
                    printf("0. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar(); // Consume newline
                    
                    switch (choice) {
                        case 1: {
                            printf("Enter ID: ");
                            scanf("%d", &id);
                            printf("Enter severity (1-5): ");
                            scanf("%d", &severity);
                            getchar(); // Consume newline
                            printf("Enter timestamp (format: MM/DD/YY): ");
                            fgets(timestemp, sizeof(timestemp), stdin);
                            timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline
                            printf("Enter description: ");
                            fgets(describtion, sizeof(describtion), stdin);
                            describtion[strcspn(describtion, "\n")] = 0; // Remove newline
                            
                            node *newnode = creat_node(id, severity, timestemp, describtion);
                            if (head == NULL) {
                                head = newnode;
                            } else {
                                printf("Node created. Use insert options to add to list.\n");
                            }
                            break;
                        }
                        case 2: {
                            printf("Enter ID: ");
                            scanf("%d", &id);
                            printf("Enter severity (1-5): ");
                            scanf("%d", &severity);
                            getchar(); // Consume newline
                            printf("Enter timestamp (format: MM/DD/YY): ");
                            fgets(timestemp, sizeof(timestemp), stdin);
                            timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline
                            printf("Enter description: ");
                            fgets(describtion, sizeof(describtion), stdin);
                            describtion[strcspn(describtion, "\n")] = 0; // Remove newline
                            
                            node *newnode = creat_node(id, severity, timestemp, describtion);
                            head = insert_at_beg(head, newnode);
                            printf("Node inserted at beginning successfully.\n");
                            break;
                        }
                        case 3: {
                            printf("Enter ID: ");
                            scanf("%d", &id);
                            printf("Enter severity (1-5): ");
                            scanf("%d", &severity);
                            getchar(); // Consume newline
                            printf("Enter timestamp (format: MM/DD/YY): ");
                            fgets(timestemp, sizeof(timestemp), stdin);
                            timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline
                            printf("Enter description: ");
                            fgets(describtion, sizeof(describtion), stdin);
                            describtion[strcspn(describtion, "\n")] = 0; // Remove newline
                            printf("Enter position to insert: ");
                            scanf("%d", &position);
                            
                            node *newnode = creat_node(id, severity, timestemp, describtion);
                            head = insert_at_position(head, newnode, position);
                            printf("Node inserted at position %d successfully.\n", position);
                            break;
                        }
                        case 4:
                            printf("Enter ID to delete: ");
                            scanf("%d", &id);
                            head = delet_by_id(head, id);
                            printf("Node deleted successfully if found.\n");
                            break;
                        case 5:
                            printf("Enter timestamp to delete (format: MM/DD/YY): ");
                            fgets(timestemp, sizeof(timestemp), stdin);
                            timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline
                            head = delet_by_timestemp(head, timestemp);
                            printf("Node deleted successfully if found.\n");
                            break;
                        case 6: {
                            printf("Enter ID to search: ");
                            scanf("%d", &id);
                            node *found = search_by_id(head, id);
                            if (found) {
                                printf("\nFound entry:\n");
                                printf("ID: %d\n", found->id);
                                printf("Severity: %d\n", found->severity);
                                printf("Timestamp: %s\n", found->timestemp);
                                printf("Description: %s\n", found->describtion);
                            } else {
                                printf("Entry with ID %d not found.\n", id);
                            }
                            break;
                        }
                        case 7: {
                            printf("Enter timestamp to search (format: MM/DD/YY): ");
                            fgets(timestemp, sizeof(timestemp), stdin);
                            timestemp[strcspn(timestemp, "\n")] = 0; // Remove newline
                            node *found = search_by_timestemp(head, timestemp);
                            if (found) {
                                printf("\nFound entry:\n");
                                printf("ID: %d\n", found->id);
                                printf("Severity: %d\n", found->severity);
                                printf("Timestamp: %s\n", found->timestemp);
                                printf("Description: %s\n", found->describtion);
                            } else {
                                printf("Entry with timestamp %s not found.\n", timestemp);
                            }
                            break;
                        }
                        case 8: {
                            printf("Enter keyword to search in descriptions: ");
                            fgets(describtion, sizeof(describtion), stdin);
                            describtion[strcspn(describtion, "\n")] = 0; // Remove newline
                            node *found = search_by_keyword(head, describtion);
                            if (found) {
                                printf("\nFound entry:\n");
                                printf("ID: %d\n", found->id);
                                printf("Severity: %d\n", found->severity);
                                printf("Timestamp: %s\n", found->timestemp);
                                printf("Description: %s\n", found->describtion);
                            } else {
                                printf("No entry found with keyword '%s'.\n", describtion);
                            }
                            break;
                        }
                        case 9:
                            head = sort_by_severity(head);
                            printf("List sorted by severity successfully.\n");
                            break;
                        case 10:
                            head = reverse(head);
                            printf("List reversed successfully.\n");
                            break;
                        case 11: {
                            int entries = count(head);
                            printf("Total number of entries: %d\n", entries);
                            break;
                        }
                        case 12:
                            printf("\n===== All Log Entries =====\n");
                            print(head);
                            break;
                        case 0:
                            printf("Returning to main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    
                    if (choice == 0) break;
                }
                break;
                
            case 2:
                // Part 2 menu: Word Dictionary Management
                while (1) {
                    printf("\n===== WORD DICTIONARY MANAGEMENT =====\n");
                    printf("1. Load dictionary from file\n");
                    printf("2. Get information about a word\n");
                    printf("3. Get words with specific synonym/antonym\n");
                    printf("4. Sort words alphabetically\n");
                    printf("5. Sort words by character count\n");
                    printf("6. Sort words by vowel count\n");
                    printf("7. Update word synonym/antonym\n");
                    printf("8. Count words with specific part\n");
                    printf("9. Delete a word\n");
                    printf("10. Find similar words\n");
                    printf("11. Merge synonym and antonym lists\n");
                    printf("12. Convert to queue\n");
                    printf("13. Create syllable queue\n");
                    printf("14. Add new word\n");
                    printf("0. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar(); // Consume newline
                    
                    switch (choice) {
                        case 1:
                            printf("Enter filename to load (e.g., file.txt): ");
                            fgets(filename, sizeof(filename), stdin);
                            filename[strcspn(filename, "\n")] = 0; // Remove newline
                            
                            file = fopen(filename, "r+");
                            if (file == NULL) {
                                printf("Error opening file. Creating new file.\n");
                                file = fopen(filename, "w+");
                                if (file == NULL) {
                                    printf("Error creating file.\n");
                                    break;
                                }
                            }
                            
                            syn = getSynWords(file);
                            rewind(file);
                            ant = getAntoWords(file);
                            
                            printf("Dictionary loaded successfully.\n");
                            break;
                            
                        case 2:
                            printf("Enter word to get information: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("\n===== Word Information =====\n");
                            getInfWord(syn, ant, word);
                            break;
                            
                        case 3:
                            printf("Enter synonym/antonym to find related words: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("\n===== Words Related to '%s' =====\n", word);
                            getInfWord2(syn, ant, word);
                            break;
                            
                        case 4:
                            syn = sortWord(syn);
                            ant = sortWord(ant);
                            printf("Words sorted alphabetically.\n");
                            break;
                            
                        case 5:
                            syn = sortWord2(syn);
                            ant = sortWord2(ant);
                            printf("Words sorted by character count.\n");
                            break;
                            
                        case 6:
                            syn = sortWord3(syn);
                            ant = sortWord3(ant);
                            printf("Words sorted by vowel count.\n");
                            break;
                            
                        case 7:
                            printf("Enter word to update: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("Enter new synonym: ");
                            fgets(syne, sizeof(syne), stdin);
                            syne[strcspn(syne, "\n")] = 0; // Remove newline
                            
                            printf("Enter new antonym: ");
                            fgets(anton, sizeof(anton), stdin);
                            anton[strcspn(anton, "\n")] = 0; // Remove newline
                            
                            syn = updateWord(file, syn, ant, word, syne, anton);
                            printf("Word updated successfully.\n");
                            break;
                            
                        case 8:
                            printf("Enter part of word to search: ");
                            fgets(partOfWord, sizeof(partOfWord), stdin);
                            partOfWord[strcspn(partOfWord, "\n")] = 0; // Remove newline
                            
                            result = countWord(syn, partOfWord);
                            
                            printf("\n===== Words containing '%s' =====\n", partOfWord);
                            TList *temp = result;
                            int count = 0;
                            while (temp != NULL) {
                                printf("Word: %s, Synonym: %s\n", temp->word, temp->related);
                                temp = temp->next;
                                count++;
                            }
                            printf("Total found: %d words\n", count);
                            
                            // Free the result list
                            while (result != NULL) {
                                TList *toFree = result;
                                result = result->next;
                                free(toFree);
                            }
                            break;
                            
                        case 9:
                            printf("Enter word to delete: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            syn = deleteWord(file, syn, ant, word);
                            printf("Word deleted successfully if found.\n");
                            break;
                            
                        case 10:
                            printf("Enter word to find similar words: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("Enter minimum similarity rate (0-100): ");
                            scanf("%d", &rate);
                            getchar(); // Consume newline
                            
                            result = similarWord(syn, word, rate);
                            
                            printf("\n===== Words similar to '%s' (minimum rate: %d%%) =====\n", word, rate);
                            temp = result;
                            count = 0;
                            while (temp != NULL) {
                                printf("Word: %s, Synonym: %s, Similarity: %d%%\n", 
                                    temp->word, temp->related, callculate_rate(temp->word, word));
                                temp = temp->next;
                                count++;
                            }
                            printf("Total found: %d words\n", count);
                            
                            // Free the result list
                            while (result != NULL) {
                                TList *toFree = result;
                                result = result->next;
                                free(toFree);
                            }
                            break;
                            
                        case 11:
                            merged = merge(syn, ant);
                            printf("Synonym and antonym lists merged successfully.\n");
                            break;
                            
                        case 12:
                            if (merged == NULL) {
                                printf("Please merge lists first (option 11).\n");
                                break;
                            }
                            
                            queue = toQueue(merged);
                            printf("Merged list converted to queue successfully.\n");
                            
                            // Display queue contents
                            printf("\n===== Queue Contents =====\n");
                            TList *current = queue->front;
                            while (current != NULL) {
                                printf("Word: %s, Related: %s\n", current->word, current->related);
                                current = current->next;
                            }
                            break;
                            
                        case 13:
                            queue = syllable(syn);
                            printf("Syllable queue created successfully.\n");
                            
                            // Display queue contents
                            printf("\n===== Syllable Queue Contents =====\n");
                            current = queue->front;
                            while (current != NULL) {
                                printf("Word: %s, Synonym: %s\n", current->word, current->related);
                                current = current->next;
                            }
                            break;
                            
                        case 14:
                            printf("Enter new word: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("Enter synonym: ");
                            fgets(syne, sizeof(syne), stdin);
                            syne[strcspn(syne, "\n")] = 0; // Remove newline
                            
                            printf("Enter antonym: ");
                            fgets(anton, sizeof(anton), stdin);
                            anton[strcspn(anton, "\n")] = 0; // Remove newline
                            
                            syn = addWord(syn, ant, word, syne, anton);
                            printf("Word added successfully.\n");
                            break;
                            
                        case 0:
                            printf("Returning to main menu...\n");
                            if (file != NULL) {
                                fclose(file);
                                file = NULL;
                            }
                            break;
                            
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    
                    if (choice == 0) break;
                }
                break;
                
            case 0:
                printf("\nExiting program. Goodbye!\n");
                
                // Free all allocated memory
                
                // Free Part 1 linked list
                while (head != NULL) {
                    node *temp = head;
                    head = head->next;
                    free(temp);
                }
                
                // Free Part 2 linked lists
                while (syn != NULL) {
                    TList *temp = syn;
                    syn = syn->next;
                    free(temp);
                }
                
                while (ant != NULL) {
                    TList *temp = ant;
                    ant = ant->next;
                    free(temp);
                }
                
                // Free merged list
                while (merged != NULL) {
                    BList *temp = merged;
                    merged = merged->next;
                    free(temp);
                }
                
                // Free queue
                if (queue != NULL) {
                    while (queue->front != NULL) {
                        TList *temp = queue->front;
                        queue->front = queue->front->next;
                        free(temp);
                    }
                    free(queue);
                }
                
                // Close file if open
                if (file != NULL) {
                    fclose(file);
                }
                
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
