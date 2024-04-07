#ifndef STUD_H
#define STUD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char names[15][20] = {
        "Ярослав",
        "Коля",
        "Дмитрий",
        "Артём",
        "Степан",
        "Павел",
        "Аким",
        "Василий",
        "Евгений",
        "Василий",
        "Петр",
        "Иван",
        "Александр",
        "Дмитрий",
        "Сергей",
};

static char surnames[15][20] = {
        "Фуфаев",
        "Смирнов",
        "Нагаев",
        "Дубов",
        "Семенов",
        "Сидоров",
        "Акимов",
        "Пронин",
        "Овдиенко",
        "Бабичев",
        "Кузнецов",
        "Петров",
        "Петренко",
        "Ильенко",
        "Макаров",
};

static char groups[15][20] = {
        "ПКС-105",
        "ИСП-403",
        "СИС-207",
        "ИСП-107",
        "ИСП-211",
        "ПКС-204",
        "ИСП-204",
        "СИС-204",
        "ИСП-205",
        "ИСП-206",
        "ИСП-106",
        "ИСП-404",
        "ПКС-106",
        "ПКС-303",
        "СИС-201"
};

typedef struct Student
{
    char name[20];
    char surnames[20];
    char gender[1];
    int age;
    char groups[20];
    int mark_math;
    int mark_chem;
    int mark_physic;
    void *(*print)(void *);
} STUDENT;

typedef struct Node
{
    STUDENT *value;
    struct Node *next;
} Node;

void *studSaveToFile(void *student);
void *student_init(void *stud);
void *studReadFromFile(void *student);

#endif // !STUD_H