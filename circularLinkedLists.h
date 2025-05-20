#ifndef CIRCULARLINKEDLISTS_H
#define CIRCULARLINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedLists.h"

void printCLL(node *head);
node *creat_node_CLL(int id , int severity , char timestemp[] ,char describtion[]);
node *insert_at_beg_CLL(node *head , node *newnode);
node *insert_at_position_CLL (node *head,node *newnode ,int position);
node *insert_at_end_CLL (node *head,node *newnode);
node *delete_first_CLL(node *head);
node *delete_last_CLL(node *head);
node *delete_by_id_CLL(node *head , int id);
node *delete_by_timestemp_CLL(node *head , char timestemp[]);
node *search_by_id_CLL(node *head , int id);
node *search_by_timestemp_CLL(node *head , char timestemp[]);
node *search_by_keyword_CLL(node *head , char keyword[]);
node *sort_by_date_CLL(node *head);
node *sort_by_severity_CLL(node *head);
node *reverse_CLL(node *head);
int count_CLL(node *head);

#endif // CIRCULARLINKEDLISTS_H
