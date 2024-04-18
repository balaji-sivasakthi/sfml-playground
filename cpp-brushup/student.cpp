#include <iostream>
#include <vector>
#include <fstream>
class Student
{
   std::string m_first = "";
   std::string m_second = "";

public:
   Student() {}
   Student(const std::string &first, const std::string &second) : m_first(first), m_second(second)
   {
   }
   const std::string getfirstName() const
   {
      return m_first;
   }

   const std::string getSecondtName() const
   {
      return m_second;
   }
};
class Course
{
   std::string m_course_name;
   std::vector<Student> m_students;

public:
   Course()
   {
   }
   Course(const std::string &course_name) : m_course_name(course_name)
   {
   }
   void addStudent(const Student &data)
   {
      m_students.push_back(data);
   }
   void loadDataFromFile(const std::string &filenmae)
   {
      std::ifstream ifs(filenmae);
      std::string first;
      std::string second;
      while (ifs >> first)
      {
         ifs >> second;
         addStudent(Student(first, second));
      }
   }
   void print() const
   {

      std::cout << "Course Name:" << m_course_name << std::endl;
      for (auto &it : m_students)
      {
         std::cout << it.getfirstName() << " " << it.getSecondtName() << std::endl;
      }
   }
};
int main(int argc, char *argv[])
{
   Course course("Balaji CPP");
   course.addStudent(Student("test", "test"));
   course.loadDataFromFile("data.txt");
   course.print();
   return 0;
}
