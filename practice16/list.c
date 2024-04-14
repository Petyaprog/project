#include "list.h"

#define ITERATE_LIMIT(limit, condition) for (int i = 0; i < limit && condition; i++, current = current->next)

void *linkedlist_init()
{
    LinkedList *list = malloc(sizeof(struct LinkedList));

    if (!list) {
        perror("Error");
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void *linkedlist_insert_sorted(void *args)
{
    struct args *arg = (struct args *)args;

    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        perror("Error");
    }

    newNode->value = arg->stud;
    newNode->next = NULL;

    if (arg->list->head == NULL) {
        arg->list->head = newNode;
        arg->list->tail = newNode;
        return NULL;
    }

    Node *current = arg->list->head;

    if (current == NULL || current->value->mark_math < arg->stud->mark_math) {
        newNode->next = arg->list->head;
        arg->list->head = newNode;
    } else {
        while (current->next != NULL && current->next->value->mark_math >= arg->stud->mark_math) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}

void *printTopMathematicsStudents(void *list)
{
    LinkedList *llist = (LinkedList *)list;
    Node *current = llist->head;

    FILE* file = fopen("student.bin", "wb");

    ITERATE_LIMIT(10, current != NULL) {
        current->value->print(current->value);
    }
    fclose(file);
}

//void* printStudents(void *list)
//{
//    LinkedList *llist = (LinkedList *)list;
//    Node *current = llist->head;
//    int i  = 0;
//    while ((current != NULL), (i < 10))
//    {
//        STUDENT *stud = (STUDENT *)current->value;
//        printf("%s ", stud->name);
//        printf("%s ", stud->surnames);
//        printf("%c ", stud->gender);
//        printf("%d ", stud->age);
//        printf("%s ", stud->groups);
//        printf("%d ", stud->mark_math);
//        printf("%d ", stud->mark_chem);
//        printf("%d ", stud->mark_physic);
//        printf("\n");
//
//        current = current->next;
//        i++;
//    }
//}