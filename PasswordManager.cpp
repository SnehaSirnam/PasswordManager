// File Name: PasswordManager.cpp
//
// Author: Sneha Sirnam
//
// PasswordManager which validates the password and encrypts
// and stores
// The PasswordManager class
// Member function definitions (implementation) in a separate file

#include <iomanip>
using namespace std;
#include "PasswordManager.h"

//private member function
//encrypts the password using  Caesar Cipher
//encryption algorithm
//takes input password as parameter
//returns the encrypted password
string PasswordManager::encrypt(string passwrd)
{
    string encPasswrd;
    for(int i=0; i<passwrd.length(); i++)
    {
        encPasswrd[i] = ((passwrd[i]- 33) + 45) % 94 + 33;
        encPasswrd.push_back(encPasswrd[i]);

    }
    return encPasswrd;
}

//private member function
//checks if the password entered meets password criteria
//takes entered password as parameter
//returns bool value

bool PasswordManager::meetsCriteria(string newPass)
{
    int countUpper=0,countLower=0;
    bool countSpecial=true;
    if(newPass.length()<15||newPass.length()>127)
        return false;
    else
    {
        for(int i=0; i<newPass.length(); i++)
        {
            if(newPass[i]>='A'&&newPass[i]<='Z')
            {
                countUpper++;

            }
            else if(newPass[i]>='a'&&newPass[i]<='z')
            {
                countLower++;
            }
            else if(newPass[i]=='%'||newPass[i]=='*')
            {
                countSpecial=false;
            }
        }
        if(countUpper>0&&countLower>0&&countSpecial)
        {
            return true;
        }
        else
            return false;
    }
}
void PasswordManager::setUsername(string user)
{
    username = user;        // username is a member var
}
void PasswordManager::setEncryptedPassword(string encPassword)
{
    //encryptedPassword is member var
    encryptedPassword = encPassword;
}

//checks if the password meets criteria and if yes
// then encrypts the password
bool PasswordManager::setNewPassword(string newPass)
{
    string encPassStored;
    if(meetsCriteria(newPass))
    {
        encPassStored = encrypt(newPass);
        setEncryptedPassword(encPassStored);
        return true;
    }
    else
        return false;

}
string PasswordManager::getUsername()
{
    return username;

}

string PasswordManager::getEncryptedPassword()
{
    return encryptedPassword;
}

//authenticates if the entered password
//matches the one present
//returns bool value
bool PasswordManager::authenticate(string passEntered)
{
    if(encryptedPassword==encrypt(passEntered))
    {
        return true;
    }
    else
        return false;

}

