#include "../include/CollegeManagementSystem.h"
#include <iostream>
#include <limits>
#include <stdexcept>
CollegeManagementSystem::CollegeManagementSystem()
     :attendanceCount(0),
     operationTop(-1) {
      
    for (int index = 0; index < MAX_STUDENTS; ++index) {
        attendanceRecords[index] = nullptr;
    }
}
CollegeManagementSystem::~CollegeManagementSystem() {
    clearAttendanceRecords();
}
void CollegeManagementSystem::pushOperation(const std::string& operation) {
    if (operationTop >= MAX_OPERATIONS - 1) {
        throw std::overflow_error("Operation stack is full.");
    }

    ++operationTop;
    operationStack[operationTop] = operation;
}
void CollegeManagementSystem::displayRecentOperations() const {
    if (operationTop == -1) {
        std::cout << "No recent operations.\n";
        return;
    }

    std::cout << "\n========== RECENT OPERATIONS ==========\n";

    for (int index = operationTop; index >= 0; --index) {
        std::cout << operationStack[index] << '\n';
    }
}
int CollegeManagementSystem::findAttendanceRecord(int studentId) const {
    for (int index = 0; index < attendanceCount; ++index) {
        if (attendanceRecords[index] != nullptr &&
            attendanceRecords[index]->getStudentId() == studentId) {
            return index;
        }
    }

    return -1;
}
void CollegeManagementSystem::clearAttendanceRecords() {
    for (int index = 0; index < attendanceCount; ++index) {
        delete attendanceRecords[index];
        attendanceRecords[index] = nullptr;
    }

    attendanceCount = 0;
}

void CollegeManagementSystem::studentMenu() {
    int choice;

    do {
        std::cout << "\n========================================\n";
        std::cout << "         STUDENT MANAGEMENT\n";
        std::cout << "========================================\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Delete Student\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        try {
            switch (choice) {

                case 1: {
                    int id;
                    std::string name;
                    std::string email;
                    std::string course;
                    int semester;

                    std::cout << "Enter Student ID: ";
                    std::cin >> id;

                    if (id <= 0) {
                        throw std::invalid_argument(
                            "Student ID must be positive."
                        );
                    }

                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'
                    );

                    std::cout << "Enter Student Name: ";
                    std::getline(std::cin, name);

                    std::cout << "Enter Email: ";
                    std::getline(std::cin, email);

                    std::cout << "Enter Course: ";
                    std::getline(std::cin, course);

                    std::cout << "Enter Semester: ";
                    std::cin >> semester;

                    if (semester <= 0) {
                        throw std::invalid_argument(
                            "Semester must be positive."
                        );
                    }

                    Student student(
                        id,
                        name,
                        email,
                        course,
                        semester
                    );

                    studentList.addStudent(student);

pushOperation(
    "Added Student with ID " + std::to_string(id)
);

std::cout << "\nStudent added successfully.\n";
                    break;
                }

                case 2:
                    std::cout << "\n========== STUDENT RECORDS ==========\n";
                    studentList.displayStudents();
                    break;

                case 3: {
                    int id;

                    std::cout << "Enter Student ID to search: ";
                    std::cin >> id;

                    if (studentList.searchStudent(id)) {
                        std::cout << "Student found.\n";
                    } else {
                        std::cout << "Student not found.\n";
                    }

                    break;
                }

                case 4: {
                    int id;

                    std::cout << "Enter Student ID to delete: ";
                    std::cin >> id;

                    if (studentList.deleteStudent(id)) {

    pushOperation(
        "Deleted Student with ID " + std::to_string(id)
    );

    std::cout << "Student deleted successfully.\n";
}
                     else {
                        std::cout << "Student not found.\n";
                    }

                    break;
                }

                case 5:
                    std::cout << "Returning to Main Menu...\n";
                    break;

                default:
                    throw std::invalid_argument(
                        "Invalid choice. Please select 1 to 5."
                    );
            }
        }
        catch (const std::invalid_argument& error) {
            std::cout << "\nError: " << error.what() << '\n';
        }

    } while (choice != 5);
}

void CollegeManagementSystem::teacherMenu() {
    int choice;

    do {
        std::cout << "\n========================================\n";
        std::cout << "         TEACHER MANAGEMENT\n";
        std::cout << "========================================\n";
        std::cout << "1. Add Teacher\n";
        std::cout << "2. Display Teachers\n";
        std::cout << "3. Search Teacher\n";
        std::cout << "4. Delete Teacher\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        try {
            switch (choice) {

                case 1: {
                    int id;
                    std::string name;
                    std::string email;
                    std::string department;
                    std::string specialization;

                    std::cout << "Enter Teacher ID: ";
                    std::cin >> id;

                    if (id <= 0) {
                        throw std::invalid_argument(
                            "Teacher ID must be positive."
                        );
                    }

                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'
                    );

                    std::cout << "Enter Teacher Name: ";
                    std::getline(std::cin, name);

                    std::cout << "Enter Email: ";
                    std::getline(std::cin, email);

                    std::cout << "Enter Department: ";
                    std::getline(std::cin, department);

                    std::cout << "Enter Specialization: ";
                    std::getline(std::cin, specialization);

                    Teacher teacher(
                        id,
                        name,
                        email,
                        department,
                        specialization
                    );

                    teacherList.addTeacher(teacher);

                    std::cout << "\nTeacher added successfully.\n";
                    break;
                }

                case 2:
                    std::cout << "\n========== TEACHER RECORDS ==========\n";
                    teacherList.displayTeachers();
                    break;

                case 3: {
                    int id;

                    std::cout << "Enter Teacher ID to search: ";
                    std::cin >> id;

                    if (teacherList.searchTeacher(id)) {
                        std::cout << "Teacher found.\n";
                    } else {
                        std::cout << "Teacher not found.\n";
                    }

                    break;
                }

                case 4: {
                    int id;

                    std::cout << "Enter Teacher ID to delete: ";
                    std::cin >> id;

                    if (teacherList.deleteTeacher(id)) {
                        std::cout << "Teacher deleted successfully.\n";
                    } else {
                        std::cout << "Teacher not found.\n";
                    }

                    break;
                }

                case 5:
                    std::cout << "Returning to Main Menu...\n";
                    break;

                default:
                    throw std::invalid_argument(
                        "Invalid choice. Please select 1 to 5."
                    );
            }
        }
        catch (const std::invalid_argument& error) {
            std::cout << "\nError: " << error.what() << '\n';
        }

    } while (choice != 5);
}

void CollegeManagementSystem::courseMenu() {
    int choice;

    do {
        std::cout << "\n========================================\n";
        std::cout << "          COURSE MANAGEMENT\n";
        std::cout << "========================================\n";
        std::cout << "1. Add Course\n";
        std::cout << "2. Display Courses\n";
        std::cout << "3. Search Course\n";
        std::cout << "4. Delete Course\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        try {
            switch (choice) {

                case 1: {
                    int courseId;
                    std::string courseName;
                    int credits;

                    std::cout << "Enter Course ID: ";
                    std::cin >> courseId;

                    if (courseId <= 0) {
                        throw std::invalid_argument(
                            "Course ID must be positive."
                        );
                    }

                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'
                    );

                    std::cout << "Enter Course Name: ";
                    std::getline(std::cin, courseName);

                    if (courseName.empty()) {
                        throw std::invalid_argument(
                            "Course name cannot be empty."
                        );
                    }

                    std::cout << "Enter Credits: ";
                    std::cin >> credits;

                    if (credits <= 0) {
                        throw std::invalid_argument(
                            "Credits must be positive."
                        );
                    }

                    Course course(
                        courseId,
                        courseName,
                        credits
                    );

                    courseList.addCourse(course);

                    std::cout << "\nCourse added successfully.\n";
                    break;
                }

                case 2:
                    std::cout << "\n========== COURSE RECORDS ==========\n";
                    courseList.displayCourses();
                    break;

                case 3: {
                    int courseId;

                    std::cout << "Enter Course ID to search: ";
                    std::cin >> courseId;

                    if (courseList.searchCourse(courseId)) {
                        std::cout << "Course found.\n";
                    } else {
                        std::cout << "Course not found.\n";
                    }

                    break;
                }

                case 4: {
                    int courseId;

                    std::cout << "Enter Course ID to delete: ";
                    std::cin >> courseId;

                    if (courseList.deleteCourse(courseId)) {
                        std::cout << "Course deleted successfully.\n";
                    } else {
                        std::cout << "Course not found.\n";
                    }

                    break;
                }

                case 5:
                    std::cout << "Returning to Main Menu...\n";
                    break;

                default:
                    throw std::invalid_argument(
                        "Invalid choice. Please select 1 to 5."
                    );
            }
        }
        catch (const std::invalid_argument& error) {
            std::cout << "\nError: " << error.what() << '\n';
        }

    } while (choice != 5);
}

void CollegeManagementSystem::attendanceMenu() {
    int choice;

    do {
        std::cout << "\n========================================\n";
        std::cout << "        ATTENDANCE MANAGEMENT\n";
        std::cout << "========================================\n";
        std::cout << "1. Mark Present\n";
        std::cout << "2. Mark Absent\n";
        std::cout << "3. View Attendance\n";
        std::cout << "4. Back to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        try {
            switch (choice) {

                case 1:
                case 2: {
                    int studentId;

                    std::cout << "Enter Student ID: ";
                    std::cin >> studentId;

                    if (studentId <= 0) {
                        throw std::invalid_argument(
                            "Student ID must be positive."
                        );
                    }

                    int recordIndex = findAttendanceRecord(studentId);

                    if (recordIndex == -1) {

                        if (attendanceCount >= MAX_STUDENTS) {
                            throw std::out_of_range(
                                "Maximum attendance record limit reached."
                            );
                        }

                        attendanceRecords[attendanceCount] =
                            new Attendance(studentId);

                        recordIndex = attendanceCount;
                        ++attendanceCount;
                    }

                    if (choice == 1) {
                        attendanceRecords[recordIndex]->markPresent();
                        std::cout << "Attendance marked: Present.\n";
                    } else {
                        attendanceRecords[recordIndex]->markAbsent();
                        std::cout << "Attendance marked: Absent.\n";
                    }

                    break;
                }

                case 3: {
                    int studentId;

                    std::cout << "Enter Student ID: ";
                    std::cin >> studentId;

                    int recordIndex = findAttendanceRecord(studentId);

                    if (recordIndex == -1) {
                        std::cout << "No attendance record found.\n";
                    } else {
                        std::cout << "\n========== ATTENDANCE ==========\n";
                        attendanceRecords[recordIndex]->display();
                    }

                    break;
                }

                case 4:
                    std::cout << "Returning to Main Menu...\n";
                    break;

                default:
                    throw std::invalid_argument(
                        "Invalid choice. Please select 1 to 4."
                    );
            }
        }
        catch (const std::exception& error) {
            std::cout << "\nError: " << error.what() << '\n';
        }

    } while (choice != 4);
}

void CollegeManagementSystem::run() {
    int choice;

    do {
        std::cout << "\n========================================\n";
        std::cout << "      COLLEGE MANAGEMENT SYSTEM\n";
        std::cout << "========================================\n";
        std::cout << "1. Student Management\n";
        std::cout << "2. Teacher Management\n";
        std::cout << "3. Course Management\n";
        std::cout << "4. Attendance Management\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                studentMenu();
                break;

            case 2:
                teacherMenu();
                break;

            case 3:
                courseMenu();
                break;

            case 4:
                attendanceMenu();
                break;

            case 5:
                std::cout << "Exiting the system...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
    
                    
                   
}
