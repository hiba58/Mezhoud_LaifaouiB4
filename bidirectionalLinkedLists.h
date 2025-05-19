#ifndef BIDIRECTIONALLINKEDLISTS_H
#define BIDIRECTIONALLINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 typedef struct bnode{
int id ;
int severity ;
char timestemp[50] ;
char describtion[100] ;

struct bnode* next ;
struct bnode* prev ;
} bnode ;
bnode* insertend(bnode* head, int id, int severity, char* time, char* desc);
bnode* insertbegin(bnode* head, int id, int severity, char* time, char* desc);
bnode* deletebyiD(bnode* head, int id);
void forward(bnode* head);
void backward(bnode* tail);
bnode* mergelists(bnode* head1, bnode* head2);

#endif // BIDIRECTIONALLINKEDLISTS_H
