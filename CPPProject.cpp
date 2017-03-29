      #include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define YES 1

//list of classes

class parking_lot;

class vehicle;

//definition of class

class parking_lot
{
    bool space[10][10];
    int count[4];
    float time_allot;
public:
    parking_lot()
    {
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                space[i][j] = 0;
            }
        }

        for(int i = 0; i < 4; i++){
            count[i] = 0;
        }
    }
    friend void getdata(parking_lot*, vehicle*);
    bool allot_space();
    void disp_lot();
};

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

//Definition of functions

bool vehicle::chk_name(string a, string b)                                      //checks if the name exists. Will change when we learn file handling
{
    if(a == first_name && b == surname){
        return 1;
    }
    else{
        return 0;
    }
}
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
            count[0]++;
            return 1;
        }
    }
    if(time_allot < 4 && time_allot >=3){                                       //more than 3 hours
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
            count[1]++;
            return 1;
        }
    }

    if(time_allot < 3 && time_allot >= 1.5){
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
            count[2]++;
            return 1;
        }
    }
    if(time_allot < 1.5 && time_allot > 0){
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
            count[3]++;
            return 1;
        }
    }
}

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
    }

    else{
        cout << "Please try after some time" << endl;                       //we need more space, or funds, or a new job
    }
}

float vehicle::charge(int rate = 10)                                        //Change the rates if we want to extort money
{
    time_out = time(NULL);                                                  //time of exit
    time_parked = (time_out - time_in) / 3600.0 ;
    return time_parked * rate;
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
int main()
{
	char vehicle_choice;
    char choice;                                                            //Choices, because we want a complicated program worth at least 5 marks
    char *currenttime;                                                      //pointer to a string
    /*parking_lot *slot;                                                      //pointer to an object
    parking_lot lot;
    slot = &lot;                                                            //slot points to lot*/
    parking_lot *slot4 = new parking_lot;
    parking_lot *slot2 = new parking_lot;
    int i = 0;
    vehicle car[1000], bike[1000];                                                      //array of 1000 cars, because we are too popular for our own good
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
        			getdata(slot4, (car + i));
                    break;
                case '2':
                	cout << "\t" << "\t" << "\t" << currenttime << endl;                //shows the time the function is called
        			slot2 -> disp_lot();
					getdata(slot2,(bike+i));     
					break;
			}
            break;
            
        case '2':
            cout << "Enter your name as <first name> <surname> :\t";
            cin >> fname >> sname;
            for(int i = 0; i < 1000; i++){
                if(car[i].chk_name(fname, sname)){                          //Checks if a car in the parking spot is associated with entered name
                    cout << "Thank you for using PARKINATOR parking systems. Your charge is INR " << car[i].charge()<<endl;
                                                                            //Sorry, couldn't think of a better name
                }
            }
            break;
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
