#include "list.h"

#define countStud for (int i = 0; i < countStudent; i++)

int main()
{
    srand(time(NULL));
    LinkedList *list = linkedlist_init();

    int countStudent;

    printf("Введите количество студентов: ");

    scanf("%d", &countStudent);
    STUDENT *student;
    countStud
    {
        STUDENT *stud = malloc(sizeof(STUDENT));
//        STUDENT *student = malloc(sizeof(STUDENT));
        student_init(stud);
//        student_print(student);
        args *arg = malloc(sizeof(args));
        arg->stud = stud;
        arg->list = list;
        linkedlist_insert_sorted(arg);
    }

    printTopMathematicsStudents(list);
    studReadFromFile(student);
    return 0;
}