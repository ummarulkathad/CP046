#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Include the time header

struct student {
  char name[50];
  int roll_number;
  char course[50];
  int attendance; // 1 for present, 0 for absent
  char attendance_date[20]; // Store attendance date and time
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
  strcpy(students[*num_students].attendance_date, ""); // Initialize attendance_date

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
  } else {
    printf("Student with roll number %d not found.\n", roll_number);
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

  // If the student is found, mark their attendance and set the date.
  if (i < *num_students) {
    students[i].attendance = is_present;

    // Get the current date and time.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Store the date in the student's record.
    sprintf(students[i].attendance_date, "%d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  } else {
    printf("Student with roll number %d not found.\n", roll_number);
  }
}

void print_report(struct student *students, int num_students) {
  // Print the attendance report in a table format.
  printf("| %-20s | %-12s | %-20s | %-10s | %-20s |\n", "Name", "Roll Number", "Course", "Attendance", "Attendance Date");
  printf("+----------------------+--------------+----------------------+------------+----------------------+\n");

  for (int i = 0; i < num_students; i++) {
    printf("| %-20s | %-12d | %-20s | %-10d | %-20s |\n", students[i].name, students[i].roll_number, students[i].course, students[i].attendance, students[i].attendance_date);
  }
  printf("+----------------------+--------------+----------------------+------------+----------------------+\n");
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
