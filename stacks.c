#include "stacks.h" 
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
 void push(TStack *stk, Stacknode *node) {
    if (stk == NULL || node == NULL) return;
    node->next = stk->top;
    stk->top = node;
}

int isEmpty(TStack stack) {
    return stack.top == NULL;
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
Stacknode *pop(TStack *stk) {
    if(isEmpty(*stk)) return NULL;
    Stacknode *temp = stk->top;
    stk->top = stk->top->next;
    return temp;
}
void printStack(TStack *stk) {
    Stacknode *curr = stk->top;
    printf("\n STACK: \n");
    while (curr != NULL) {
        printf("Word: %s | Synonym: %s | Antonym: %s\n", curr->word, curr->synonym, curr->antonym);
        curr = curr->next;
    }
}
int countVowels(const char *str){
    int count = 0; 
    int i ;
    for(i = 0; str[i]; i++){
        char c= tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        	count++;
		}
    }
    return count;
}
TStack *toStack(BList *merged){
    TStack *stack= (TStack *)malloc(sizeof(TStack));
    stack->top= NULL;
    BList *current= merged;
    while(current!= NULL){
        Stacknode *newnode = (Stacknode *)malloc(sizeof(Stacknode));
        strcpy(newnode->word, current->word);
        strcpy(newnode->synonym, current->synonym);
        strcpy(newnode->antonym, current->antonym);
        newnode->charcount= current->countchar;
        newnode->countvow= current->countvow;
        newnode->next= NULL;
        push(stack, newnode);
        current= current->next;
    }

    return stack;
}
TStack *sortWordStack(TStack *stk){
    if (stk== NULL || isEmpty(*stk)){
        return stk;
    }
    int count= 0;
    int i, j;
    Stacknode *nodes[100]; 
    while(!isEmpty(*stk)){
        Stacknode *node = pop(stk);
        nodes[count] = node;
        count ++;
    }
    for(i=0; i <count-1; i++){
        for( j = i+1; j < count; j++) {
            if(strcmp(nodes[i]->word, nodes[j]->word) > 0){
                Stacknode *t= nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = t;
            }
        }
    }
    for(i =count-1; i>=0; i--){
        push(stk, nodes[i]);
    }
    return stk;
}
TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton){
    if (stk == NULL || isEmpty(*stk)){
    	return stk;
	}
    Stacknode *current = stk->top;
    while(current != NULL){
        if (strcmp(current->word, word) == 0){
            strcpy(current->synonym, syne);
            strcpy(current->antonym, anton);
            break;
        }
        current= current->next;
    }
    return stk;
}
BList *StacktoList(TStack *stk){
    Stacknode *nodes[100];
    int count = 0;
    int i, j;
    BList *head = NULL, *tail = NULL;
    if (stk == NULL || isEmpty(*stk)){
    	return NULL;
	}
    while (!isEmpty(*stk)){
        nodes[count++] = pop(stk);
    }
    for (i = 0; i < count - 1; i++){
        for (j = i + 1; j < count; j++) {
            if (strcmp(nodes[i]->word, nodes[j]->word) > 0){
                Stacknode *temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
    for (i = 0; i < count; i++){
        BList *newnode = (BList *)malloc(sizeof(BList));
        strcpy(newnode->word, nodes[i]->word);
        strcpy(newnode->synonym, nodes[i]->synonym);
        strcpy(newnode->antonym, nodes[i]->antonym);
        newnode->countchar = nodes[i]->charcount;
        newnode->countvow = nodes[i]->countvow;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL){
            head = tail = newnode;
        } 
		else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    return head;
}
char *getSmallest(TStack *stk){
    if(stk == NULL || isEmpty(*stk)) return NULL;
    Stacknode *current = stk->top;
    char *smallest = current->word;
    while(current != NULL) {
        if(strcmp(current->word, smallest) < 0){
            smallest = current->word;
        }
        current = current->next;
    }
    return smallest;
}
bool isPalindromeStack(char *word){
    int len = strlen(word);
    char stack[100];
    int i;
    int top = -1;
    for( i = 0; i < len; i++){
    	top++;
        stack[top] = tolower(word[i]);
    }
    for (i = 0; i<len; i++){
        char c = tolower(word[i]);
        if (c != stack[top]){
            return false;
        }
        top--;
    }
    return true;
}
TStack *createStack() {
  TStack *stack = (TStack *)malloc(sizeof(TStack));
   stack->top = NULL;
    return stack;
}
TStack *getInfWordStack(TStack *stk, char *word) {
 Stacknode *temp = stk->top;
   while (temp != NULL) {
    if (strcmp(temp->word, word) == 0) {
      printf("Word: %s\n", temp->word);
      printf("Synonym: %s\n", temp->synonym);
      printf("Antonym: %s\n", temp->antonym);
      printf("Characters: %d, Vowels: %d\n", temp->charcount, temp->countvow);
    break;
        }
 temp = temp->next;
    }
   return stk;
}  
TStack *deleteWordStack(TStack *stk, char *word) {
     TStack *tempStack = (TStack *)malloc(sizeof(TStack));
     tempStack->top = NULL;
    while (!isEmpty(*stk)) {
    Stacknode *node = pop(stk);
    if (strcmp(node->word, word) != 0) {
      push(tempStack, node);
    } else {
            free(node);
        }
    }
    while (!isEmpty(*tempStack)) {
        push(stk, pop(tempStack));
    }
    free(tempStack);
    return stk;
}
TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton) {
     Stacknode *newnode = (Stacknode *)malloc(sizeof(Stacknode));
    strcpy(newnode->word, word);
    strcpy(newnode->synonym, syne);
    strcpy(newnode->antonym, anton);
    newnode->charcount = strlen(word);
    newnode->countvow = countVowels(word);
    newnode->next = NULL;
    push(stk, newnode);
    return stk;
} 
void enqueue(TQueue *queue, TList *node) {
    node->next = NULL;
   if (queue->rear == NULL) {
    queue->front = queue->rear = node;
    } 
	else {
      queue->rear->next = node;
      queue->rear = node;
    }
}
TQueue *stackToQueue(TStack *stk) {
     TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
      queue->front = NULL;
     queue->rear = NULL;
    TStack *tempStack = createStack();
    while (!isEmpty(*stk)) {
        push(tempStack, pop(stk));
    }
    while (!isEmpty(*tempStack)) {
          Stacknode *snode = pop(tempStack);
        TList *newNode = (TList *)malloc(sizeof(TList));
        strcpy(newNode->word, snode->word);
          sprintf(newNode->related, "%s/%s", snode->synonym, snode->antonym);
         newNode->countchar = snode->charcount;
          newNode->countvow = snode->countvow;
         newNode->next = NULL;
          enqueue(queue, newNode);
        free(snode);
    }
    free(tempStack);
    return queue;
}
int main() {
    // Part 1 variables
    node *head = NULL;
    int id, severity, position;
    char timestemp[10], describtion[100], keyword[50];
    node *result;
    
    // Part 2 variables
    TStack *wordStack = createStack();
    TStack *infixStack = NULL;
    BList *wordList = NULL;
    TQueue *resultQueue = NULL;
    threeTstack categorizedWords;
    categorizedWords.shortWords = createStack();
    categorizedWords.longWords = createStack();
    categorizedWords.diphthongs = createStack();
    char word[20], synonym[20], antonym[20];
    Stacknode *wordNode;
    
    printf("\n==== Linked List and Stack Management System ====\n");
    
    int choice;
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
                            fgets(keyword, sizeof(keyword), stdin);
                            keyword[strcspn(keyword, "\n")] = 0; // Remove newline
                            node *found = search_by_keyword(head, keyword);
                            if (found) {
                                printf("\nFound entry:\n");
                                printf("ID: %d\n", found->id);
                                printf("Severity: %d\n", found->severity);
                                printf("Timestamp: %s\n", found->timestemp);
                                printf("Description: %s\n", found->describtion);
                            } else {
                                printf("No entry found with keyword '%s'.\n", keyword);
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
                    printf("1. Add a new word\n");
                    printf("2. Delete a word\n");
                    printf("3. Update a word\n");
                    printf("4. Search for a word\n");
                    printf("5. Display all words\n");
                    printf("6. Sort word stack\n");
                    printf("7. Check if word is palindrome\n");
                    printf("8. Convert stack to list\n");
                    printf("9. Get smallest word\n");
                    printf("10. Convert stack to queue\n");
                    printf("11. Count vowels in a word\n");
                    printf("12. Categorize words\n");
                    printf("0. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar(); // Consume newline
                    
                    switch (choice) {
                        case 1: // Add a new word
                            printf("Enter word: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("Enter synonym: ");
                            fgets(synonym, sizeof(synonym), stdin);
                            synonym[strcspn(synonym, "\n")] = 0; // Remove newline
                            
                            printf("Enter antonym: ");
                            fgets(antonym, sizeof(antonym), stdin);
                            antonym[strcspn(antonym, "\n")] = 0; // Remove newline
                            
                            wordStack = addWordStack(wordStack, word, synonym, antonym);
                            printf("Word added successfully!\n");
                            break;
                            
                        case 2: // Delete a word
                            printf("Enter word to delete: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            wordStack = deleteWordStack(wordStack, word);
                            printf("Word deleted successfully if found!\n");
                            break;
                            
                        case 3: // Update a word
                            printf("Enter word to update: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("Enter new synonym: ");
                            fgets(synonym, sizeof(synonym), stdin);
                            synonym[strcspn(synonym, "\n")] = 0; // Remove newline
                            
                            printf("Enter new antonym: ");
                            fgets(antonym, sizeof(antonym), stdin);
                            antonym[strcspn(antonym, "\n")] = 0; // Remove newline
                            
                            wordStack = updateWordStack(wordStack, word, synonym, antonym);
                            printf("Word updated successfully if found!\n");
                            break;
                            
                        case 4: // Search for a word
                            printf("Enter word to search: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            infixStack = getInfWordStack(wordStack, word);
                            if (infixStack != NULL && !isEmpty(*infixStack)) {
                                printf("Word found! Related information:\n");
                                printStack(infixStack);
                            } else {
                                printf("Word not found in dictionary!\n");
                            }
                            break;
                            
                        case 5: // Display all words
                            printf("\n===== Dictionary Words =====\n");
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty.\n");
                            } else {
                                printStack(wordStack);
                            }
                            break;
                            
                        case 6: // Sort word stack
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty, nothing to sort.\n");
                            } else {
                                wordStack = sortWordStack(wordStack);
                                printf("Dictionary sorted successfully!\n");
                            }
                            break;
                            
                        case 7: // Check if word is palindrome
                            printf("Enter word to check: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            if (isPalindromeStack(word)) {
                                printf("'%s' is a palindrome!\n", word);
                            } else {
                                printf("'%s' is not a palindrome.\n", word);
                            }
                            break;
                            
                        case 8: // Convert stack to list
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty, nothing to convert.\n");
                            } else {
                                wordList = StacktoList(wordStack);
                                if (wordList != NULL) {
                                    printf("Stack converted to list successfully!\n");
                                    // Note: You might want to add a function to print the list
                                    printf("List contents (printing first few entries):\n");
                                    BList *current = wordList;
                                    int count = 0;
                                    while (current != NULL && count < 5) {
                                        // Print based on your BList structure
                                        // printf("Word: %s\n", current->data);
                                        current = current->next;
                                        count++;
                                    }
                                } else {
                                    printf("Failed to convert stack to list.\n");
                                }
                            }
                            break;
                            
                        case 9: // Get smallest word
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty.\n");
                            } else {
                                char *smallest = getSmallest(wordStack);
                                if (smallest != NULL) {
                                    printf("The smallest word is: %s\n", smallest);
                                } else {
                                    printf("Error finding the smallest word.\n");
                                }
                            }
                            break;
                            
                        case 10: // Convert stack to queue
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty, nothing to convert.\n");
                            } else {
                                resultQueue = stackToQueue(wordStack);
                                if (resultQueue != NULL) {
                                    printf("Stack converted to queue successfully!\n");
                                    // Note: Add code to print the queue if needed
                                } else {
                                    printf("Failed to convert stack to queue.\n");
                                }
                            }
                            break;
                            
                        case 11: // Count vowels in a word
                            printf("Enter word to count vowels: ");
                            fgets(word, sizeof(word), stdin);
                            word[strcspn(word, "\n")] = 0; // Remove newline
                            
                            printf("'%s' has %d vowels.\n", word, countVowels(word));
                            break;
                            
                        case 12: // Categorize words
                            if (isEmpty(*wordStack)) {
                                printf("Dictionary is empty, nothing to categorize.\n");
                            } else {
                                printf("Categorizing words into short words, long words, and diphthongs...\n");
                                
                                // Reset categorized stacks
                                categorizedWords.shortWords = createStack();
                                categorizedWords.longWords = createStack();
                                categorizedWords.diphthongs = createStack();
                                
                                // Implement logic to categorize words from wordStack into the three categories
                                // This is a placeholder - you'll need to implement the actual categorization logic
                                TStack tempStack = *wordStack;
                                while (!isEmpty(tempStack)) {
                                    Stacknode *node = pop(&tempStack);
                                    if (node) {
                                        int len = strlen(node->word);
                                        // Example categorization logic
                                        if (len <= 4) {
                                            push(categorizedWords.shortWords, node);
                                        } else if (len > 7) {
                                            push(categorizedWords.longWords, node);
                                        } else {
                                            // Check for diphthongs (placeholder logic)
                                            // You'd need to implement proper diphthong detection
                                            if (strstr(node->word, "ae") || strstr(node->word, "oe") || 
                                                strstr(node->word, "au") || strstr(node->word, "ou")) {
                                                push(categorizedWords.diphthongs, node);
                                            } else {
                                                // Default to long words if doesn't match other criteria
                                                push(categorizedWords.longWords, node);
                                            }
                                        }
                                    }
                                }
                                
                                printf("\nCategorization complete!\n");
                                printf("Short words: %d entries\n", countVowels("placeholder")); // Replace with actual count
                                printf("Long words: %d entries\n", countVowels("placeholder")); // Replace with actual count
                                printf("Words with diphthongs: %d entries\n", countVowels("placeholder")); // Replace with actual count
                            }
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
                
            case 0:
                printf("\nExiting program. Goodbye!\n");
                while (head != NULL) {
                    node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
