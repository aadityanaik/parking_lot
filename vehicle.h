#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <iostream>

class parking_lot;

class vehicle
{
  std::string name, password;
    int time_in, time_out;
    float time_parked;
public:
    friend void getdata(parking_lot*, vehicle*);
};

#endif
