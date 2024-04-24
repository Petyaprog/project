#include "list.h"

void *linkedlist_init()
{
    LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void* linkedlist_insert_sorted(void *args)
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
    return NULL;
}

void* list_load(void *list)
{
    LinkedList *llist = (LinkedList *)list;

    FILE *file = fopen("students.txt", "w");

    Node *current = llist->head;

    int i = 0;
    while ((current != NULL), (i < 10))
     {
        student_load (current);
        current = current->next;
        i++;
    }
    fclose(file);
    return NULL;
}

void* student_read(void *list)
{
    LinkedList *llist = (LinkedList *)list;

    FILE *file = fopen("students.txt", "r");

    Node *current = llist->head;

    int i = 0;
    while ((current != NULL), (i < 10))
    {
        studReadFromFile(file);
        current = current->next;
        i++;
    }

    fclose(file);
    return NULL;
}