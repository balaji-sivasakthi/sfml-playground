#include <iostream>
#include <vector>
#include <fstream>

class Student
{
   std::string m_firstName;
   std::string m_lastName;

public:
   Student() {}
   Student(const std::string &firstName, const std::string &lastName) : m_firstName(firstName), m_lastName(lastName) {}

   const std::string &getFirstName() const
   {
      return m_firstName;
   }

   const std::string &getLastName() const
   {
      return m_lastName;
   }
};

class Course
{
   std::string m_courseName;
   std::vector<Student> m_students;

public:
   Course() {}
   Course(const std::string &courseName) : m_courseName(courseName) {}

   void addStudent(const Student &student)
   {
      m_students.push_back(student);
   }

   void loadDataFromFile(const std::string &filename)
   {
      std::ifstream inputFile(filename);
      std::string firstName, lastName;
      while (inputFile >> firstName >> lastName)
      {
         addStudent(Student(firstName, lastName));
      }
   }

   void print() const
   {
      std::cout << "Course Name: " << m_courseName << std::endl;
      for (const auto &student : m_students)
      {
         std::cout << student.getFirstName() << " " << student.getLastName() << std::endl;
      }
   }
};

int main()
{
   Course course("Balaji CPP");
   course.addStudent(Student("test", "test"));
   course.loadDataFromFile("data.txt");
   course.print();
   return 0;
}
