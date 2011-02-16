#include <iostream>					// needed for input/output
#include <string>					// needed for string use

// include header file
#include "teacherType.h"
	
using namespace std;				// allow use of standard namespace



void teacherType::setTeacher(int id, std::string first, std::string last, std::string email, int phone)
{
	// set first and last name
	tchid = id;
	firstName = first;
	lastName = last;
	tchemail = email;
	tchphone = phone;
}


/*** function to get the name ***/
void teacherType::getTeacher(int &id, std::string &first, std::string &last, std::string &email, int &phone)
{
	// get the name and set it
	id = tchid;
	first = firstName;
	last = lastName;
	email = tchemail;
	phone = tchphone;
}


