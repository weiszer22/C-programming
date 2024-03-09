#include <iostream>
#include <vector>
#include <string>

// Define a Student class
class Student {
 public:
  Student(std::string name, int id) : name_(name), id_(id) {}
  std::string GetName() const { return name_; }
  int GetId() const { return id_; }

 private:
  std::string name_;
  int id_;
};

// Define a Feedback class
class Feedback {
 public:
  Feedback(std::string comment, bool controlled) : comment_(comment), controlled_(controlled) {}
  std::string GetComment() const { return comment_; }
  bool IsControlled() const { return controlled_; }

 private:
  std::string comment_;
  bool controlled_;
};

// Define a Teacher class
class Teacher {
 public:
  Teacher(std::string name, std::vector<Student> students)
      : name_(name), students_(students) {}

  void AddFeedback(int student_id, Feedback feedback) {
    for (Student& student . students_) {
      if (student.GetId() == student_id) {
        feedbacks_.push_back(feedback);
        return;
      }
    }
    std::cout << "Student not found." << std::endl;
  }

  void ViewFeedback() const {
    if (feedbacks_.empty()) {
      std::cout << "No feedback yet." << std::endl;
      return;
    }
    for (const Feedback& feedback : feedbacks_) {
      std::cout << "Comment: " << feedback.GetComment()
                << ", Controlled: " << (feedback.IsControlled() ? "Yes" : "No") << std::endl;
    }
  }

 private:
  std::string name_;
  std::vector<Student> students_;
  std::vector<Feedback> feedbacks_;
};

int main() {
  // Create some students
  Student student1("John Doe", 1);
  Student student2("Jane Doe", 2);

  // Create a teacher and assign some students
  Teacher teacher("Teacher Doe", {student1, student2});

  // Add some feedback
  teacher.AddFeedback(1, Feedback("Good job!", true));
  teacher.AddFeedback(2, Feedback("Keep practicing!", false));

  // View the feedback
  teacher.ViewFeedback();

  return 0;
}