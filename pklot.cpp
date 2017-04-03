#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <fstream>

#include "vehicle.h"
#include "parking_lot.h"
#include "file.h"

using namespace std;

#define YES 1

void getdata(parking_lot *x, vehicle *y)                                    //takes input from the user
{
    cout << "Enter the amount of time you want to park for (in hours):\t";
    do{
      cin >> (x -> time_allot);
      if(cin.fail()){                                                         //cin function fails in the extraction process
        cout << "Bad Parameters. Try again:" << endl;
        cin.clear();                                                        //clears out the buffer and resets the cin function
        cin.ignore(32767, '\n');                                            //removes/ignores the bad input
	cin >> (x -> time_allot);
      }
    }while(cin.fail());
    if((x -> allot_space())){                                               //if space is alloted
        cout << "Enter your full name:\t";
	cin.ignore();
        getline(cin, y -> name);

	string pwdtrial;
	do{
	  cout << "Enter a password:\t";
	  //cin.ignore();
	  getline(cin, y -> password);
	  cout << "Confirm your password:\t" << endl;
	  //cin.ignore();
	  getline(cin, pwdtrial);
	  if(pwdtrial != (y -> password)){
	    cout << "Sorry, passwords do not match" << endl;
	  }
	}while(pwdtrial != (y -> password));
	x -> index.append((y -> name), (y -> password));
	x -> index.append(time(NULL));
    }

    else{
        cout << "Please try after some time" << endl;                       //we need more space, or funds, or a new job
    }
}

void charge(string n, string p, parking_lot *x)
{
  int row, column, time_in, sectn;
  if((x -> index.check_sectn(n, p)) == 0){
    //cout << n << endl << p << endl;
    cout << "We are sorry, we could not find you in the system." << endl;
  }

  else{
    sectn = x -> index.check_sectn(n, p);
    cout << sectn << endl;
    time_in = (x -> index.returntime(sectn));
    row = (x -> index.returnrow(sectn));
    column = (x -> index.returncolumn(sectn));
    //cout << time_in << " " << row << " " << column << endl;
    cout << "Thank you for using PARKINATOR parking systems std. pvt. ltd." << endl;
    cout << "Your charge is INR " << 20 * (time(NULL) - time_in) << endl;
    cout << row << " " << column << endl;
    x -> change_state(row, column);
  }
}





int main()
{
    char vehicle_choice;
    char choice;                                                            //Choices, because we want a complicated program worth at least 5 marks
    char *currenttime;                                                      //pointer to a string
    parking_lot *slot4 = new parking_lot("4wheeler/Index");
    parking_lot *slot2 = new parking_lot("2wheeler/Index");
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
	    //cin.ignore();
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
