// include teacherType header file if not defined
#ifndef H_teacherType
#define H_teacherType

#include <string>					// needed for string use
#include <vector>					// needed for vector use

using namespace std;				// allow use of standard namespace

/*** definition of teacherType class ***/
class teacherType
{
public:
	void setTeacher(int id, string first, string last, string email,int phone);
	void getTeacher(int& id, string& first, string& last, string& email,int& phone);
protected:
	int	tchid;
	string firstName;		// stores the first name
	string lastName;		// stores the last name
	string tchemail;
	int tchphone;
};

#endif