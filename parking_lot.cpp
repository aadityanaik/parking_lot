#include <iostream>
#include <cstdlib>
#include <time.h>
#include "parking_lot.h"
#include "file.h"

#define YES 1

using namespace std;

bool parking_lot::allot_space()                                                 //returns 1 if space allocated, 0 otherwise
{
    int row, column;
    if(time_allot >= 4){                                                        //more than 4 hours
        if(count[0] >= 20){
            cout << "No more space for you" << endl;                            //in case the entire section is occupied
            return 0;
        }
        else{
            do{
                column = rand() % 10;                                           //randomly generate a spot--- column
                row = rand() % 2 + 65;                                          //row
            }while(space[row - 65][column] == YES);                             //keeps looping until the slot generated is empty
            cout << "Your space is " << char(row) << column + 1 << endl;
            space[row - 65][column] = 1;
	    index.append(row, column);
            count[0]++;
            return 1;
        }
    }
    else if(time_allot < 4 && time_allot >=3){                                       //more than 3 hours
        if(count[1] >= 20){
            cout << "No more space for you" << endl;                            //in case the entire section is occupied
            return 0;
        }
        else{
            do{
                column = rand() % 10;                                           //randomly generate a spot--- column
                row = rand() % 2 + 67;                                          //row
            }while(space[row - 65][column] == YES);                             //keeps looping until the slot generated is empty
            cout << "Your space is " << char(row) << column + 1 << endl;
            space[row - 65][column] = 1;
	    index.append(row, column);
            count[1]++;
            return 1;
        }
    }

    else if(time_allot < 3 && time_allot >= 1.5){
        if(count[2] >= 36){
            cout << "No more space for you" << endl;                            //in case the entire section is occupied
            return 0;
        }
        else{
            do{
                row = rand() % 6 + 69;                                          //randomly generate row
                if(row > 70){
                    column = rand() % 4;                                        //random generation of column for rows J, I, H, G
                    if(column >= 2)
                        column = column + 6;
                }
                else
                    column = rand() % 10;                                       //random generation of column for rows E, F
            }while(space[row - 65][column] == YES);
            cout << "Your space is " << char(row) << column + 1 << endl;
            space[row - 65][column] = 1;
	    index.append(row, column);
            count[2]++;
            return 1;
        }
    }
    else if(time_allot < 1.5 && time_allot > 0){
        if(count[3] >= 24){
            cout << "No more space for you" << endl;                            //in case the entire section is occupied
            return 0;
        }
        else{
            do{
                row = rand() % 4 + 71;                                          //random generation of row
                column = rand() % 6 + 2;                                        //random generation of column
            }while(space[row - 65][column] == YES);
            cout << "Your space is " << char(row) << column + 1 << endl;
            space[row - 65][column] = 1;
	    index.append(row, column);
            count[3]++;
            return 1;
        }
    }
}


void parking_lot::disp_lot()
{
    int m ,n;
    cout << "   ";
    for(n = 0; n < 10; n ++){                                               //Printing column headings appropriately spaced
        cout << n + 1 << "  ";
    }
    cout << endl;
    for(m = 0; m < 10; m++){
        cout << char(m + 65) << "  ";                                       //Printing row names
        for(n = 0; n < 10; n++){
            cout << space[m][n] << "  ";                                    //Printing the value under each spot
        }
        cout << endl;
        if(m % 2 == 1)
            cout << endl;
    }
    cout << "   ";
    for(n = 0; n < 4; n++)
        cout << "   ";
    cout << "Entry" << endl;                                                //Printing the entry point of the lot
}


void parking_lot::change_state(int row, int column)
{
  space[row - 65][column] = 0;
}
