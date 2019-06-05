#include "grade.h"

using std::domain_error;
using std::vector;
using std:: find;
using std::ostream;
using std::string;
using std:: endl;

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

// We create this function to solve problem of overloaded function when calculating transform in media analysis
double compute_final_grade_aux(const student_info& s){
    try{
        return compute_final_grade(s);
    }catch(domain_error){
        return compute_final_grade(s.midterm_grade, s.final_grade, 0);
    }
}

// predicate to determine whether a student fail
bool fgrage(const student_info& s){
    return compute_final_grade(s) < 60;
}

// Median analysis for all students final grades
double median_analysis(const vector<student_info>& students){
    vector<double> grades;
    // calculate final grades for each student using compute final grade function and append to grades vector
    transform(students.begin(), students.end(), back_inserter(grades), compute_final_grade_aux);
   // calculate median of the grades vector and return it
    return compute_median(grades);
}


void write_analysis(ostream& out, const string& name, double analysis(const vector<student_info>&),
                    const vector<student_info>& did, const vector<student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did)
                << ": median(didnt = ) " << analysis(didnt) << endl;

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

void extract_student_do_all_homework(const vector<student_info>& sts, vector<student_info>& s1, vector<student_info>& s2){
    vector<student_info>::size_type i =0;

    while(i!= sts.size()){
        if(do_all_homework(sts[i]))
            s1.push_back(sts[i]);
        else
            s2.push_back(sts[i]);
        i++;
    }


}

