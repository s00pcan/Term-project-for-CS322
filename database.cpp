#include <vector>
#include <iostream>
#include <fstream>	
#include "teacherType.h"
#include "database.h"

using namespace std;

void database::getteachervec(vector<teacherType>& vecteacher,database& dbase){
		vecteacher = dbaseteacher;
		}
		void database::setteachervec(vector<teacherType> vecteacher,database dbase){
 dbaseteacher = vecteacher;
		} 

