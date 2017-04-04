#include <iostream>
#include <string>

#include "functions.h"
#include "parking_lot.h"
#include "vehicle.h"

using namespace std;

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
    cout << "We are sorry, we could not find you in the system." << endl;
  }

  else{
    sectn = x -> index.check_sectn(n, p);
    time_in = (x -> index.returntime(sectn));
    row = (x -> index.returnrow(sectn));
    column = (x -> index.returncolumn(sectn));
    cout << "Thank you for using PARKINATOR parking systems std. pvt. ltd." << endl;
    cout << "Your car is located in slot " << char(row) << " " << column << endl;
    cout << "Your charge is INR " << 20 * (time(NULL) - time_in) / 60.0 << endl;
    x -> change_state(row, column);
  }
}
