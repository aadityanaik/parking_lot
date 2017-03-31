#include <iostream>

using namespace std;

#ifndef _VEHICLE_H
#define _VEHICLE_H

class parking_lot;

class vehicle
{
    char name[101];
    int time_in, time_out;
    float time_parked;
public:
    friend void getdata(parking_lot*, vehicle*);
};

#endif
