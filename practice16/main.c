#include "list.h"

#define countStud for (int i = 0; i < countStudent; i++)

int main()
{
    srand(time(NULL));
    LinkedList *list = linkedlist_init();

    int countStudent;

    printf("Введите количество студентов: ");

    scanf("%d", &countStudent);

    countStud
    {
        STUDENT *stud = malloc(sizeof(STUDENT));
        if (!stud) {
            perror("Error");
        }

        student_init(stud);

        args *arg = malloc(sizeof(args));
        if (!arg) {
            perror("Error");
        }

        arg->stud = stud;
        arg->list = list;
        linkedlist_insert_sorted(arg);
    }

    printTopMathematicsStudents(list);
    STUDENT *stud = malloc(sizeof(STUDENT));
    studReadFromFile(stud);

    return 0;
}