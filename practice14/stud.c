#include  "stud.h"

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

    return NULL;
};

