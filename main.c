#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL; 


void addStudent() {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent->roll);
    printf("Enter Name: ");
    getchar(); // clear newline
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0';
    printf("Enter Marks: ");
    scanf("%f", &newStudent->marks);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }

    printf("Student added successfully!\n");
}


void displayStudents() {
    if (head == NULL) {
        printf("No students found!\n");
        return;
    }

    struct Student *temp = head;
    printf("\nRoll\tName\tMarks\n");
    printf("----------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}


void searchStudent() {
    if (head == NULL) {
        printf("No students found!\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Student Found: %d %s %.2f\n", temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student with Roll Number %d not found!\n", roll);
}


void deleteStudent() {
    if (head == NULL) {
        printf("No students to delete!\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    struct Student *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll Number %d not found!\n", roll);
        return;
    }

    if (prev == NULL) { // deleting head
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student deleted successfully!\n");
}


void menu() {
    int choice;
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
}


int main() {
    menu();
    return 0;
}
