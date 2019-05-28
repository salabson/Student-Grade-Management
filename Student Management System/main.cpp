#include <iostream>
#include <string>
#include<ios>
#include<iomanip>



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

  while(cin >> homework_grade){
    icount++;
    sum+=homework_grade;
  }
  streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << 0.2*midterm_grade + 0.4*final_grade + 0.4 *sum/icount
         << setprecision(prec) << endl;
    return 0;
}
