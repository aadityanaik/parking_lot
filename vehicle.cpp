#include <iostream>
#include <fstream>
#include "vehicle.h"

using namespace std;

float vehicle::charge(int rate = 10)                                        //Change the rates if we want to extort money
{
    time_out = time(NULL);                                                  //time of exit
    time_parked = (time_out - time_in) / 3600.0 ;
    return time_parked * rate;
}

bool vehicle::chk_name(string a, string b)                                      //checks if the name exists. Will change when we learn file handling
{
    if(a == first_name && b == surname){
        return 1;
    }
    else{
        return 0;
    }
}
