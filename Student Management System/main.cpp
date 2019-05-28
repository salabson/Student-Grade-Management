#include <iostream>
#include <string>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>



using namespace std;

int main()
{
   // Read student name
    cout << "Please Enter your first name!" << endl;
    string name;
    cin>>name;
    cout << "Hello " << name << "!" << endl;

    // Read student midtern and final grade
    cout << "Enter your Midterm and Final Grades" << endl;
    double midterm_grade, final_grade;
    cin >> midterm_grade >> final_grade;

  // ask for Homework grades
  cout << "Enter all your homework grades" << endl;
  int icount = 0;
  double sum = 0;
  double homework_grade;
  vector<double> homework_grades;

  // read homework grades into vector
  while(cin >> homework_grade){
   homework_grades.push_back(homework_grade);
   }
   // check that student enter some homework grade
   typedef vector<double>::size_type vec_size;
   vec_size size = homework_grades.size();
   if(size == 0){
    cout << "You must enter at least one grade" << endl;
    return 1;
  }

  // sort the grades
  sort(homework_grades.begin(), homework_grades.end());

  // compute median of homework grades
  vec_size mid = size/2;
  double median;
  median = size%2==0 ? homework_grades[mid]+homework_grades[mid-1]/2:homework_grades[mid];

  streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << 0.2*midterm_grade + 0.4*final_grade + 0.4 *median
         << setprecision(prec) << endl;
    return 0;
}
