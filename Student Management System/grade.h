#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<stdexcept>
#include "student_info.h"
#include "median.h"

double compute_final_grade(double, double , double );
double compute_final_grade(const student_info&);

#endif // GUARD_grade_h
