#ifndef LIST_H
#define LIST_H

#include "stud.h"

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;

typedef struct args
{
    STUDENT *stud;
    LinkedList *list;
} args;

void *linkedlist_init();
void *linkedlist_insert_sorted(void *args);
void *printTopMathematicsStudents(void *list);
void* printStudents(void *list);

#endif // LIST_H