#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "check.h"
using namespace std;

void check()
{
        int status = 0;
        ifstream file("cooper_prof.txt");
        string name, search_name;
        int student_num;
        double Diff_level;
        double Quality;
        double Overall;
        string dept_name;
        cout << "enter the professor's last name"<<endl;
        cin >> search_name;
        while (file >> name >> dept_name >>Diff_level>> Quality >> Overall>> student_num)
        {
                if (search_name == name)
                {
                cout << "professor found" << endl;
                cout << name << " Difficulty " << Diff_level 
			<<" Quality "<<Quality<<" Overall "<<Overall  
			<< " || Rated by " << student_num << " students."<<endl;
                        status = 1;

                }
        }
        if(status == 0)
        {
                cout<<"prof not found"<< endl;
                cout<<"Please create a new one" << endl;
        }

}

