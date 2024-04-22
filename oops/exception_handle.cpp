#include<bits/stdc++.h>

using namespace std;

class Printer{
	int _AvailablePage;
	string _name;
public:
	Printer(string name, int page){
		_AvailablePage = page;
		_name = name;

	}
	void Print(string docName){
		int requiredPaper = docName.length()/10;
		if(requiredPaper > _AvailablePage){
			throw 402;
		}
		cout<<"Printing....."<<docName<<endl;
		_AvailablePage-= requiredPaper;
	}
};
int main(){
	Printer p("Hp jetpack compose", 12);
	try
	{
		p.Print("Hey myself siddhu, i am a Software Engineer");
		p.Print("Hey myself siddhu, i am a Software Engineer");
		p.Print("Hey myself siddhu, i am a Software Engineer");
		p.Print("Hey myself siddhu, i am a Software Engineer");
		p.Print("Hey myself siddhu, i am a Software Engineer");
	}
	catch(const char exp){
		cout<<"Exception occured"<<exp<<endl;
	}
	catch(int exp){
		cout<<"Exception occured"<<exp<<endl;
	}
	catch(...){
		cout<<"Exception occured";
	}
	
	
}