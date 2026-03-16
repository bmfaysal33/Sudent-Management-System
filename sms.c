#include <stdio.h>
#include <conio.h>

// Functionalities
void allStudentRecord();
void addStudent();
void searchStudent();
void delete();

int main()
{

    int choice;

    printf("\n\n\t \t ====== Student Management System ====== ");
    printf(" \n \n \t\t\t 1. All Student Record \n \t\t\t 2. Add Student  \n \t\t\t 3. Search Student by Roll \n \t\t\t 4. Delete a student \n \t\t\t 5. Exit \n\n");
    printf("\t\t-----------------------------------------\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);
    printf("\n\n");


    switch(choice){

        case 1: allStudentRecord(); break;
        case 2: addStudent(); break;
        case 3: searchStudent(); break;
        case 4: delete(); break;
        case 5: exit(0); break;
        default: printf("Invalid choice!\n");

    }

    return 0;
}