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
    // check that student enter some homework grade(s)
   typedef vector<double>::size_type vec_size;
    vec_size size = vec.size();
   if(size == 0)
    throw domain_error("Median of the vector is empty");



    // sort the homework grades
  sort(vec.begin(), vec.end());

  // compute median of homework grades
  vec_size mid = size/2;

  return size%2==0 ? vec[mid]+vec[mid-1]/2:vec[mid];


}

//compute student's overall grade from midterm and final exam grades
// vector of homework grades
// this function does not copy its arguments, because median does so for us
double compute_final_grade(double midterm, double final_grade, const vector<double>& homework){
     if(homework.size() == 0){
    throw domain_error("Student has no homework");
  }
    return compute_final_grade(midterm, final_grade, compute_median(homework));
}
//Read homework from input stream into homework vector
istream& read_homework(istream& in, vector<double>& homework){

  if(in){
    // Clear the previous content
    homework.clear();

   // read homework grades into vector
   double homework_grade;
   while(cin >> homework_grade)
      homework.push_back(homework_grade);


   // Clear the stream so that input will work for next student
   in.clear();
  }

   return in;
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

  // Read the homework grades
  vector<double> homework_grades;
  read_homework(cin,homework_grades);


   try {
        // compute and write final grade
   double overall_grade = compute_final_grade(midterm_grade,final_grade,homework_grades);
   streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << overall_grade
         << setprecision(prec) << endl;

   }catch (domain_error){
     cout << "You must enter home grades. Please try again" << endl;
     return 1;
   }

    return 0;
}
