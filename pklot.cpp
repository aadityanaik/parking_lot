#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

#include "vehicle.h"
#include "parking_lot.h"

using namespace std;

#define YES 1

void getdata(parking_lot *x, vehicle *y)                                    //takes input from the user
{
    cout << "Enter the amount of time you want to park for (in hours):\t";
    cin >> (x -> time_allot);
    if(cin.fail()){                                                         //cin function fails in the extraction process
        cout << "Bad Parameters. Try again:" << endl;
        cin.clear();                                                        //clears out the buffer and resets the cin function
        cin.ignore(32767, '\n');                                            //removes/ignores the bad input
    }
    if((x -> allot_space())){                                               //if space is alloted
        (y -> time_in) = time(NULL);                                        //time of entry
        cout << "Enter your name as <first name> <surname> :\t";
        cin >> y -> first_name >> y -> surname;                             //takes in user name
	ofstream oFile;
	oFile.open("Index.txt", ios::app);
	oFile << y -> first_name << y -> surname << endl;
	oFile.close();
    }

    else{
        cout << "Please try after some time" << endl;                       //we need more space, or funds, or a new job
    }
}







int main()
{
	char vehicle_choice;
    char choice;                                                            //Choices, because we want a complicated program worth at least 5 marks
    char *currenttime;                                                      //pointer to a string
    parking_lot *slot4 = new parking_lot;
    parking_lot *slot2 = new parking_lot;
    int i = 0;
    vehicle *wheel4 = new vehicle;
    vehicle *wheel2 = new vehicle;
    struct tm *t;                                                           //pointer to struct tm
    time_t y;                                                               // variable of a custom datatype
    string fname, sname;


    do{
        time(&y);                                                           //returns number of seconds since 1 Jan '70
        t = localtime(&y);                                                  //converts the number of seconds into the respective data members of struct tm
        currenttime = asctime(t);                                           //returns a pointer to a string which shows local time
        srand(time(NULL));                                                  //makes a seed depending on the time the function is called
        cout << "What do you want to do (1 / 2) ?" << endl;
        cout << "1) Park" << endl << "2) Exit from the lot" << endl;        //Choices, for a fancier program
    start:
        cin >> choice;
        switch(choice)                                                      //Switch... case, because if conditions are too mainstream
        {
        case '1':
        	
        	cout<<"Enter Your Vehicle Choice:"<<endl<<"1)4-Wheeler"<<endl<<"2)2-Wheeler"<<endl;
        	cin>>vehicle_choice;
        	switch(vehicle_choice)
        	{
        	case '1':
        	        cout << "\t" << "\t" << "\t" << currenttime << endl;                //shows the time the function is called
        		slot4 -> disp_lot();
        		getdata(slot4, wheel4);
			slot4 -> disp_lot();
                        break;
                case '2':
                	cout << "\t" << "\t" << "\t" << currenttime << endl;                //shows the time the function is called
        		slot2 -> disp_lot();
			getdata(slot2,wheel2);
			slot2 -> disp_lot();
			break;

		default:
		  cout << "Parameters not recognized. Try again:\t";
		  goto start;
		 }
            break;
            
        case '2':
	  /*cout << "Enter your name as <first name> <surname> :\t";
            cin >> fname >> sname;
            for(int i = 0; i < 1000; i++){
                if(car[i].chk_name(fname, sname)){                          //Checks if a car in the parking spot is associated with entered name
                    cout << "Thank you for using PARKINATOR parking systems. Your charge is INR " << car[i].charge()<<endl;
                                                                            //Sorry, couldn't think of a better name
                }
            }
            break;*/
        default:
            cout << "Could not recognize parameters. Please try again." << endl;
                                                                            //When the user is too dumb to read that we want 1 or 2
            goto start;
            break;
        }
        i++;
    }while(1);
    return 0;
}
