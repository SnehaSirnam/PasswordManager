// File Name: PasswordDriver.cpp
//
// Author: Sneha Sirnam
//
// PasswordManager which validates the password and encrypts
// and stores
// Driver class to run the program
// Driver (main) in a separate file

#include<iostream>
#include <fstream>
#include "PasswordManager.h"
using namespace std;
const int SIZE=3;


//Driver demo using PasswordManager class

int main ()
{
    PasswordManager pwMan[SIZE];    // The PasswordManager object
    string netID,encPassword;
    ifstream fin;
    ofstream fout;
    int i=0;

    fin.open("passwords.txt");
    if(!fin.is_open())
    {
        cout<<"Error opening file to read data"<<endl;
        return 0;
    }

    //to read the data from the file
    while (fin>>netID)

    {
        pwMan[i].setUsername(netID);
        fin>>encPassword;
        pwMan[i].setEncryptedPassword(encPassword);
        i++;
    }
    fin.close();
    string enteredUsername,enteredOldPass,enteredNewPass;
    bool netIDmatches=false;
    int netIDmatchno=-1;
    //to get the input from the user
    cout<<"Please enter your username: "<<endl;
    cin>>enteredUsername;
    cout<<"Please enter your old password: "<<endl;
    cin>>enteredOldPass;
    cout<<"Please enter your new password: "<<endl;
    cin>>enteredNewPass;
    //Loop to check if the entered User name matches
    for(int i=0; i<SIZE; i++)
    {
        if(enteredUsername==pwMan[i].getUsername())
        {
            netIDmatches=true;
            netIDmatchno=i;

        }
    }
    if(netIDmatches)
    {
        //authenticates if the old password is correct
        if(pwMan[netIDmatchno].authenticate(enteredOldPass))
        {
            //sets the new password
            if(pwMan[netIDmatchno].setNewPassword(enteredNewPass))
            {
                fout.open("passwords.txt");
                //Displays error message if file does not exist or opened
                if(!fout.is_open())
                {
                    cout<<"Error opening file to write data"<<endl;
                    return 0;
                }
                cout<<"Password has been changed for netID: "
                    <<pwMan[netIDmatchno].getUsername()<<endl;
                //overrides the data in the existing file
                for(int i=0; i<SIZE; i++)
                {
                    fout<<pwMan[i].getUsername()<<"   ";
                    fout<<pwMan[i].getEncryptedPassword();
                    fout<<endl;
                }

            }
            else
            {
                cout<<"New Password does not meet criteria."<<endl;
                return 0;
            }

        }
        else
        {
            cout<<"Old password is incorrect."<<endl;
            return 0;
        }
    }
    else
    {
        cout<<"NetID is invalid, password not changed."<<endl;
        return 0;
    }

    return 0;
}

