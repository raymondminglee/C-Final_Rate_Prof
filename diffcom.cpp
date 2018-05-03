#include <iostream>
#include <string>
#include "Rate.h"
#include "Professor.h"
#include "diffcom.h"
bool operator() ( const Professor& lhs, Professor& rhs)
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
