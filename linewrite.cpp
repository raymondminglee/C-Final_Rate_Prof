#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "linewrite.h"
using namespace std;

string name;
double Diff, Quality, Overall;
int student_num;
string dept_name;


void linewrite(string name, double Diff, double Quality, double Overall, int student_num, string dept_name)
{
        ofstream file("cooper_prof.txt", ios::app);
        file<<name<< " " << dept_name<<" "<< Diff<< " "<< Quality<< " " << Overall<<" " << student_num<< endl;
        file.close();
}

