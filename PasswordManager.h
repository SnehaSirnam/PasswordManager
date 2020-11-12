// The PasswordManager class
// Class declaration (specification) in a separate file

#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <string>

using namespace std;

class PasswordManager //new data type
{
private:
    string username;
    string  encryptedPassword;

    string encrypt(string);
    bool meetsCriteria(string);

public:
    void setUsername(string);
    void setEncryptedPassword(string);
    bool setNewPassword(string);
    string getUsername();
    string getEncryptedPassword();
    bool authenticate(string);

};

#endif
