#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Professor.h"
#include "Rate.h"
#include "changerate.h"
#include "linedel.h"
#include "linewrite.h"
using namespace std;

void changerate()
{
        int status = 0;
        double new_Diff_level, Diff_level, new_Quality, Quality, Overall;
        int student_num;
        string dept_name;
        string name, name2rate;
        string line2del;
        stringstream ss;


        ifstream file("cooper_prof.txt");
        cout <<" enter the professor you want to rate"<<endl;
        cin >> name2rate;

        while    (file>>name>>dept_name>>Diff_level>>Quality>>Overall>>student_num)
        {
                if (name2rate == name)
                {

                        Rate R(Diff_level, Quality, Overall);
                        Professor newProf(name, R, student_num, dept_name);
                        cout << newProf.name << " " << newProf.Rating.Diff_level<< endl;
                        ss << newProf.name << " " << newProf.dept_name<< " " <<newProf.Rating.Diff_level<< " "<< newProf.Rating.Quality<< " " <<newProf.Rating.Overall<<" "<<newProf.student_num;
                        line2del = ss.str();
                        linedel(line2del);
                        cout << "enter your rating for Difficulty"<< endl;
                        cin >> new_Diff_level;
                        cout << "enter your rating for Quality" << endl;
                        cin >> new_Quality;
                        newProf.changenumber(newProf.student_num);
                        newProf.changeDiff(new_Diff_level, newProf.student_num);
                        newProf.changeQual(new_Quality, newProf.student_num);
                        newProf.changeOver();
                        cout <<"new rating is: " <<newProf.Rating.Diff_level << endl;
                        linewrite(newProf.name, newProf.Rating.Diff_level, newProf.Rating.Quality, newProf.Rating.Overall, newProf.student_num, newProf.dept_name);
                        status = 1;
                }
        }


        if (status = 0)
        {
        cout<< "prof not found, plase create new one" << endl;
        }
	return;
}
