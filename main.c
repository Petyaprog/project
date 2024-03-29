#include "list.h"

#define countStud for (int i = 0; i < countStudent; i++)

int main()
{
    srand(time(NULL));
    LinkedList *list = linkedlist_init();

    int countStudent;

    printf("Введите количествdfbhо студентов: ");
    scanf("%d", &countStudent);

    countStud
    {
        STUDENT *stud = malloc(sizeof(STUDENT));
        student_init(stud);
        args *arg = malloc(sizeof(args));
        arg->stud = stud;
        arg->list = list;
        linkedlist_insert_sorted(arg);
    }
    printTopMathematicsStudents(list);

    return 0;
}