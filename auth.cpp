#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <iterator>
#include <sstream>
#include "auth.h"
#include "md5.h"

using namespace std;

string trim(string& str);
vector<string> split(string str, char del);

// Start of auth class implementation
const string auth::salt = "lolmd5";
const string auth::loginFilename = "logins.txt";

auth::auth(){
	
}
vector<string> auth::loadFile(){
	vector<string> lines;
	ifstream inDocument;
	inDocument.open(auth::loginFilename);

	// Read the document to be checked
	if (!inDocument){
		cerr << "Unable to open file " << auth::loginFilename << endl;
	} else {
		string readLine;	

		while(inDocument.eof() == false){
			getline(inDocument,readLine);
			lines.push_back(readLine);
		}
	}

	inDocument.close();
	return lines;
}
void auth::saveFile(vector<string> logins){
	ofstream oFile;
	vector<string>::iterator vi;

	// Open the output file
	oFile.open(auth::loginFilename.c_str());
	
	// Write the lines to the file
	for (vi=logins.begin();vi!=logins.end();vi++){
		if (trim(*vi) != ""){
			oFile << *vi << endl;
		}
	}

	oFile.close();
}
bool auth::removeUser(string username, string password){
	vector<string> logins = auth::loadFile();
	vector<string>::iterator vi;
	bool found = false;

	// Loop through the logins file for a matching username. If one is found, return false
	// If one is not found, return false.
	for (vi=logins.begin();vi!=logins.end();vi++){
		vector<string> loginVec = split(*vi,',');
		string loginUsername = "";
		string loginHash = "";

		if (trim(*vi) != ""){
			loginUsername = trim(loginVec[0]);
			loginHash = trim(loginVec[1]);
			
			if (loginUsername == username && auth::login(username,password)){
				found = true;
				*vi = "";
				break;
			}
		}
	}

	if (found){
		auth::saveFile(logins);
	}

	return found;
}
bool auth::addUser(string username, string password){
	vector<string> logins = auth::loadFile();
	vector<string>::iterator vi;

	// Loop through the logins file for a matching username. If one is found, return false
	// If one is not found, return false.
	for (vi=logins.begin();vi!=logins.end();vi++){
		vector<string> loginVec = split(*vi,',');
		string loginUsername = "";
		string loginHash = "";

		if (trim(*vi) != ""){
			loginUsername = trim(loginVec[0]);
			loginHash = trim(loginVec[1]);
			
			if (username == loginUsername){
				return false; // User already exists
			}
		}
	}

	logins.push_back(username + "," + md5(auth::salt+trim(username)+trim(password)));
	auth::saveFile(logins);
	return true;
}
bool auth::changePassword(string username, string oldPassword, string newPassword1, string newPassword2){
	if (newPassword1 == newPassword2){
		return auth::changePassword(username, oldPassword, newPassword1);
	} else {
		return false;
	}
}
bool auth::changePassword(string username, string oldPassword, string newPassword){
	vector<string> logins = auth::loadFile();
	vector<string>::iterator vi;

	// Loop through the logins file for a matching username and hash. If one is found, consider the user authenticated
	// If one is not found, return false.
	for (vi=logins.begin();vi!=logins.end();vi++){
		vector<string> loginVec = split(*vi,',');
		string loginUsername = "";
		string loginHash = "";

		if (trim(*vi) != ""){
			loginUsername = trim(loginVec[0]);
			loginHash = trim(loginVec[1]);
		}

		if (username == loginUsername){
			if (auth::login(username,oldPassword)){
				*vi = username + "," + md5(auth::salt+trim(username)+trim(newPassword));
				auth::saveFile(logins);
				return true;
			} else {
				cerr << "Invalid password for user \"" << username << "\"" << endl;
				return false;
			}
		}
	}

	cerr << "Invalid username/password" << endl;
	return false;
}
bool auth::login(string username, string password){
	// Construct passwords using the md5 algorithm
	// The input is a concatenated string consisting of the salt, the username entered, and the password given.
	// e.g. md5("lolmd5chrispassword") = "53ec5bbab50d715f882485af18358b4e"
	// This stops people from simply switching passwords around to login as different users or using a lookup table
	string hash = md5(auth::salt+trim(username)+trim(password));

	vector<string> logins = auth::loadFile();
	vector<string>::iterator vi;

	// Loop through the logins file for a matching username and hash. If one is found, consider the user authenticated
	// If one is not found, return false.
	for (vi=logins.begin();vi!=logins.end();vi++){
		if (trim(*vi) != ""){
			vector<string> loginVec = split(*vi,',');
			string loginUsername = trim(loginVec[0]);
			string loginHash = trim(loginVec[1]);

			if (loginUsername == username && loginHash == hash){
				return true;
			}
		}
	}

	cerr << "Bad username/password" << endl;
	return false;
}
// End of auth class

string trim(string& str){
	const string blank = "";
	regex rgxTrim("^\\s+|\\s+$");
	str = std::tr1::regex_replace(str, rgxTrim, blank);
	return str;
}
vector<string> split(string str, char del){
	string token, text(str);
	istringstream iss(text);
	vector<string> vec = vector<string>();
		
	while (getline(iss, token, del)){
		vec.push_back(token);
	}

	return vec;
}