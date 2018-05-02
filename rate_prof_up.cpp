#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int status;
int input;


class Rate{
	public:
		double Diff_level;
		double Quality;
		double Overall;

		Rate(double D, double Q, double O): Diff_level(D), Quality(Q), Overall (O){}
};


class Professor {

public:
    string name;
    double new_Diff_level, new_Quality;
    int student_num;
    string dept_name;
    Rate Rating;

    Professor(string str, Rate R, int student, string dept): name(str), Rating(R), student_num(student), dept_name(dept) {}
    
    void changeDiff(double new_Diff_level,int student_num) {Rating.Diff_level = (Rating.Diff_level*(student_num-1)+new_Diff_level)/student_num;}
    void changeQual(double new_Quality, int student_num) {Rating.Quality = (Rating.Quality*(student_num -1)+ new_Quality)/student_num;}
    void changeOver(){Rating.Overall = (Rating.Diff_level+Rating.Quality)/2;}
    void changenumber(int num) {student_num = num + 1;}
    friend bool operator< (const Professor &lhs, const Professor &rhs);
};

bool operator< (const Professor &lhs, const Professor &rhs)
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
}

struct{
	bool operator() (Professor a, Professor b)
	{
		return a.Rating.Quality < a.Rating.Quality;
	}
} customGreater;


void check();
void create();
void changerate();
void linedel(string line2del);
void linewrite(string name, double Diff, double Quality, double Overall, int student_num, string dept_name);
void low2high();
void high2low();


int main()
{
    cout << "________________________________________" << endl;
    cout << "what would you like to do" << endl;
    cout << "1 check a professor's rating" << endl;
    cout << "2 rate a professor" <<endl;
    cout << "3 create a professor" <<endl;
    cout << "4 dispaly professor from low to high" << endl;
    cout << "5 quit the programm" << endl;
    cout << "test" << endl;
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
    else if (input == 5)
	    exit(0);
    else if(input ==6)
	    high2low();
    else
	    cout <<"Invalid input, please enter a number from 1 to 5." << endl;
	
    return 0;
}


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
	cout << name << " " << dept_name<< " " << Diff_level<< " " << Quality <<" "<< Overall<<" " << student_num << endl;
	file << name << " " << dept_name<< " " << Diff_level<< " " << Quality <<" "<< Overall<<" " << student_num << endl;
        file.close();
        main();
}


void check()
{
	status = 0;
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
		cout << name << " Difficulty " << Diff_level <<" Quality "<<Quality<<" Overall "<<Overall  << " || Rated by " << student_num << " students."<<endl;
			status = 1;
			
		}
	}
	if(status == 0)
	{
		cout<<"prof not found"<< endl;
		cout<<"Please create a new one" << endl;
	}
			
	
	main();
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

	while	 (file>>name>>dept_name>>Diff_level>>Quality>>Overall>>student_num)
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
	main();
}


void linedel(string line2del)
{
    	string line;
	ifstream fin;
    	fin.open("cooper_prof.txt");
   	ofstream temp;
  	temp.open("temp.txt");

    	while (getline(fin,line))
   	{
      		if (line != line2del)
       		{
       			temp << line << endl;
       		}
   	}	

  	temp.close();
   	fin.close();
   	cout << "line deleted"<<endl;
	remove("cooper_prof.txt");
   	rename("temp.txt","cooper_prof.txt");
}

void linewrite(string name, double Diff, double Quality, double Overall, int student_num, string dept_name)
{
	ofstream file("cooper_prof.txt", ios::app);
	file<<name<< " " << dept_name<<" "<< Diff<< " "<< Quality<< " " << Overall<<" " << student_num<< endl;
	file.close();
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

	set<Professor> ProfSet;
	
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
			cout<<it->name << " " <<it->Rating.Diff_level <<endl;
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
			cout << it->name <<" " <<it->dept_name<< " " <<it -> Rating.Diff_level <<endl;
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

        vector<Professor> ProfVect;

        ifstream file;
        file.open("cooper_prof.txt");
        
        
                while(file >> name >> dept_name >> Diff_level >> Quality >> Overall >> student_num)
                {
                        Rate R(Diff_level, Quality, Overall);
                        Professor invect(name, R, student_num, dept_name);
                        ProfVect.push_back(invect);
                }

		std::sort(ProfVect.begin(), ProfVect.end(), customGreater);
		for (auto i : ProfVect)
                {
                        cout<<i <<endl;
                }
        
        /*else
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
                        cout << it->name <<" " <<it->dept_name<< " " <<it -> Rating.Diff_level <<endl;
                }
        }*/
        main();
}

