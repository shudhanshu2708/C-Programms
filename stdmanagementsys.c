#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to hold student information
struct Student {
    int roll_no;
    char name[50];
    float grade;
};

// Array to hold student records and a variable to keep count
struct Student students[MAX];
int count = 0;

// Function declarations
void addStudent();
void displayStudents();
void editStudent();
void deleteStudent();
void searchStudent();

int main() {
    int choice;
    
    do {
        // Display menu
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Menu-based control structure
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add a student
void addStudent() {
    if (count >= MAX) {
        printf("Student list is full!\n");
        return;
    }
    
    struct Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", s.name); // to read string with spaces
    printf("Enter Grade: ");
    scanf("%f", &s.grade);
    
    students[count++] = s;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    printf("\nRoll No\tName\t\tGrade\n");
    printf("-------\t--------\t-----\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].roll_no, students[i].name, students[i].grade);
    }
}

// Function to edit a student's information
void editStudent() {
    int roll, found = 0;
    printf("Enter Roll Number of student to edit: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("Editing Student - %s\n", students[i].name);
            printf("Enter new Name: ");
            scanf(" %[^\n]%*c", students[i].name);
            printf("Enter new Grade: ");
            scanf("%f", &students[i].grade);
            printf("Student record updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

// Function to delete a student
void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll Number of student to delete: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("Student Found!\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Grade: %.2f\n", students[i].grade);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}