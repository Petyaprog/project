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
}

void *student_load (Node *current)
{
    FILE *file = fopen("students.txt", "a");

    fprintf(file,"%s ", current->value->name);
    fprintf(file,"%s ", current->value->surnames);
    fprintf(file,"%c ", current->value->gender);
    fprintf(file,"%d ", current->value->age);
    fprintf(file,"%s ", current->value->groups);
    fprintf(file,"%d ", current->value->mark_math);
    fprintf(file,"%d ", current->value->mark_chem);
    fprintf(file,"%d ", current->value->mark_physic);
    fprintf(file,"\n");

    return current;
}

void *studReadFromFile(FILE *file)
{
    STUDENT *stud = malloc(sizeof(STUDENT));

    fscanf(file,"%s ", stud->name);
    fscanf(file,"%s ", stud->surnames);
    fscanf(file,"%c ", &stud->gender);
    fscanf(file,"%d ", &stud->age);
    fscanf(file,"%s ", stud->groups);
    fscanf(file,"%d ", &stud->mark_math);
    fscanf(file,"%d ", &stud->mark_chem);
    fscanf(file,"%d ", &stud->mark_physic);

    return stud;
}