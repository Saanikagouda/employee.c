#include <stdio.h>
#include <string.h>

#define MAX 100   
struct Employee {
    int id;
    char name[50];
    char dept[30];
    float salary;
};

struct Employee employees[MAX];
int count = 0;  

void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}


void addEmployee() {
    if (count >= MAX) {
        printf("Employee list is full!\n");
        return;
    }

    struct Employee e;
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);  
    printf("Enter Department: ");
    scanf(" %[^\n]", e.dept);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    employees[count++] = e;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
               employees[i].id, employees[i].name,
               employees[i].dept, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Found: ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
                   employees[i].id, employees[i].name,
                   employees[i].dept, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateEmployee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", employees[i].name);
            printf("Enter new Department: ");
            scanf(" %[^\n]", employees[i].dept);
            printf("Enter new Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}