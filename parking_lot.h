#ifndef _PARKING_LOT_H
#define _PARKING_LOT_H

#include <iostream>
#include "file.h"

class vehicle;

class parking_lot
{
    bool space[10][10];
    int count[4];
    float time_allot;
    
public: 
    parking_lot(std::string file)
    {
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                space[i][j] = 0;
            }
        }

        for(int i = 0; i < 4; i++){
            count[i] = 0;
        }

	index = File(file);
    }

    File index;
    
    friend void getdata(parking_lot*, vehicle*);
    bool allot_space();
    void disp_lot();
    void change_state(int, int);
};

#endif
