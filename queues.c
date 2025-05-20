#include "queues.h"
#include "linkedLists.h"

 queue *creatqueue(){
 	queue *newqueue ; 
 	newqueue=(queue *)malloc(sizeof(queue));  
 	newqueue->front=NULL;
 	newqueue->rear=NULL; 
 	return newqueue ; 
 }  
 node* creat_node(int id, int severity, char timestemp[], char describtion[]) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->id = id;
    newnode->severity = severity;
    strcpy(newnode->timestemp, timestemp);
    strcpy(newnode->describtion, describtion);
    newnode->next = NULL;
    return newnode;
}
void enqueueT(queue *q ,node *newnode){
	if(q->front==NULL){
		q->front=newnode; 
		q->rear=newnode; 
	} 
	else {
	q->rear->next=newnode;  
	q->rear=newnode; 
	}
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
  int main() {
    queue *q = NULL;
    int choice, id, severity;
    char timestemp[10], describtion[100];
    
    printf("\n==== Queue Management System ====\n");
    
    while (1) {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Create a new queue\n");
        printf("2. Enqueue a new element\n");
        printf("3. Dequeue an element\n");
        printf("4. Peek (view front element)\n");
        printf("5. Check if queue is empty\n");
        printf("6. Display all elements in queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                // Free existing queue if any
                if (q != NULL) {
                    while (q->front != NULL) {
                        node *temp = q->front;
                        q->front = q->front->next;
                        free(temp);
                    }
                    free(q);
                }
                
                q = creatqueue();
                printf("Queue created successfully.\n");
                break;
                
            case 2:
                if (q == NULL) {
                    printf("Please create a queue first (option 1).\n");
                    break;
                }
                
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
                enqueueT(q, newnode);
                printf("Element enqueued successfully.\n");
                break;
                
            case 3:
                if (q == NULL) {
                    printf("Please create a queue first (option 1).\n");
                    break;
                }
                
                if (is_empty_queue(q)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    node *dequeued = dequeue(q);
                    printf("Element dequeued successfully.\n");
                    
                    // If the queue becomes empty after dequeuing
                    if (q->front == NULL) {
                        q->rear = NULL;
                    }
                }
                break;
                
            case 4:
                if (q == NULL) {
                    printf("Please create a queue first (option 1).\n");
                    break;
                }
                
                node *front = peek_queue(q);
                if (front != NULL) {
                    printf("\n===== Front Element =====\n");
                    printf("ID: %d\n", front->id);
                    printf("Severity: %d\n", front->severity);
                    printf("Timestamp: %s\n", front->timestemp);
                    printf("Description: %s\n", front->describtion);
                } else {
                    printf("Queue is empty. No element to peek.\n");
                }
                break;
                
            case 5:
                if (q == NULL) {
                    printf("Please create a queue first (option 1).\n");
                    break;
                }
                
                if (is_empty_queue(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
                
            case 6:
                if (q == NULL) {
                    printf("Please create a queue first (option 1).\n");
                    break;
                }
                
                if (is_empty_queue(q)) {
                    printf("Queue is empty. No elements to display.\n");
                } else {
                    printf("\n===== Queue Elements (Front to Rear) =====\n");
                    node *current = q->front;
                    int count = 0;
                    
                    while (current != NULL) {
                        printf("\nElement %d:\n", ++count);
                        printf("ID: %d\n", current->id);
                        printf("Severity: %d\n", current->severity);
                        printf("Timestamp: %s\n", current->timestemp);
                        printf("Description: %s\n", current->describtion);
                        current = current->next;
                    }
                    
                    printf("\nTotal elements in queue: %d\n", count);
                }
                break;
                
            case 0:
                printf("\nExiting program. Goodbye!\n");
                
                // Free all allocated memory
                if (q != NULL) {
                    while (q->front != NULL) {
                        node *temp = q->front;
                        q->front = q->front->next;
                        free(temp);
                    }
                    free(q);
                }
                
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
