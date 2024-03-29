#include  "stud.h"

void *student_print(void *student)
{
    STUDENT *stud = (STUDENT *)student;

    printf("%s ", stud->name);
    printf("%s ", stud->surnames);
    printf("%c ", stud->gender);
    printf("%d ", stud->age);
    printf("%s ", stud->groups);
    printf("%d ", stud->mark_math);
    printf("%d ", stud->mark_chem);
    printf("%d\n", stud->mark_physic);
    return NULL;
}

void *student_init(void *stud)
{
    STUDENT *student = (STUDENT *)stud;

    strcpy(student->name, names[rand() % 15]);
    strcpy(student->surnames, surnames[rand() % 15]);
    student->gender = 'M';
    student->age = rand() % 5 + 15;
    strcpy(student->groups, groups[rand() % 5]);
    student->mark_math = rand() % 5 + 1;
    student->mark_chem = rand() % 5 + 1;
    student->mark_physic = rand() % 5 + 1;
    student->print = student_print;
};