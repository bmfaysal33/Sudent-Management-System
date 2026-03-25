#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Functionalities
void allStudentRecord();
void addStudent();
void searchStudent();
void deleteStudent();

// Student

struct student
{
    int roll;
    char name[40];
    float cgpa;
};

int main()
{

    int choice;

    while (1)
    {
        printf("\n\n ====== Student Management System ====== ");
        printf(" \n \n 1. All Student Record \n 2. Add Student  \n 3. Search Student by Roll \n 4. Delete a student \n 5. Exit \n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n-------------------Output-----------------\n\n");

        switch (choice)
        {

        case 1:
            allStudentRecord();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

// All student
void allStudentRecord()
{
    printf("All students Here\n\n");

    FILE *stud = fopen("student.txt", "r");

    if (stud == NULL)
    {
        printf("No student Data Exist");
        return;
    }
    else
    {
        int ch = fgetc(stud);

        while (ch != EOF)
        {
            printf("%c", ch); // printf first cause its already assigned in top
            ch = fgetc(stud);
        }
        fclose(stud);
    }
};

// Add Student
void addStudent()
{
    FILE *stud;
    stud = fopen("student.txt", "a");
    if (stud == NULL)
    {
        printf("Student doesn't exist!!! \n");
        return;
    }
    else
    {

        printf("Student exist.\n\n");

        struct student s;

        printf("Enter Student Name: \n");
        // scanf("%s", s.name);
        // gets(s.name); // Old method , this doesnt take input rather goes to new line.

        scanf(" %[^\n]", s.name);

        // we will use fprintf() rather than this fputs()
        // fputs(s.name, stud);
        // fputs("\n", stud);

        printf("Enter Student Roll: \n");
        scanf("%d", &s.roll); // gets() won't work here cause its a int type

        printf("Enter Student CGPA: \n");
        scanf("%f", &s.cgpa);

        fprintf(stud, "%s %d %.2f\n", s.name, s.roll, s.cgpa);
    }

    printf("Record added successfully!\n");
    fclose(stud);
};

// Search Student
void searchStudent()
{
    FILE *stud = fopen("student.txt", "r");
    struct student s;
    int roll, found = 0;
    printf("Enter Roll: ");
    scanf("%d", &roll);

    if (stud == NULL)
    {
        printf("No Student Data exist, Add student data. \n");
    }
    else
    {
        while (fscanf(stud, "%s %d %f", s.name, &s.roll, &s.cgpa) != EOF)
        {
            if (s.roll == roll)
            {
                printf("Name: %s \n Roll: %d \n CGPA: %.2f", s.name, s.roll, s.cgpa);
                found = 1;
            }
        }

        if (!found)
        {
            printf("\nStudent with Roll %d Not found!\n", roll);
        }
    }
};

// Delete a student
void deleteStudent()
{
    printf("Delete students Here");
};