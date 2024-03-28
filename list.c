#include "list.h"

#define ITERATE_LIMIT(limit, condition) for (int i = 0; i < limit && condition; i++, current = current->next)

void *linkedlist_init()
{
    LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL; 
    return list;
}

void *linkedlist_insert_sorted(void *args)
{
    struct args *arg = (struct args *)args;

    Node *newNode = malloc(sizeof(Node));
    newNode->value = arg->stud;
    newNode->next = NULL;

    if (arg->list->head == NULL)
    {
        arg->list->head = newNode;
        arg->list->tail = newNode;
        return NULL;
    }

    Node *current = arg->list->head;

    if (current == NULL || current->value->mark_math < arg->stud->mark_math)
    {
        newNode->next = arg->list->head;
        arg->list->head = newNode;
    }
    else
    {
        while (current->next != NULL && current->next->value->mark_math >= arg->stud->mark_math)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void *printTopMathematicsStudents(void *list)
{
    LinkedList *llist = (LinkedList *)list;

    printf("\nТоп-10 учеников по математике:\n\n");
    struct Node *current = llist->head;
    ITERATE_LIMIT(10, current != NULL)
    {
        current->value->print(current->value);
    }
}