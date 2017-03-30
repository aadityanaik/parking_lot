#include <iostream>

using namespace std;

#ifndef _VEHICLE_H
#define _VEHICLE_H

class parking_lot;

class vehicle
{
    string first_name, surname;
    int time_in, time_out;
    float time_parked;
public:
    friend void getdata(parking_lot*, vehicle*);
    float charge(int);
    bool chk_name(string , string);
};

#endif
