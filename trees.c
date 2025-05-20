#include "trees.h"
#include "linkedlists.h"

 bool isBST(treenode *root, int min , int max){
if(root==NULL){
	return true ;  
} 
if(root->id<=min ||root->id>=max) 
return false ; 	 
 if (root->id <= min || root->id >= max) {
        return false;}
return isBST(root->left, min, root->id) &&
      isBST(root->right, root->id, max);
} 
treenode *find_bst(treenode *root, int value){
	if(root->id==value){
		return root ;
	} 
	if(value<root->id){
 return find_bst(root->left,value);
 	} 
 	else if(value>root->id){
 		return find_bst(root->right,value);
		 	 }
}
 treenode* insertlog(treenode *root,int id,char *timestamp,char *message,int severity){
if(root==NULL){
   treenode* newNode=(treenode*)malloc(sizeof(treenode)) ;
  newNode->id=id ;
  strcpy(newNode->timestamp,timestamp) ;
  strcpy(newNode->message,message) ;
      newNode->severity=severity ;
    newNode->left=NULL ;
     newNode->right=NULL ;
   return newNode ;
}
     if(id<root->id)
	  root->left=insertlog(root->left,id,timestamp,message,severity) ;
else 
   root->right=insertlog(root->right,id,timestamp,message,severity) ;
return root ;
}
treenode* searchlog(treenode *root,int id){
   if(root==NULL)
   return NULL ;
 if(root->id==id)
   return root ;
 if(id<root->id) 
   return searchlog(root->left,id) ;
else
  return searchlog(root->right,id) ;
}
treenode* findmin(treenode* node){
while(node->left!=NULL) node=node->left ;
return node ;
}
treenode* deletelog(treenode* root,int id){
if(root==NULL)  
   return NULL ;
if(id<root->id)  
  root->left=deletelog(root->left,id) ;
else 
    if(id>root->id)  
root->right=deletelog(root->right,id) ;
else {
if(root->left==NULL){
treenode* tmp=root->right ;
free(root) ;
  return tmp ;
}
else  
   if(root->right==NULL){
  treenode* tmp=root->left ;
  free(root) ;
  return tmp ;
}
     treenode* tmp=findmin(root->right) ;
   root->id=tmp->id ;
   strcpy(root->timestamp,tmp->timestamp) ;
   strcpy(root->message,tmp->message) ;
  root->severity=tmp->severity ;
  root->right=deletelog(root->right,tmp->id) ;
}
       return root ;
}
void inorder(treenode* root){
if(root==NULL) 
return ;
  inorder(root->left) ;
   printf("ID:%d Time:%s Message:%s Severity:%d\n",root->id,root->timestamp,root->message,root->severity) ;
  inorder(root->right) ;
}
void preorder(treenode* root){
   if(root==NULL) 
return ;
printf("ID:%d Time:%s Message:%s Severity:%d\n",root->id,root->timestamp,root->message,root->severity) ;
  preorder(root->left) ;
  preorder(root->right) ;
}
void postorder(treenode* root){  
if(root==NULL)
   return ;
 postorder(root->left) ;
  postorder(root->right) ;
    printf("ID:%d Time:%s Message:%s Severity:%d\n",root->id,root->timestamp,root->message,root->severity) ;
}  
// part2 
int countVowels(const char *str){
    int count = 0;
    int i;
    for (i =0; str[i]; i++){
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}
TTree *createNode(char *word, char *syn, char *ant){
    TTree *newNode = (TTree*)malloc(sizeof(TTree));
    strcpy(newNode->word, word);
    strcpy(newNode->synonym, syn);
    strcpy(newNode->antonym, ant);
    newNode->charCount = strlen(word);
    newNode->vowelCount = countVowels(word);
    newNode->left= newNode->right =NULL;
    return newNode;
}
Stacknode* pop(TStack *stk){
    if (stk==NULL || stk->top==NULL){
    	return NULL;
	}
    Stacknode *temp = stk->top;
    stk->top = stk->top->next;
    temp->next = NULL; 
    return temp;
}
TTree *insertTree(TTree *root, TTree *newNode){
    if (root==NULL){
        return newNode;
    }
    int cmp =strcmp(newNode->word, root->word);
    if (cmp < 0){
        root->left=insertTree(root->left, newNode);
    } 
   else if(cmp > 0){
        root->right=insertTree(root->right, newNode);
    }
    return root;
}
TTree *toTree(TStack *stk){
    TTree *root=NULL;
    Stacknode *temp;
    while ((temp = pop(stk))!= NULL){
        TTree *newNode = createNode(temp->word, temp->synonym, temp->antonym);
        root = insertTree(root, newNode);
        free(temp); 
    }
    return root;
}
TTree *getInfWordTree(TTree *tr, char *word){
    if(tr==NULL){
        return NULL;
    }
    int cmp = strcmp(word, tr->word);
    if(cmp== 0){
        return tr;
    } 
	else if (cmp < 0){
        return getInfWordTree(tr->left, word);
    } 
	else{
        return getInfWordTree(tr->right, word);
    }
}
void pushS(TStack *stk, const char *word, const char *syn, const char *ant){
    Stacknode *newNode =(Stacknode*)malloc(sizeof(Stacknode));
    strcpy(newNode->word, word);
    strcpy(newNode->synonym, syn);
    strcpy(newNode->antonym, ant);
    newNode->charcount = strlen(word);
    newNode->countvow =0; 
    newNode->next=stk->top;
    stk->top=newNode;
}
TTree *findMin(TTree *root){
    while (root && root->left != NULL){
    	root=root->left;
	}
    return root;
}
TTree *deleteWordBST(TTree *tr,char *word){
    if(tr == NULL){
    	return NULL;
	}
    int cmp = strcmp(word, tr->word);
    if(cmp < 0){
        tr->left =deleteWordBST(tr->left, word);
    }
	else if(cmp > 0){
        tr->right = deleteWordBST(tr->right, word);
    }
	else{
        if(tr->left == NULL){
            TTree *rightChild = tr->right;
            free(tr);
            return rightChild;
        } 
		else if(tr->right==NULL){
            TTree *leftChild =tr->left;
            free(tr);
            return leftChild;
        } 
		else{
            TTree *minNode =findMin(tr->right);
            strcpy(tr->word, minNode->word);
            strcpy(tr->synonym, minNode->synonym);
            strcpy(tr->antonym, minNode->antonym);
            tr->charCount= minNode->charCount;
            tr->vowelCount=minNode->vowelCount;
            tr->right = deleteWordBST(tr->right, minNode->word);
        }
    }
    return tr;
}
TTree *TraversalBSTinOrder(TTree *tr){
    if(tr == NULL){
    	return NULL;
	}
    TraversalBSTinOrder(tr->left);
    printf("Word: %s, Synonym: %s, Antonym: %s, CharCount: %d, Vowels: %d\n", tr->word, tr->synonym, tr->antonym, tr->charCount, tr->vowelCount);
    TraversalBSTinOrder(tr->right);
    return tr;
}
TTree *TraversalBSTpostOrder(TTree *tr){
    if (tr ==NULL){
    	return NULL;
	}
    TraversalBSTpostOrder(tr->left);
    TraversalBSTpostOrder(tr->right);
    printf("Word: %s, Synonym: %s, Antonym: %s, CharCount: %d, Vowels: %d\n", tr->word, tr->synonym, tr->antonym, tr->charCount, tr->vowelCount);
    return tr;
}
TTree *LowestCommonAncestor(TTree *tr, char *word1, char *word2){
    if(tr== NULL){
    	  return NULL;
	}
    if(strcmp(word1, tr->word) < 0 && strcmp(word2, tr->word) < 0)
        return LowestCommonAncestor(tr->left, word1, word2);
    if(strcmp(word1, tr->word) > 0 && strcmp(word2, tr->word) > 0)
        return LowestCommonAncestor(tr->right, word1, word2);
    return tr;
}
TTree *inOrderSuccessor(TTree *tr, char *word){
    TTree *successor = NULL;
    TTree *current = tr;
    while(current != NULL){
        int cmp = strcmp(word, current->word);
        if(cmp < 0){
            successor =current;
            current =current->left;
        } else if (cmp > 0){
            current= current->right;
        }
		else{
            if(current->right != NULL){
                TTree *temp = current->right;
                while (temp->left!=NULL){
                    temp = temp->left;
                }
                return temp;
            }
        }
    }
    return successor;
}
TTree *AddWordBST(TTree *root, char *word, char *syne, char *anton) {
    if (root == NULL) {
      TTree *newNode = (TTree *)malloc(sizeof(TTree));
         strcpy(newNode->word, word);
       strcpy(newNode->synonym, syne);
          strcpy(newNode->antonym, anton);
         newNode->charCount = strlen(word);
        newNode->vowelCount = countVowels(word);
              newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (strcmp(word, root->word) < 0)
        root->left = AddWordBST(root->left, word, syne, anton);
    else 
	   if (strcmp(word, root->word) > 0)
        root->right = AddWordBST(root->right, word, syne, anton);
    return root;
}
TTree *fillTree(FILE *f) {
     TTree *root = NULL;
    char word[50], syn[50], ant[50];
       while (fscanf(f, "%s %s %s", word, syn, ant) == 3) {
            root = AddWordBST(root, word, syn, ant);
    } 
    return root;
} 
TTree *UpdateWordBST(TTree *tr, char *word, char *syne, char *anton) {
    TTree *node = getInfWordTree(tr, word);
    if (node) {
        strcpy(node->synonym, syne);
        strcpy(node->antonym, anton);
    }
    return tr;
} 
void preOrder(TTree *tr) {
    if (tr) {
        printf("%s ", tr->word);
        preOrder(tr->left);
        preOrder(tr->right);
    }
} 
int height(TTree *tr) {
     if (!tr) 
	    return 0;
      int lh = height(tr->left);
     int rh = height(tr->right);
    return (lh > rh ? lh : rh) + 1;
}
int size(TTree *tr) {
      if (!tr)
	    return 0;
    return size(tr->left) + size(tr->right) + 1;
}
void HighSizeBST(TTree *tr) {
    printf("Heigth: %d\n", height(tr));
    printf("Size: %d\n", size(tr));
} 
int CountNodesRanges(TTree *root, int l, int h) {
    if (root == NULL) 
	   return 0;
    if (root->charCount >= l && root->charCount <= h) {
        return 1 + CountNodesRanges(root->left, l, h) + CountNodesRanges(root->right, l, h);
    } else 
	  if (root->charCount < l) {
        return CountNodesRanges(root->right, l, h);
    } 
	else {
        return CountNodesRanges(root->left, l, h);
    }
}
bool isMirror(TTree *t1, TTree *t2) {
      if (t1 == NULL && t2 == NULL) {
          return true;}
          if (t1 == NULL || t2 == NULL){
         return false;
       }
       return (strcmp(t1->word, t2->word) == 0)
       && isMirror(t1->left, t2->right)&& isMirror(t1->right, t2->left);
}
bool isSymmetric(TTree *root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}
void displayMainMenu() {
    printf("\n==============================================\n");
    printf("          BINARY SEARCH TREE OPERATIONS          \n");
    printf("==============================================\n");
    printf("1. Log Management Operations\n");
    printf("2. Dictionary Operations\n");
    printf("0. Exit Program\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void displayLogMenu() {
    printf("\n==============================================\n");
    printf("              LOG MANAGEMENT SYSTEM              \n");
    printf("==============================================\n");
    printf("1. Insert new log entry\n");
    printf("2. Search log by ID\n");
    printf("3. Delete log by ID\n");
    printf("4. Display logs (Inorder)\n");
    printf("5. Display logs (Preorder)\n");
    printf("6. Display logs (Postorder)\n");
    printf("0. Return to main menu\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void displayDictionaryMenu() {
    printf("\n==============================================\n");
    printf("              DICTIONARY SYSTEM              \n");
    printf("==============================================\n");
    printf("1. Add new word\n");
    printf("2. Delete word\n");
    printf("3. Search word information\n");
    printf("4. Update word\n");
    printf("5. Display dictionary (Inorder)\n");
    printf("6. Display dictionary (Postorder)\n");
    printf("7. Find lowest common ancestor\n");
    printf("8. Find in-order successor\n");
    printf("9. Display tree height and size\n");
    printf("10. Count nodes in character length range\n");
    printf("11. Check if tree is symmetric\n");
    printf("12. Load dictionary from file\n");
    printf("0. Return to main menu\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void handleLogOperations() {
    treenode* logTree = NULL;
    int choice, id, severity;
    char timestamp[50], message[100];
    treenode* result;

    do {
        displayLogMenu();
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1: // Insert log
                printf("Enter log ID: ");
                scanf("%d", &id);
                getchar(); // Clear the newline
                
                printf("Enter timestamp: ");
                fgets(timestamp, sizeof(timestamp), stdin);
                timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
                
                printf("Enter message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                
                printf("Enter severity (1-5): ");
                scanf("%d", &severity);
                
                logTree = insertlog(logTree, id, timestamp, message, severity);
                printf("Log entry added successfully!\n");
                break;
                
            case 2: // Search log
                printf("Enter log ID to search: ");
                scanf("%d", &id);
                
                result = searchlog(logTree, id);
                if (result) {
                    printf("Log found:\n");
                    printf("ID: %d\nTime: %s\nMessage: %s\nSeverity: %d\n", 
                           result->id, result->timestamp, result->message, result->severity);
                } else {
                    printf("Log with ID %d not found.\n", id);
                }
                break;
                
            case 3: // Delete log
                printf("Enter log ID to delete: ");
                scanf("%d", &id);
                
                logTree = deletelog(logTree, id);
                printf("Log deletion operation completed.\n");
                break;
                
            case 4: // Inorder traversal
                printf("\nDisplaying logs (Inorder):\n");
                if (logTree == NULL) {
                    printf("No logs available.\n");
                } else {
                    inorder(logTree);
                }
                break;
                
            case 5: // Preorder traversal
                printf("\nDisplaying logs (Preorder):\n");
                if (logTree == NULL) {
                    printf("No logs available.\n");
                } else {
                    preorder(logTree);
                }
                break;
                
            case 6: // Postorder traversal
                printf("\nDisplaying logs (Postorder):\n");
                if (logTree == NULL) {
                    printf("No logs available.\n");
                } else {
                    postorder(logTree);
                }
                break;
                
            case 0: // Return to main menu
                printf("Returning to main menu...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    // Free the log tree before returning
    // (A proper cleanup function would be needed here)
}

// Dictionary Operations Functions
void handleDictionaryOperations() {
    TTree* dictionary = NULL;
    int choice, lRange, hRange;
    char word[50], synonym[50], antonym[50], word2[50];
    TTree* result;
    FILE* file;

    do {
        displayDictionaryMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline

        switch(choice) {
            case 1: // Add new word
                printf("Enter word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                printf("Enter synonym: ");
                fgets(synonym, sizeof(synonym), stdin);
                synonym[strcspn(synonym, "\n")] = 0; // Remove newline
                
                printf("Enter antonym: ");
                fgets(antonym, sizeof(antonym), stdin);
                antonym[strcspn(antonym, "\n")] = 0; // Remove newline
                
                dictionary = AddWordBST(dictionary, word, synonym, antonym);
                printf("Word added successfully!\n");
                break;
                
            case 2: // Delete word
                printf("Enter word to delete: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                dictionary = deleteWordBST(dictionary, word);
                printf("Word deletion operation completed.\n");
                break;
                
            case 3: // Search word
                printf("Enter word to search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                result = getInfWordTree(dictionary, word);
                if (result) {
                    printf("Word found:\n");
                    printf("Word: %s\nSynonym: %s\nAntonym: %s\n", 
                           result->word, result->synonym, result->antonym);
                    printf("Character count: %d\nVowel count: %d\n", 
                           result->charCount, result->vowelCount);
                } else {
                    printf("Word '%s' not found in the dictionary.\n", word);
                }
                break;
                
            case 4: // Update word
                printf("Enter word to update: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                printf("Enter new synonym: ");
                fgets(synonym, sizeof(synonym), stdin);
                synonym[strcspn(synonym, "\n")] = 0; // Remove newline
                
                printf("Enter new antonym: ");
                fgets(antonym, sizeof(antonym), stdin);
                antonym[strcspn(antonym, "\n")] = 0; // Remove newline
                
                dictionary = UpdateWordBST(dictionary, word, synonym, antonym);
                printf("Word update operation completed.\n");
                break;
                
            case 5: // Inorder traversal
                printf("\nDisplaying dictionary (Inorder):\n");
                if (dictionary == NULL) {
                    printf("Dictionary is empty.\n");
                } else {
                    TraversalBSTinOrder(dictionary);
                }
                break;
                
            case 6: // Postorder traversal
                printf("\nDisplaying dictionary (Postorder):\n");
                if (dictionary == NULL) {
                    printf("Dictionary is empty.\n");
                } else {
                    TraversalBSTpostOrder(dictionary);
                }
                break;
                
            case 7: // Find LCA
                printf("Enter first word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                printf("Enter second word: ");
                fgets(word2, sizeof(word2), stdin);
                word2[strcspn(word2, "\n")] = 0; // Remove newline
                
                result = LowestCommonAncestor(dictionary, word, word2);
                if (result) {
                    printf("Lowest Common Ancestor: %s\n", result->word);
                } else {
                    printf("Could not find LCA.\n");
                }
                break;
                
            case 8: // Find inorder successor
                printf("Enter word to find successor: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                
                result = inOrderSuccessor(dictionary, word);
                if (result) {
                    printf("In-order successor: %s\n", result->word);
                } else {
                    printf("No in-order successor found.\n");
                }
                break;
                
            case 9: // Display tree height and size
                if (dictionary == NULL) {
                    printf("Dictionary is empty.\n");
                } else {
                    HighSizeBST(dictionary);
                }
                break;
                
            case 10: // Count nodes in range
                printf("Enter minimum character length: ");
                scanf("%d", &lRange);
                printf("Enter maximum character length: ");
                scanf("%d", &hRange);
                
                printf("Number of words with length between %d and %d: %d\n", 
                       lRange, hRange, CountNodesRanges(dictionary, lRange, hRange));
                break;
                
            case 11: // Check if symmetric
                if (isSymmetric(dictionary)) {
                    printf("The dictionary tree is symmetric.\n");
                } else {
                    printf("The dictionary tree is not symmetric.\n");
                }
                break;
                
            case 12: // Load dictionary from file
                printf("Enter filename to load dictionary from: ");
                char filename[100];
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                
                file = fopen(filename, "r");
                if (file) {
                    dictionary = fillTree(file);
                    fclose(file);
                    printf("Dictionary loaded successfully!\n");
                } else {
                    printf("Error opening file: %s\n", filename);
                }
                break;
                
            case 0: // Return to main menu
                printf("Returning to main menu...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    // Free the dictionary tree before returning
    // (A proper cleanup function would be needed here)
}

int main() {
    int choice;
    
    printf("Welcome to Binary Search Tree Operations Demo\n");
    
    do {
        displayMainMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                handleLogOperations();
                break;
                
            case 2:
                handleDictionaryOperations();
                break;
                
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
