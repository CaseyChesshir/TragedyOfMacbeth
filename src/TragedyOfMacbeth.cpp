#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Character.hpp"
#include "json/json.h"
#include "TragedyOfMacbeth.hpp"
#include "Act.hpp"
#include "Act1.hpp"

using namespace std;

int main(){
	cout << "initializing" << endl;
	
	Json::Value root;
	Json::Reader reader;
	
	


	filebuf fb;
	fb.open("working.json", ios::in);
	istream is(&fb);


	bool parsingSuccessful = reader.parse( is, root );

	if ( !parsingSuccessful )
	{
		// report to the user the failure and their locations in the document.
		std::cout  << "Failed to parse configuration\n"
				   << reader.getFormattedErrorMessages();
		return 1;
	}


	cout << "root[0]: " << root[0] << endl;
	cout << "root[1]: " << root[1] << endl;

	const Json::Value &val = root[0];


//	string wow = root[0].toStyledString();

//	cout << "wow: " << wow << endl;


	cout << "omg: " << root[0].get("play_name", "error") << endl;

	int i=0;


	vector<string> EntirePlayLines;

	for (Json::ValueConstIterator it = root.begin(); it != root.end(); ++it){
		advance(it,55779);
		const Json::Value &temp = *it;
		cout << temp.get("text_entry","error") << endl;
		if(temp.get("play_name", "error").compare("macbeth") == 0){
			cout << temp.get("line_id","error") << endl; 
			exit(0);
			cout << temp.get("text_entry","error") << endl;
			EntirePlayLines.push_back(temp.get("text_entry","error").asString());
		}
		i++;
	}

	Act1 act1;
	act1.Scene1();
	act1.Scene2();
	act1.Scene3();
	act1.Scene4();
	act1.Scene5();
	act1.Scene6();
	act1.Scene7();

	Act2 act2;
	act2.Scene1();
	act2.Scene2();
	act2.Scene3();
	act2.Scene4();

	Act3 act3;
	act3.Scene1();
	act3.Scene2();
	act3.Scene3();
	act3.Scene4();
	act3.Scene5();
	act3.Scene6();

	Act4 act4;
	act4.Scene1();
	act4.Scene2();
	act4.Scene3();

	Act5 act5;
	act5.Scene1();
	act5.Scene2();
	act5.Scene3();
	act5.Scene4();
	act5.Scene5();
	act5.Scene6();
	act5.Scene7();
	act5.Scene8();


	cout << "about to return" << endl;
	return 0;
}
