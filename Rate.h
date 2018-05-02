#ifndef Rate_h
#define Rate_h

#include <string>
#include <iostream>

using namespace std;

class Rate{
        public:
                double Diff_level;
                double Quality;
                double Overall;
		Rate(double D, double Q, double O);
};

#endif
