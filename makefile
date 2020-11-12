#makefile

a.out: PasswordManager.o PasswordDriver.o
	g++ PasswordManager.o PasswordDriver.o
PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -c PasswordDriver.cpp
PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -c PasswordManager.cpp
	