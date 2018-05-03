#ifndef Professor_h
#define Professor_h
#include <string>
#include <iostream>
#include "Rate.h"

using namespace std;

class Professor {

public:
    string name;
    double new_Diff_level, new_Quality;
    int student_num;
    string dept_name;
    Rate Rating;

    Professor(string str, Rate R, int student, string dept);

    changeDiff(double new_Diff_level,int student_num);
    changeQual(double new_Quality, int student_num);
    changeOver();
    changenumber(int num);
   // friend bool operator< (const Professor &lhs, const Professor &rhs);
};

#endif

