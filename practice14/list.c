#include "list.h"

#define ITERATE_LIMIT(condition, limit) while ((condition), (i < limit))

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

void* saveStudentsToFile(void *list)
{
    LinkedList *llist = (LinkedList *)list;

    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла для записи\n");
        exit(-1);
    }

    Node *current = llist->head;

    int i = 0;
    ITERATE_LIMIT(current != NULL , 10) {
        fprintf(file, "%s %s %c %d %s %d %d %d\n",
                current->value->name,
                current->value->surnames,
                current->value->gender,
                current->value->age,
                current->value->groups,
                current->value->mark_math,
                current->value->mark_chem,
                current->value->mark_physic
        );
        current = current->next;
        i++;
    }
    fclose(file);
}