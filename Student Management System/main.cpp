#include <iostream>
#include <string>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include"grade.h"


using std::vector;
using std::domain_error;
using std::sort;
using std::cin;
using std::cout;
using std::setprecision;
using std::streamsize;
using std::string;
using std::endl;
using std::max;
using std::istream;

int main()
{
    /**
   // Read student name
    cout << "Please Enter your first name!" << endl;
    string name;
    cin>>name;
    cout << "Hello " << name << "!" << endl;

    // Read student midterm and final grade
    cout << "Enter your Midterm and Final Grades" << endl;
    double midterm_grade, final_grade;
    cin >> midterm_grade >> final_grade;

   // ask for Homework grades
   cout << "Enter all your homework grades" << endl;

  // Read the homework grades
  vector<double> homework_grades;
  read_homework(cin,homework_grades);
  **/


  vector<student_info> students;
  student_info student;

  // this fill the student vector with student data
  while(read_student_info(cin,student))
        students.push_back(student);

 // sort the students by name
  sort(students.begin(), students.end(), compare);

  // access each student data the compute his overall grade and print it along with his name
  for(vector<student_info>::size_type i=0; i!=students.size(); i++ ){
    try {
        cout << students[i].name << " ";
        // compute and write final grade
   double overall_grade = compute_final_grade(students[i]);
   streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << overall_grade
         << setprecision(prec) << endl;

   }catch (domain_error e){
     cout << e.what();
     return 1;
   }
    cout << endl;
  }




    return 0;
}
