#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <fstream>

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
	  {
	    char choice;
	    string pass;
	    cout << "Do you own a two wheeler or a four wheeler?" << endl << "1)4-Wheeler" << endl << "2)2-Wheeler" << endl;
	    cin >> choice;
	    while(choice != '1' && choice != '2'){
	      cout << "Enter 1 or 2" << endl;
	      cin >> choice;
	    }
	    cout << "Enter your full name:\t";
	    cin.ignore();
	    getline(cin, input);
	    cout << "Enter your password:\t";
	    getline(cin, pass);
	    cout << "OK" << endl;
	    switch(choice){
	    case '1':
	      charge(input, pass, slot4);
	      break;

	    case '2':
	      charge(input, pass, slot2);
	      break;
	    }
	    
            break;
	  }
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
