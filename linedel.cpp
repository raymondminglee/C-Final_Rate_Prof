#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "linedel.h"
using namespace std;

string line2del;



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
        //cout << "line deleted"<<endl;
        remove("cooper_prof.txt");
        rename("temp.txt","cooper_prof.txt");
	
}

