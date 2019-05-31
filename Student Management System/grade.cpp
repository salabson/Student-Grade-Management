#include "grade.h"
using std::domain_error;

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
