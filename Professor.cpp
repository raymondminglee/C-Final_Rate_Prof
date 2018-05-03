#include <iostream>
#include <string>
#include "Professor.h"
#include "Rate.h"
using namespace std;

Professor::Professor(string str, Rate R, int student, string dept): name(str), Rating(R), student_num(student), dept_name(dept) {}

Professor::changeDiff(double new_Diff_level,int student_num) {
	Rating.Diff_level = (Rating.Diff_level*(student_num-1)+new_Diff_level)/student_num;
	}
Professor::changeQual(double new_Quality, int student_num) {
	Rating.Quality = (Rating.Quality*(student_num -1)+ new_Quality)/student_num;
	}
Professor::changeOver(){
	Rating.Overall = (Rating.Diff_level+Rating.Quality)/2;
	}
Professor::changenumber(int num) {student_num = num + 1;}

/*bool operator< (const Professor &lhs, const Professor &rhs)
{
        if (lhs.Rating.Diff_level < rhs.Rating.Diff_level)
                return true;
        else if (lhs.Rating.Diff_level > rhs.Rating.Diff_level)
                return false;
        else //compare name
        {
                if(lhs.name < rhs.name)
                        return true;
                else if (lhs.name > lhs.name)
                        return false;
                else
                        return false;
        }
}*/


