#ifndef H_database
#define H_database

#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>	
#include "teacherType.h"
class database
{
public:
	void getteachervec(vector<teacherType>& vecteacher,database& dbase);
	void setteachervec(vector<teacherType> vecteacher,database dbase);

	double studbasesize;
	double tchdbasesize;
	double crsdbasesize;
	double condbasesize;
	vector<teacherType> dbaseteacher;
};
#endif