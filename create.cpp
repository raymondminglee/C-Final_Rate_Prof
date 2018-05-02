#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "create.h"
using namespace std;
void create()
{
        string name, dept_name;
        double Diff_level;
        double Quality;
        double Overall;
        int student_num = 1;
        ofstream file("cooper_prof.txt", ios::app);
        cout <<"Please enetr professor last name " << endl;
        cin >> name;
        cout << "Please enter the department (EE,ME,CE,CHE,FA,ARCH)"<<endl;
        cin >> dept_name;
        cout << "Please rate the level of difficulty: (scale 1 to 5)"<<endl;
        cin >> Diff_level;
        cout<< "Pleae rate the level of lecture quality"<<endl;
        cin >> Quality;
        Overall = (Diff_level+Quality)/2;
        cout << "Created "<< name << " " << dept_name<< " " 
		<< "Difficulty " <<Diff_level<< " Quality " << Quality 
		<<" Overall "<< Overall<<" ||Rated by " << student_num << endl;
	file << name << " " << dept_name<< " " << Diff_level<< " " << Quality <<" "<< Overall<<" " << student_num << endl;
        file.close();
        return;
}


