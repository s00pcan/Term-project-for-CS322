#ifndef H_auth
#define H_auth

#include <string>
#include <vector>

using namespace std;

class auth
{
public:
	auth();
	// login method
	// Precondition: 
	// Postcondition: 
	static bool login(string username, string password);
	// changePassword methods
	// Precondition: 
	// Postcondition: 
	static bool changePassword(string username, string oldPassword, string newPassword1, string newPassword2);
	static bool changePassword(string username, string oldPassword, string newPassword);
	// addUser method
	// Precondition: 
	// Postcondition: 
	static bool addUser(string username, string password);
	// removeUser method
	// Precondition: 
	// Postcondition: 
	static bool removeUser(string username, string password);
protected:
private:
	static const string salt;
	static const string loginFilename;
	// loadFile method
	// Precondition: 
	// Postcondition: 
	static vector<string> loadFile();
	// saveFile method
	// Precondition: 
	// Postcondition: 
	static void saveFile(vector<string>);
};

#endif