#include "stacks.h" 
#include "linkedLists.h" 
#include <ctype.h>
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
 node *insert_at_position (node *head,node *newnode ,int position) { 
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
    TStack *dictionary = createStack();
    TQueue *queue;
    BList *list;
    char word[50], synonym[50], antonym[50];
    int choice;
    
    // Pre-populate with some sample words
    dictionary = addWordStack(dictionary, "happy", "joyful", "sad");
    dictionary = addWordStack(dictionary, "big", "large", "small");
    dictionary = addWordStack(dictionary, "good", "excellent", "bad");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1: // Add new word
                printf("\nEnter word: ");
                scanf("%49s", word);
                clearInputBuffer();
                
                printf("Enter synonym: ");
                scanf("%49s", synonym);
                clearInputBuffer();
                
                printf("Enter antonym: ");
                scanf("%49s", antonym);
                clearInputBuffer();
                
                dictionary = addWordStack(dictionary, word, synonym, antonym);
                printf("\nWord added successfully!\n\n");
                break;
                
            case 2: // Update existing word
                printf("\nEnter word to update: ");
                scanf("%49s", word);
                clearInputBuffer();
                
                printf("Enter new synonym: ");
                scanf("%49s", synonym);
                clearInputBuffer();
                
                printf("Enter new antonym: ");
                scanf("%49s", antonym);
                clearInputBuffer();
                
                dictionary = updateWordStack(dictionary, word, synonym, antonym);
                printf("\nWord updated successfully!\n\n");
                break;
                
            case 3: // Delete word
                printf("\nEnter word to delete: ");
                scanf("%49s", word);
                clearInputBuffer();
                
                dictionary = deleteWordStack(dictionary, word);
                printf("\nWord deleted successfully!\n\n");
                break;
                
            case 4: // Display all words
                printf("\n--- Dictionary Contents ---\n");
                printStack(dictionary);
                printf("\n");
                break;
                
            case 5: // Search for a word
                printf("\nEnter word to search: ");
                scanf("%49s", word);
                clearInputBuffer();
                
                printf("\n--- Word Information ---\n");
                dictionary = getInfWordStack(dictionary, word);
                printf("\n");
                break;
                
            case 6: // Sort dictionary
                dictionary = sortWordStack(dictionary);
                printf("\nDictionary sorted successfully!\n\n");
                break;
                
            case 7: // Convert to queue and display
                queue = stackToQueue(dictionary);
                printQueue(queue);
                printf("\n");
                // Free queue memory
                while (queue->front != NULL) {
                    TList *temp = queue->front;
                    queue->front = queue->front->next;
                    free(temp);
                }
                free(queue);
                break;
                
            case 8: // Convert to doubly linked list and display
                list = StacktoList(dictionary);
                printBList(list);
                printf("\n");
                // Free list memory
                while (list != NULL) {
                    BList *temp = list;
                    list = list->next;
                    free(temp);
                }
                break;
                
            case 9: // Check if a word is a palindrome
                printf("\nEnter word to check: ");
                scanf("%49s", word);
                clearInputBuffer();
                
                if (isPalindromeStack(word)) {
                    printf("\n'%s' is a palindrome!\n\n", word);
                } else {
                    printf("\n'%s' is not a palindrome!\n\n", word);
                }
                break;
                
            case 10: // Find the alphabetically smallest word
                if (!isEmpty(*dictionary)) {
                    char *smallest = getSmallest(dictionary);
                    printf("\nThe alphabetically smallest word is: '%s'\n\n", smallest);
                } else {
                    printf("\nDictionary is empty!\n\n");
                }
                break;
                
            case 0: // Exit
                printf("\nExiting program. Goodbye!\n");
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
        
    } while (choice != 0);
    
    // Free memory before exiting
    while (!isEmpty(*dictionary)) {
        Stacknode *temp = pop(dictionary);
        free(temp);
    }
    free(dictionary);
    
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to display menu options
void displayMenu() {
    printf("===== DICTIONARY MANAGEMENT SYSTEM =====\n");
    printf("1. Add a new word with synonym and antonym\n");
    printf("2. Update an existing word\n");
    printf("3. Delete a word\n");
    printf("4. Display all words (dictionary)\n");
    printf("5. Search for a word\n");
    printf("6. Sort dictionary\n");
    printf("7. Convert to queue and display\n");
    printf("8. Convert to doubly linked list and display\n");
    printf("9. Check if a word is a palindrome\n");
    printf("10. Find the alphabetically smallest word\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Function to display queue
void printQueue(TQueue *queue) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    TList *current = queue->front;
    printf("\nQUEUE:\n");
    while (current != NULL) {
        printf("Word: %s | Related: %s | Characters: %d | Vowels: %d\n", 
               current->word, current->related, current->countchar, current->countvow);
        current = current->next;
    }
}
void printBList(BList *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    BList *current = head;
    printf("\nDOUBLY LINKED LIST:\n");
    while (current != NULL) {
        printf("Word: %s | Synonym: %s | Antonym: %s | Characters: %d | Vowels: %d\n", 
               current->word, current->synonym, current->antonym, 
               current->countchar, current->countvow);
        current = current->next;
    }
}
