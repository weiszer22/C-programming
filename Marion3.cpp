#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    int id;
    string name;
    string className;

public:
    Student(int _id, string _name, string _className) : id(_id), name(_name), className(_className) {}

    int getId() { return id; }
    string getName() { return name; }
    string getClassName() { return className; }
};

class Teacher {
private:
    int id;
    string name;
    vector<Student*> students;

public:
    Teacher(int _id, string _name) : id(_id), name(_name) {}

    int getId() { return id; }
    string getName() { return name; }

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(Student* student) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == student) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    void printStudents() {
        cout << "Students assigned to teacher " << name << ": " << endl;
        for (Student* student  students) {
            cout << "Student ID: " << student->getId() << endl;
            cout << "Name: " << student->getName() << endl;
            cout << "Class: " << student->getClassName() << endl;
            cout << endl;
        }
    }
};

int main() {
    Student* s1 = new Student(1, "Weiszer", "Computer Science");
    Student* s2 = new Student(2, "Marion", "Electronics");
    Student* s3 = new Student(3, "Maziga", "Automotive");

    Teacher* t1 = new Teacher(1, "Md. Nancy");
    Teacher* t2 = new Teacher(2, "Mr. Phillip");

    t1->addStudent(s1);
    t1->addStudent(s2);
    t2->addStudent(s3);

    t1->printStudents();
    t2->printStudents();

    t1->removeStudent(s1);

    t1->printStudents();

    delete s1;
    delete s2;
    delete s3;
    delete t1;
    delete t2;

    return 0;
}
