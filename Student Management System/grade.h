#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<stdexcept>
#include<vector>
#include<string>
#include<iostream>
#include "student_info.h"
#include "median.h"

double compute_final_grade(double, double , double );
double compute_final_grade(const student_info&);
double compute_final_grade_aux(const student_info&);
bool fgrage(const student_info&);
std::vector<student_info> extract_student_fails(std::vector<student_info>&);
void extract_student_do_all_homework(const std::vector<student_info>&, std::vector<student_info>&, std::vector<student_info>&);
double median_analysis(const std::vector<student_info>&);
void write_analysis(std::ostream& out, const std::string&, double analysis(const std::vector<student_info>&),
                    const std::vector<student_info>&, const std::vector<student_info>&);

#endif // GUARD_grade_h

