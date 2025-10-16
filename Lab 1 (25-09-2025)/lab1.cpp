#include <iostream>
using namespace std;

struct Student {
    int student_id;
    string student_name;
    string student_email;
};

int main() {
    Student student[5]

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student #" << (i + 1) << ":\n";
        cout << "Student ID: ";
        cin >> student[i].student_id;
        cin.ignore();
        cout << "Student Name: ";
        getline(cin, student[i].student_name);
        cout << "Student Email: ";
        getline(cin, student[i].student_email);
    }

    for (int i = 0; i < 5; i++) {
        cout << "\nDetails of student " << (i + 1) << ":\n";
        cout << "Student ID: " << student[i].student_id << "\n";
        cout << "Student Name: " << student[i].student_name << "\n";
        cout << "Student Email: " << student[i].student_email << "\n";
    }
}