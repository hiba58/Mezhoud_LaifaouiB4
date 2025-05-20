#include "recursion.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
node *reverse_ll(node *head){ 
node *temp;
	if(head==NULL){
		return NULL;
	} 
	else if(head->next==NULL){
		return head;
	} 
	temp=reverse_ll(head->next); 
	head->next->next=head; 
	head->next=NULL; 
	return temp; 
}  
int rec_factorial(int n){
	if(n==1){
		return 1; 
	} 
	else return n*rec_factorial(n-1); 	
} 
int rec_fibonacci(int n ){
	if(n==1){
		return 1; 
	} 
	if(n==0){ 
	return 1; 
	} 
	else return rec_fibonacci(n-1)+rec_fibonacci(n-2); 
}   
int max_id(node *head){ 
int max; 
	node *current=head ; 
	if(current==NULL){
		return -1; 
	} 
	 	max=max_id(current->next); 
     if(current->id>max){
return (current->id); 	} 
  else {
	return max ;
}	
		return max_id(current->next);  

} 
// part2 
bool isPalindromWord(char *word) {
    int left = 0;
    int right = strlen(word) - 1;
    
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
} 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "recursion.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader(const char* title) {
    printf("\n==================================================\n");
    printf("                %s", title);
    printf("\n==================================================\n");
}

void printFooter() {
    printf("\n==================================================\n");
    printf("Press Enter to continue...");
    getchar();
}

node* createNode(int id, char* data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->id = id;
    strcpy(newNode->id, data);
    newNode->next = NULL;
    return newNode;
}

node* insertEnd(node* head, int id, char* data) {
    node* newNode = createNode(id, data);
    
    if (head == NULL) {
        return newNode;
    }
    
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    
    node* current = head;
    printf("\nCurrent Linked List:\n");
    while (current != NULL) {
        printf("ID: %d, Data: %s\n", current->id, current->id);
        current = current->next;
    }
    printf("\n");
}

void freeList(node* head) {
    node* current = head;
    node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice, n, result, id;
    node* head = NULL;
    char word[100], data[100];
    
    while (1) {
        clearScreen();
        printHeader("RECURSION FUNCTIONS DEMO");
        
        printf("\nMAIN MENU:\n");
        printf("1. Calculate Factorial (Recursive)\n");
        printf("2. Calculate Fibonacci Number (Recursive)\n");
        printf("3. Add Node to Linked List\n");
        printf("4. Reverse Linked List (Recursive)\n");
        printf("5. Find Maximum ID in Linked List (Recursive)\n");
        printf("6. Check if Word is Palindrome\n");
        printf("7. Display Current Linked List\n");
        printf("8. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1: // Factorial
                clearScreen();
                printHeader("FACTORIAL CALCULATION");
                
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                getchar(); // Consume newline
                
                if (n < 1) {
                    printf("\nError: Please enter a positive integer greater than 0.\n");
                } else {
                    result = rec_factorial(n);
                    printf("\nFactorial of %d = %d\n", n, result);
                }
                
                printFooter();
                break;
                
            case 2: // Fibonacci
                clearScreen();
                printHeader("FIBONACCI CALCULATION");
                
                printf("Enter a position in the Fibonacci sequence (0 or greater): ");
                scanf("%d", &n);
                getchar(); // Consume newline
                
                if (n < 0) {
                    printf("\nError: Please enter a non-negative integer.\n");
                } else {
                    result = rec_fibonacci(n);
                    printf("\nFibonacci number at position %d = %d\n", n, result);
                }
                
                printFooter();
                break;
                
            case 3: // Add node to linked list
                clearScreen();
                printHeader("ADD NODE TO LINKED LIST");
                
                printf("Enter ID (integer): ");
                scanf("%d", &id);
                getchar(); // Consume newline
                
                printf("Enter data (string): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; // Remove newline
                
                head = insertEnd(head, id, data);
                printf("\nNode added successfully!\n");
                
                printFooter();
                break;
                
            case 4: // Reverse linked list
                clearScreen();
                printHeader("REVERSE LINKED LIST (RECURSIVE)");
                
                if (head == NULL) {
                    printf("\nThe list is empty! Nothing to reverse.\n");
                } else {
                    printf("Original list:\n");
                    printList(head);
                    
                    head = reverse_ll(head);
                    
                    printf("Reversed list:\n");
                    printList(head);
                }
                
                printFooter();
                break;
                
            case 5: // Find max ID
                clearScreen();
                printHeader("FIND MAXIMUM ID IN LINKED LIST");
                
                if (head == NULL) {
                    printf("\nThe list is empty! No maximum ID to find.\n");
                } else {
                    result = max_id(head);
                    if (result == -1) {
                        printf("\nNo valid ID found in the list.\n");
                    } else {
                        printf("\nMaximum ID in the list: %d\n", result);
                    }
                }
                
                printFooter();
                break;
                
            case 6: // Check palindrome
                clearScreen();
                printHeader("CHECK IF WORD IS PALINDROME");
                
                printf("Enter a word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                if (isPalindromWord(word)) {
                    printf("\n\"%s\" is a palindrome!\n", word);
                } else {
                    printf("\n\"%s\" is NOT a palindrome.\n", word);
                }
                
                printFooter();
                break;
                
            case 7: // Display list
                clearScreen();
                printHeader("DISPLAY LINKED LIST");
                
                printList(head);
                
                printFooter();
                break;
                
            case 8: // Exit
                clearScreen();
                printHeader("EXITING PROGRAM");
                
                printf("\nFreeing all allocated memory...\n");
                freeList(head);
                printf("Memory freed successfully.\n");
                printf("Thank you for using the Recursion Functions Demo!\n");
                
                return 0;
                
            default:
                clearScreen();
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
                printFooter();
        }
    }
    
    return 0;
}
