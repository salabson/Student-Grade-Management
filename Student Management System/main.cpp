#include <iostream>
#include <string>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

double compute_final_grade(double midterm, double final_grade, double median ){
    return 0.2*midterm + 0.4*final_grade + 0.4*median;
}

double compute_median(vector<double> vec){
    // check that student enter some homework grade
   typedef vector<double>::size_type vec_size;
    vec_size size = vec.size();
   if(size == 0){
    throw domain_error("Median of the vector is empty");
  }



    // sort the grades
  sort(vec.begin(), vec.end());

  // compute median of homework grades
  vec_size mid = size/2;

  return size%2==0 ? vec[mid]+vec[mid-1]/2:vec[mid];


}




int main()
{
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

  double homework_grade;
  vector<double> homework_grades;

  // read homework grades into vector
  while(cin >> homework_grade){
   homework_grades.push_back(homework_grade);
   }



   double median = compute_median(homework_grades);
  // compute and write final grade
   streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << compute_final_grade(midterm_grade,final_grade,median)
         << setprecision(prec) << endl;
    return 0;
}
