<html>
<html>
<head>
</head>
<body>
    <h1>Student Attendance Management System</h1>
    <p>This C program is designed to manage a list of students and their attendance records. It provides the following functionalities:</p>
    <ol>
        <li><strong>Add Student:</strong> Allows you to add a new student to the list with their name, roll number, and course.</li>
        <li><strong>Remove Student:</strong> Removes a student from the list based on their roll number.</li>
        <li><strong>Mark Attendance:</strong> Marks attendance for a student based on their roll number (1 for present, 0 for absent).</li>
        <li><strong>Print Report:</strong> Displays a report of all students including their name, roll number, course, and attendance status.</li>
        <li><strong>Exit:</strong> Exits the program.</li>
    </ol>

    <h2>How to Use</h2>
    <ol>
        <li>Compile the program using a C compiler (e.g., GCC).</li>
        <li>Run the compiled executable.</li>
        <li>Choose options from the menu to perform actions on the student list.</li>
        <li>Follow the on-screen prompts to input data or make selections.</li>
    </ol>

    <h2>Data Structure</h2>
    <p>The program uses a struct <code>student</code> to store student information, including name, roll number, course, and attendance status (1 for present, 0 for absent). Students are stored in an array.</p>

    <h2>Sample Usage</h2>
    <pre>
1. Add student
2. Remove student
3. Mark attendance
4. Print report
5. Exit
Enter your choice: 1

Enter the student name: John Doe
Enter the student roll number: 101
Enter the student course: Computer Science

1. Add student
2. Remove student
3. Mark attendance
4. Print report
5. Exit
Enter your choice: 3

Enter the student roll number to mark attendance: 101
Is the student present (1 for yes, 0 for no)? 1

1. Add student
2. Remove student
3. Mark attendance
4. Print report
5. Exit
Enter your choice: 4

Student name: John Doe
Student roll number: 101
Student course: Computer Science
Student attendance: 1
    

</pre>
</body>
</html>
