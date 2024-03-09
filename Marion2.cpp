#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    Student(std::string name, int id) : name(name), id(id) {}
    std::string getName() { return name; }
    int getId() { return id; }
private:
    std::string name;
    int id;
};

class Feedback {
public:
    Feedback(std::string text, bool controlled, int studentId)
        : text(text), controlled(controlled), studentId(studentId) {}
    std::string getText() { return text; }
    bool isControlled() { return controlled; }
    int getStudentId() { return studentId; }
private:
    std::string text;
    bool controlled;
    int studentId;
};

class Teacher {
public:
    void addStudent(Student student) { students.push_back(student); }
    void addFeedback(Feedback feedback) { feedbacks.push_back(feedback); }
    void modifyFeedback(int index, Feedback feedback) { feedbacks[index] = feedback; }
    void deleteFeedback(int index) { feedbacks.erase(feedbacks.begin() + index); }
    void viewStudents() {
        for (const Student& student : students) {
            std::cout << "Student name: " << student.getName()
                      << ", Student id: " << student.getId() << std::endl;
        }
    }
    void viewFeedbacks() {
        for (const Feedback& feedback : feedbacks) {
            std::cout << "Feedback text: " << feedback.getText() 
                      << ", Controlled: " << (feedback.isControlled() ? "Yes" : "No") 
                      << ", Student id: " << feedback.getStudentId() << std::endl;
        }
    }
private:
    std::vector<Student> students;
    std::vector<Feedback> feedbacks;
};

int main() {
    Teacher teacher;

    // Add students
    teacher.addStudent(Student("Weiszer", 1));
    teacher.addStudent(Student("Marion", 2));

    // Add feedback
    teacher.addFeedback(Feedback("Great job!", true, 1));
    teacher.addFeedback(Feedback("Good work!", false, 2));

    // Modify feedback
    Feedback modifiedFeedback("Good work!", true, 2);
    teacher.modifyFeedback(0, modifiedFeedback);

    // View students
    teacher.viewStudents();

    // View feedback
    teacher.viewFeedbacks();

    // Delete feedback
    teacher.deleteFeedback(0);

    // View feedback after deletion
    teacher.viewFeedbacks();

    return 0;
}
