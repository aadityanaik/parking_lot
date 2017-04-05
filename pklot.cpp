/****************************************************************************************************************
 *                                 PARKINATOR PARKING SYSTEMS STD. PVT. LTD.                                    *
 *                                                                                                              *
 *  CEOs- Siddarth Menon, Aaditya Naik, Utkarsh Pant                                                            *
 *                                                                                                              *
 *  Authors- The CEOs themselves.                                                                               *
 *                                                                                                              *
 *    PARKINATOR Parking Systems is an ingenious way of managing your parking lot.Developed by the very people  *
 *  who pride themselves in knowing what's best for your parking lot, PARKINATOR can be used almost everywhere, *
 *  from the rundown garage in the middle of a big city to the most posh Hotels and Plazas around the world.    *
 *  Are you tired of a surplus of frustrated guests trying to get to their cars? Well, not any more! Simply     *
 *  head over to our repository at https://github.com/Siddarthmdn2810/parking_lot and download the source!      *
 *  Or send us your email address and we will share the binaries with you! What's better is that PARKINATOR is  *
 *  so well optimized, running on minimalistic graphics, that it runs lightning fast on even the slowest        *
 *  computer (t&c apply), so that you don't need to be inconvenienced for your comfort! Try it out right now!   *
 *                                                                                                              *
 ****************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <direct.h>

#include "vehicle.h"
#include "parking_lot.h"
#include "file.h"
#include "functions.h"

using namespace std;

#define YES 1

int main()
{
    char vehicle_choice;
    char choice;                                                            //Choices, because we want a complicated program worth at least 5 marks
    char *currenttime;                                                      //pointer to a string
    parking_lot *slot4 = new parking_lot("4wheeler\\Index");
    parking_lot *slot2 = new parking_lot("2wheeler\\Index");
    int i = 0;
    vehicle *wheel4 = new vehicle;
    vehicle *wheel2 = new vehicle;
    struct tm *t;                                                           //pointer to struct tm
    time_t y;                                                               // variable of a custom datatype
    string input;
    mkdir("2wheeler");
    mkdir("4wheeler");
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
        	system("CLS");
        	cout<<"Enter Your Vehicle Choice:"<<endl<<"1)4-Wheeler"<<endl<<"2)2-Wheeler"<<endl;
        	cin>>vehicle_choice;
        	switch(vehicle_choice)
        	{
        	case '1':
        	    system("CLS");
                cout << "\t" << "\t" << "\t" << currenttime << endl;                //shows the time the function is called
        		slot4 -> disp_lot();
        		getdata(slot4, wheel4);
        		system("CLS");
                slot4 -> disp_lot();
                cout << "Proceed to your spot" << endl;
                Sleep(2500);
                break;
            case '2':
                system("CLS");
                cout << "\t" << "\t" << "\t" << currenttime << endl;                //shows the time the function is called
        		slot2 -> disp_lot();
                getdata(slot2,wheel2);
                slot2 -> disp_lot();
                cout << "Proceed to your spot" << endl;
                Sleep(2500);
                break;

            default:
                cout << "Parameters not recognized. Try again:\t";
                goto start;
                break;
        	}
        	system("CLS");
        	break;
        case '2':
        {
        system("CLS");
	    char choice;
	    string pass;
	    cout << "Do you own a two wheeler or a four wheeler?" << endl << "1)4-Wheeler" << endl << "2)2-Wheeler" << endl;
	    cin >> choice;
	    while(choice != '1' && choice != '2'){
	      cout << "Enter 1 or 2" << endl;
	      cin >> choice;
	    }
	    system("CLS");
	    cout << "Enter your full name:\t";
	    cin.ignore();
	    getline(cin, input);
	    cout << "Enter your password:\t";
	    getline(cin, pass);
	    switch(choice){
	    case '1':
            system("CLS");
            charge(input, pass, slot4);
            break;

	    case '2':
	        system("CLS");
	      charge(input, pass, slot2);
	      break;
	    }

        cout << "Please wait..." << endl;
        Sleep(5000);
        system("CLS");
        break;
	  }

        case 'e':
            goto EXIT;
            break;
        default:
            cout << "Could not recognize parameters. Please try again:\t";
                                                                            //When the user is too dumb to read that we want 1 or 2
            goto start;
            break;
        }
        i++;
    }while(1);
    EXIT:
    remove("2wheeler\\Index");
    remove("4wheeler\\Index");
    return 0;
}
