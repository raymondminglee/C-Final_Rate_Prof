#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "check.h"
#include "create.h"
#include "linedel.h"
#include "linewrite.h"
#include "Rate.h"
#include "Professor.h"
using namespace std;

int status;
int input, input2;

void changerate();
void low2high();
void high2low();

struct Diffcmp{
	bool operator() (const Professor &lhs, const Professor &rhs)
	{
		if (lhs.Rating.Diff_level < rhs.Rating.Diff_level)
			return true;
		else if (lhs.Rating.Diff_level > rhs.Rating.Diff_level)
			return false;
		else
		{
                	if(lhs.name < rhs.name)
                        	return true;
                	else if (lhs.name > lhs.name)
                        	return false;
                	else
                        	return false;
        	}
	}
};


struct Qcmp{
        bool operator() (const Professor &lhs, const Professor &rhs)
        {
                if (lhs.Rating.Quality > rhs.Rating.Quality)
                        return true;
                else if (lhs.Rating.Quality < rhs.Rating.Quality)
                        return false;
                else
                {
                        if(lhs.name > rhs.name)
                                return true;
                        else if (lhs.name < lhs.name)
                                return false;
                        else
                                return false;
                }
        }
};





int main()
{
    int state;
    state = 1;
    while(state ==1)
    {
    cout << "________________________________________" << endl;
    cout << "what would you like to do" << endl;
    cout << "1 check a professor's rating" << endl;
    cout << "2 rate a professor" <<endl;
    cout << "3 create a professor" <<endl;
    cout << "4 dispaly professor from low to high Difficulty" << endl;
    cout << "5 dispaly professor from low to high Quality" << endl;
    cout << "clt + C to quit the programm" << endl;
    cout << " "<< endl;
    cin >> input;
    if (input == 1)
            check();
    else if (input ==2)
            changerate();
    else if (input == 3)
            create();
    else if (input == 4)
    	    low2high();    		
    else if (input ==5)
	    high2low();
    else
            cout <<"Invalid input, please enter a number from 1 to 5." << endl;
    }

    return 0;
}

void changerate()
{
        status = 0;
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
			cout <<newProf.name<<" rating is: Difficulty "
                                << newProf.Rating.Diff_level << " Quality " << newProf.Rating.Quality 
				<< " Overall "<<newProf.Rating.Overall<<endl;

                        ss << newProf.name << " " << newProf.dept_name<< " " 
				<<newProf.Rating.Diff_level<< " "<< newProf.Rating.Quality<< " " 
				<<newProf.Rating.Overall<<" "<<newProf.student_num;
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
                        cout <<newProf.name<<" new rating is: Difficulty "
				<< newProf.Rating.Diff_level << " Quality " << newProf.Rating.Quality << " "
				<<newProf.Rating.Overall<<endl; 	
                        linewrite(newProf.name, newProf.Rating.Diff_level, newProf.Rating.Quality, newProf.Rating.Overall, newProf.student_num, newProf.dept_name);
                        status = 1;
                }
        }


        if (status = 0)
        {
        cout<< "prof not found, plase create new one" << endl;
        }
        
}

void low2high()
{
        string name;
        double Diff_level, Quality, Overall;
        int student_num;
        
	string dept, dept_name;
        cout<< "whcih department would you like to see?"<<endl;
        cout<< "enter ALL for all department" <<endl;
        cin >> dept;
        
	set<Professor, Diffcmp> ProfSet;

        ifstream file;
        file.open("cooper_prof.txt");
        if (dept == "ALL")
        {
                while(file >> name >> dept_name >> Diff_level >> Quality >> Overall >> student_num)
                {
                        Rate R(Diff_level, Quality, Overall);
                        Professor inset(name, R, student_num, dept_name);
                        ProfSet.insert(inset);
                }

                for (auto it=ProfSet.begin(); it!=ProfSet.end(); ++it)
                
		{
			 cout << it->name <<" " <<it->dept_name<<
                                " Difficulty " <<it -> Rating.Diff_level<<
                                " Quality " << it -> Rating.Quality<<
                                " Overall " << it -> Rating.Overall<<endl;
                }
        }
        else
        {
                while(file >> name >> dept_name >> Diff_level >> student_num)
                {
                        if(dept == dept_name)
                        {
                                Rate R(Diff_level, Quality, Overall);
                                Professor inset(name, R, student_num, dept_name);
                                ProfSet.insert(inset);
                        }
                }
                for (auto it=ProfSet.begin(); it!=ProfSet.end(); ++it)
                {
                        cout << it->name <<" " <<it->dept_name<< 
				" Difficulty " <<it -> Rating.Diff_level<<
				" Quality " << it -> Rating.Quality<<
				" Overall " << it -> Rating.Overall<<endl;
                }
        }
        main();
}

void high2low()
{
        string name;
        double Diff_level, Quality, Overall;
        int student_num;

        string dept, dept_name;
        cout<< "whcih department would you like to see?"<<endl;
        cout<< "enter ALL for all department" <<endl;
        cin >> dept;

        set<Professor, Qcmp> ProfSet;

        ifstream file;
        file.open("cooper_prof.txt");
        if (dept == "ALL")
        {
                while(file >> name >> dept_name >> Diff_level >> Quality >> Overall >> student_num)
                {
                        Rate R(Diff_level, Quality, Overall);
                        Professor inset(name, R, student_num, dept_name);
                        ProfSet.insert(inset);
                }

                for (auto it=ProfSet.begin(); it!=ProfSet.end(); ++it)

                {
                         cout << it->name <<" " <<it->dept_name<<
                                " Difficulty " <<it -> Rating.Diff_level<<
                                " Quality " << it -> Rating.Quality<<
                                " Overall " << it -> Rating.Overall<<endl;
                }
        }
        else
        {
                while(file >> name >> dept_name >> Diff_level >> student_num)
                {
                        if(dept == dept_name)
                        {
                                Rate R(Diff_level, Quality, Overall);
                                Professor inset(name, R, student_num, dept_name);
                                ProfSet.insert(inset);
                        }
                }
                for (auto it=ProfSet.begin(); it!=ProfSet.end(); ++it)
                {
                        cout << it->name <<" " <<it->dept_name<<
                                " Difficulty " <<it -> Rating.Diff_level<<
                                " Quality " << it -> Rating.Quality<<
                                " Overall " << it -> Rating.Overall<<endl;
		}
	}
	main();
}

