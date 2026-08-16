#include "../include/Attendance.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Attendance::Attendance(int studentId)
    : studentId(studentId),
      totalClasses(0) {

    if (studentId <= 0) {
        throw std::invalid_argument("Student ID must be positive.");
    }

    for (int index = 0; index < MAX_CLASSES; ++index) {
        attendanceRecords[index] = false;
    }
}

void Attendance::markPresent() {
    if (totalClasses >= MAX_CLASSES) {
        throw std::out_of_range(
            "Maximum class limit reached."
        );
    }

    attendanceRecords[totalClasses] = true;
    ++totalClasses;
}

void Attendance::markAbsent() {
    if (totalClasses >= MAX_CLASSES) {
        throw std::out_of_range(
            "Maximum class limit reached."
        );
    }

    attendanceRecords[totalClasses] = false;
    ++totalClasses;
}

double Attendance::getPercentage() const {
    if (totalClasses == 0) {
        return 0.0;
    }

    int attendedClasses = 0;

    for (int index = 0; index < totalClasses; ++index) {
        if (attendanceRecords[index]) {
            ++attendedClasses;
        }
    }

    return (static_cast<double>(attendedClasses) / totalClasses) * 100.0;
}

void Attendance::display() const {
    std::cout << "Student ID: " << studentId << '\n';
    std::cout << "Total Classes: " << totalClasses << '\n';

    std::cout << "Attendance Records: ";

    if (totalClasses == 0) {
        std::cout << "No records available.\n";
    } else {
        for (int index = 0; index < totalClasses; ++index) {
            std::cout << (attendanceRecords[index] ? "P " : "A ");
        }

        std::cout << '\n';
    }

    std::cout << "Attendance Percentage: "
              << std::fixed << std::setprecision(2)
              << getPercentage() << "%\n";
}

int Attendance::getStudentId() const {
    return studentId;
}

int Attendance::getTotalClasses() const {
    return totalClasses;
}