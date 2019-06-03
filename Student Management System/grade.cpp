#include "grade.h"
using std::domain_error;
using std::vector;

double compute_final_grade(double midterm, double final_grade, double median ){
    return 0.2*midterm + 0.4*final_grade + 0.4*median;
}



//compute student's overall grade from midterm and final exam grades
// vector of homework grades
// this function does not copy its arguments, because median does so for us
double compute_final_grade(const student_info& s){
     if(s.homework.size() == 0){
    throw domain_error("Student has no homework");
  }
    return compute_final_grade(s.midterm_grade, s.final_grade, compute_median(s.homework));
}

// predicate to determine whether a student fail
bool fgrage(const student_info& s){
    return compute_final_grade(s) < 60;
}

/**
// Separating passing and failing student records: first try
// used a lot of memory
vector<student_info> extract_student_fails(vector<student_info>& students){
    vector<student_info> fail, pass;

    for(vector<student_info>::size_type i=0; i!=students.size(); i++){
        if(fgrage(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);

    }
         students = pass;
         return fail;


}
**/

/**
// Second try: potentially slow
vector<student_info> extract_student_fails(vector<student_info>& students){

    vector<student_info> fail;
    vector<student_info>::size_type i =0;
    while(i!=students.size()){
        if(fgrage(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin()+i);
        }
        else
            i++;
    }

    return fail;
}

**/

// third try: iterators no indexing also potentially slow
vector<student_info> extract_student_fails(vector<student_info>& students){

    vector<student_info> fail;
    vector<student_info>::iterator iter = students.begin();
    while(iter!=students.end()){
        if(fgrage(*iter)){
            fail.push_back(*iter);
            students.erase(iter);
        }
        else
            iter++;
    }

    return fail;
}

