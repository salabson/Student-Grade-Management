#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>


struct student_info{
    std::string name;
    double midterm_grade, final_grade;
    std::vector<double> homework;
};

std::istream& read_homework(std::istream& ,std::vector<double>&);
std::istream& read_student_info(std::istream&, student_info&);
bool compare (const student_info&, const student_info&);
bool do_all_homework(const student_info&);




#endif // GUARD_student_info_h

