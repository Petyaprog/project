#include  "stud.h"

void *studSaveToFile(void *student)
{
    STUDENT *stud = (STUDENT *)student;
    FILE *file = fopen("student.bin", "ab");

    if (file != NULL)
    {
            fwrite(stud->name, sizeof(stud->name), 1, file);
            fwrite(stud->surnames, sizeof(stud->surnames), 1, file);
            fwrite(&stud->gender, sizeof(stud->gender), 1, file);
            fwrite(&stud->age, sizeof(stud->age), 1, file);
            fwrite(stud->groups, sizeof(stud->groups), 1, file);
            fwrite(&stud->mark_math, sizeof(stud->mark_math), 1, file);
            fwrite(&stud->mark_chem, sizeof(stud->mark_chem), 1, file);
            fwrite(&stud->mark_physic, sizeof(stud->mark_physic), 1, file);

        fclose(file);
    }
    else
    {
        printf("Error opening file\n");
    }

    return stud;
};

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
    student->print = studSaveToFile;

    return student;
};

void *studReadFromFile(void *student)
{
    STUDENT *stud = (STUDENT *)student;

    FILE *file = fopen("student.bin", "rb");

    if (file != NULL)
    {
        fread(stud->name, sizeof(stud->name), 1, file);
        fread(stud->surnames, sizeof(stud->surnames), 1, file);
        fread(&stud->gender, sizeof(stud->gender), 1, file);
        fread(&stud->age, sizeof(stud->age), 1, file);
        fread(stud->groups, sizeof(stud->groups), 1, file);
        fread(&stud->mark_math, sizeof(stud->mark_math), 1, file);
        fread(&stud->mark_chem, sizeof(stud->mark_chem), 1, file);
        fread(&stud->mark_physic, sizeof(stud->mark_physic), 1, file);

        fclose(file);
    }
    else
    {
        printf("Error opening file\n");
    }

    return stud;
}