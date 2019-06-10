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

double compute_average(const vector<double>& vec){
    return accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
}
double compute_average_grade(const student_info& s){
    return compute_final_grade(s.midterm_grade, s.final_grade, compute_average(s.homework));
}

// median of nonzero elements of homework or 0 if all homework are zero;
double compute_optimistic_median(const student_info& s){
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero),0);

    if(nonzero.empty())
       return compute_final_grade(s.midterm_grade, s.final_grade, 0);
    else
        return compute_final_grade(s.midterm_grade, s.final_grade, compute_median(nonzero));
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

// predicate to determine whether a student pass
bool pgrage(const student_info& s){
    return !fgrage(s);
}

// Median analysis for all students final grades
double median_analysis(const vector<student_info>& students){
    vector<double> grades;
    // calculate final grades for each student using compute final grade function and append to grades vector
    transform(students.begin(), students.end(), back_inserter(grades), compute_final_grade_aux);
   // calculate median of the grades vector and return it
    return compute_median(grades);
}

double optimistic_median_analysis(const vector<student_info>& students){
    vector<double> grades;
    // calculate final grades for each student using compute final grade function and append to grades vector
    transform(students.begin(), students.end(), back_inserter(grades), compute_optimistic_median);
   // calculate median of the grades vector and return it
    return compute_median(grades);
}

// Median analysis for all students final grades
double average_analysis(const vector<student_info>& students){
    vector<double> grades;
    // calculate final grades for each student using compute final grade function and append to grades vector
    transform(students.begin(), students.end(), back_inserter(grades), compute_average_grade);
   // calculate median of the grades vector and return it
    return compute_median(grades);
}


void write_analysis(ostream& out, const string& name, double analysis(const vector<student_info>&),
                    const vector<student_info>& did, const vector<student_info>& didnt)
{
    out << name <<":" << name <<"(did) = " << analysis(did)
                << ":" << name <<"(didnt = ) " << analysis(didnt) << endl;
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

// Two pass solution using algorithm
vector<student_info> extract_fails(vector<student_info>& students){

    vector<student_info> fail;
    // remove the passing students from the students vector,
    // remaining the failing  student then copy them to fail vector
    remove_copy_if(students.begin(), students.end(),back_inserter(fail), pgrage);
    // We erase the failing students from students vector
    vector<student_info>::iterator iter = remove_if(students.begin(), students.end(), fgrage);
    students.erase(iter, students.end());


    return fail;


}


// One pass solution using algorithm
vector<student_info> extract_fails_2(vector<student_info>& students){

    vector<student_info>::iterator  iter = stable_partition(students.begin(),students.end(),pgrage);
    // remove the passing students from the students vector,
    // remaining the failing  student then copy them to fail vector
    vector<student_info> fail (iter, students.end());
    // We erase the failing students from students vector
    students.erase(iter, students.end());

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

