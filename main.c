#include "list.h"

#define countStud for (int i = 0; i < countStudent; i++)

int main()
{
    srand(time(NULL));
    LinkedList *list = linkedlist_init();

    int countStudent;

<<<<<<< HEAD
    printf("Введите колипацушпаущчествdfbhо студентов: ");
=======
    printf("Введите количljdnflkaklaество студентов: ");
>>>>>>> d690fa770c09ef0b421b38801b4d77eaa424e3cb
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