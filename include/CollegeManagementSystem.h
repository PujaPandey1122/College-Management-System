#ifndef COLLEGE_MANAGEMENT_SYSTEM_H
#define COLLEGE_MANAGEMENT_SYSTEM_H

#include "StudentList.h"
#include "TeacherList.h"
#include "CourseList.h"
#include "Attendance.h"

#include <string>

class CollegeManagementSystem {
private:
    // Maximum number of students with attendance records
    static const int MAX_STUDENTS = 100;

    // Maximum number of operations stored in the stack
    static const int MAX_OPERATIONS = 100;

    // Main data structures
    StudentList studentList;
    TeacherList teacherList;
    CourseList courseList;

    // Attendance records
    Attendance* attendanceRecords[MAX_STUDENTS];
    int attendanceCount;

    // Stack for recent operations
    std::string operationStack[MAX_OPERATIONS];
    int operationTop;

    // Menus
    void studentMenu();
    void teacherMenu();
    void courseMenu();
    void attendanceMenu();
    void stackMenu();

    // Attendance helper functions
    int findAttendanceRecord(int studentId) const;
    void clearAttendanceRecords();

    // Stack functions
    void pushOperation(const std::string& operation);
    void displayRecentOperations() const;

public:
    CollegeManagementSystem();
    ~CollegeManagementSystem();

    void run();
};

#endif
