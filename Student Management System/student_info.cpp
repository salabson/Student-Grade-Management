#include "student_info.h"

using std::vector;
using std::istream;
using std::cin;
using std::cout;
using std:: endl;
//Read homework from input stream into homework vector
istream& read_homework(istream& in, vector<double>& homework){

  if(in){
    // Clear the previous content
    homework.clear();
   // read homework grades into vector
   double homework_grade;
   while(in >> homework_grade)
      homework.push_back(homework_grade);


   // Clear the stream so that input will work for next student
   in.clear();
  }

   return in;
}

istream& read_student_info(istream& in, student_info& s){
    // Read and store student's name, midterm and final grades
    cout << "Enter student's name, midterm and final grades" << endl;
    in >> s.name >> s.midterm_grade >> s.final_grade;

    // Read and store all homework grades into a vector
    cout << "Enter student's homework grades" << endl;
    read_homework( in, s.homework);

    return in;

}

bool compare (const student_info& x, const student_info& y ){
    return x.name < y.name;
}

// check if student do all homework
bool do_all_homework(const student_info& st){
   return (find(st.homework.begin(), st.homework.end(), 0)== st.homework.end());
}



