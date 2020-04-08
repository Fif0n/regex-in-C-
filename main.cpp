#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

class regular{
       ifstream plik1;
       ofstream plik2;

  public:
        regular();
        ~regular();
       
        void checkregular();        
};

regular::regular(){
    plik1.open("c:\\od.txt");
    plik2.open("c:\\do.txt");
}

void regular::checkregular(){
	string code;
	regex regularne("[0-9]{2}-[0-9]{3}");
	while(!plik1.eof()){
		plik1>>code;
		if(regex_match(code,regularne)){
			plik2<<code<<endl;
		}
	}
	              
}

regular::~regular(){
    plik1.close();
    plik2.close();
}

int main() {
    regular r1;
    r1.checkregular();
    return 0;
}
