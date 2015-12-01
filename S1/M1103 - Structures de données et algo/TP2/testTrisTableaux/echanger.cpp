#include "echanger.h"

void echanger(int& val1, int& val2)
{
    // VARIABLES
    int save;

    // TRAITEMENTS
    save = val2;
    val2 = val1;
    val1 = save;
}
