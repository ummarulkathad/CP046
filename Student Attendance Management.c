#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[50];
  int roll_number;
  char course[50];
  int attendance; // 1 for present, 0 for absent
};

void add_student(struct student *students, int *num_students) {
  // Get the student details from the user.
  printf("Enter the student name: ");
  scanf("%s", students[*num_students].name);
  printf("Enter the student roll number: ");
  scanf("%d", &students[*num_students].roll_number);
  printf("Enter the student course: ");
  scanf("%s", students[*num_students].course);
  students[*num_students].attendance = 0; // 0 for absent by default

  // Increment the number of students.
  (*num_students)++;
}

void remove_student(struct student *students, int *num_students, int roll_number) {
  // Find the student with the given roll number.
  int i;
  for (i = 0; i < *num_students; i++) {
    if (students[i].roll_number == roll_number) {
      break;
    }
  }

  // If the student is found, remove it from the array.
  if (i < *num_students) {
    for (; i < *num_students - 1; i++) {
      students[i] = students[i + 1];
    }
    (*num_students)--;
  }
}

void mark_attendance(struct student *students, int *num_students, int roll_number, int is_present) {
  // Find the student with the given roll number.
  int i;
  for (i = 0; i < *num_students; i++) {
    if (students[i].roll_number == roll_number) {
      break;
    }
  }

  // If the student is found, mark their attendance.
  if (i < *num_students) {
    students[i].attendance = is_present;
  }
}

void print_report(struct student *students, int num_students) {
  // Print the attendance report for all students.
  int i;
  for (i = 0; i < num_students; i++) {
    printf("Student name: %s\n", students[i].name);
    printf("Student roll number: %d\n", students[i].roll_number);
    printf("Student course: %s\n", students[i].course);
    printf("Student attendance: %d\n\n", students[i].attendance);
  }
}

int main() {
  // Initialize the student array and the number of students.
  struct student students[100];
  int num_students = 0;

  // The main menu.
  int choice;
  while (1) {
    printf("1. Add student\n");
    printf("2. Remove student\n");
    printf("3. Mark attendance\n");
    printf("4. Print report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_student(students, &num_students);
        break;
      case 2:
        printf("Enter the student roll number to remove: ");
        int roll_number;
        scanf("%d", &roll_number);
        remove_student(students, &num_students, roll_number);
        break;
      case 3:
        printf("Enter the student roll number to mark attendance: ");
        scanf("%d", &roll_number);
        printf("Is the student present (1 for yes, 0 for no)? ");
        int is_present;
        scanf("%d", &is_present);
        mark_attendance(students, &num_students, roll_number, is_present);
        break;
[11:40 am, 29/08/2023] Kathad: #include <stdio.h>
#include <stdlib.h>

struct student {
  char name[50];
  int roll_number;
  char course[50];
  int attendance; // 1 for present, 0 for absent
};

void add_student(struct student *students, int *num_students) {
  // Get the student details from the user.
  printf("Enter the student name: ");
  scanf("%s", students[*num_students].name);
  printf("Enter the student roll number: ");
  scanf("%d", &students[*num_students].roll_number);
  printf("Enter the student course: ");
  scanf("%s", students[*num_students].course);
  students[*num_students].attendance = 0; // 0 for absent by default

  // Increment the number of students.
  (*num_students)++;
}

void remove_student(struct student *students, int *num_students, int roll_number) {
  // Find the student with the given roll number.
  int i;
  for (i = 0; i < *num_students; i++) {
    if (students[i].roll_number == roll_number) {
      break;
    }
  }

  // If the student is found, remove it from the array.
  if (i < *num_students) {
    for (; i < *num_students - 1; i++) {
      students[i] = students[i + 1];
    }
    (*num_students)--;
  }
}

void mark_attendance(struct student *students, int *num_students, int roll_number, int is_present) {
  // Find the student with the given roll number.
  int i;
  for (i = 0; i < *num_students; i++) {
    if (students[i].roll_number == roll_number) {
      break;
    }
  }

  // If the student is found, mark their attendance.
  if (i < *num_students) {
    students[i].attendance = is_present;
  }
}

void print_report(struct student *students, int num_students) {
  // Print the attendance report for all students.
  int i;
  for (i = 0; i < num_students; i++) {
    printf("Student name: %s\n", students[i].name);
    printf("Student roll number: %d\n", students[i].roll_number);
    printf("Student course: %s\n", students[i].course);
    printf("Student attendance: %d\n\n", students[i].attendance);
  }
}

int main() {
  // Initialize the student array and the number of students.
  struct student students[100];
  int num_students = 0;

  // The main menu.
  int choice;
  while (1) {
    printf("1. Add student\n");
    printf("2. Remove student\n");
    printf("3. Mark attendance\n");
    printf("4. Print report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_student(students, &num_students);
        break;
      case 2:
        printf("Enter the student roll number to remove: ");
        int roll_number;
        scanf("%d", &roll_number);
        remove_student(students, &num_students, roll_number);
        break;
      case 3:
        printf("Enter the student roll number to mark attendance: ");
        scanf("%d", &roll_number);
        printf("Is the student present (1 for yes, 0 for no)? ");
        int is_present;
        scanf("%d", &is_present);
        mark_attendance(students, &num_students, roll_number, is_present);
        break;
              case 4:
        print_report(students, num_students);
        break;
      case 5:
        // Exit the program.
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}
