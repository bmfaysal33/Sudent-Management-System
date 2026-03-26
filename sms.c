#include <stdio.h>
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
   

    FILE *stud = fopen("student.txt", "r");

    struct student s;

    int found = 0;

    if (stud == NULL)
    {
        printf("No student Data Exist");
        return;
    }

    while (fscanf(stud, " %[^,],%d,%f", s.name, &s.roll, &s.cgpa) != EOF)
    {

        if (found == 0)
        {
            printf("\n%-30s %-10s %-10s\n", "Name", "Roll", "CGPA");
            printf("---------------------------------------------------\n");
        }
        printf("%-30s %-10d %-10.2f\n", s.name, s.roll, s.cgpa);
        found = 1;
    }

    fclose(stud);

      if (found == 0)
    {
        printf("The file is empty. No records to show!\n");
    }
    else
    {
        printf("---------------------------------------------------\n");
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

        fprintf(stud, "%s,%d,%.2f\n", s.name, s.roll, s.cgpa);
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
        while (fscanf(stud, " %[^,],%d,%f", s.name, &s.roll, &s.cgpa) != EOF)
        {
            if (s.roll == roll)
            {
                printf("\nName: %s \n Roll: %d \n CGPA: %.2f \n", s.name, s.roll, s.cgpa);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("\nStudent with Roll %d Not found!\n", roll);
        }
        fclose(stud);
    }
};

// Delete a student
void deleteStudent()
{

    FILE *stud, *temp;
    stud = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    struct student s;

    int roll, found = 0;

    if (stud == NULL)
    {

        printf("No file exist. ");
        return;
    }

    printf("Enter roll: ");
    scanf("%d", &roll);

    while (fscanf(stud, " %[^,],%d,%f", s.name, &s.roll, &s.cgpa) != EOF)
    {
        if (roll == s.roll)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%s,%d,%.2f\n", s.name, s.roll, s.cgpa);
        }
    }

    fclose(stud);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
    {
        printf("\nRecord with Roll %d deleted successfully!\n", roll);
    }
    else
    {
        printf("\nRecord with Roll %d not found!\n", roll);
    }
};