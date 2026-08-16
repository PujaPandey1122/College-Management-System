#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>

class Attendance {
private:
    static const int MAX_CLASSES = 100;

    int studentId;
    bool attendanceRecords[MAX_CLASSES];
    int totalClasses;

public:
    explicit Attendance(int studentId);

    void markPresent();
    void markAbsent();

    double getPercentage() const;

    void display() const;

    int getStudentId() const;
    int getTotalClasses() const;
};

#endif