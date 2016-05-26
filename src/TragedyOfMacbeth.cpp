#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Character.hpp"
#include "json/json.h"
#include "TragedyOfMacbeth.hpp"

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


	const Json::Value &val = root[0];

	int i=0;

	vector<pair<string,string>> EntirePlayLines;

	for (Json::ValueConstIterator it = root.begin(); it != root.end(); ++it){
		const Json::Value &temp = *it;
		if(temp.get("play_name", "error").compare("macbeth") == 0){
			if (temp.get("speaker","error").compare("ADRIANO DE ARMADO") != 0){
				cout << temp.get("line_id","error") << endl; 
			}
			pair<string,string> currentpair = make_pair(temp.get("speaker","error").asString(),
														temp.get("text_entry","error").asString());
			EntirePlayLines.push_back(currentpair);
		}
		i++;
	}

	string currentspeaker = "";

	for(vector<pair<string,string>>::const_iterator i = EntirePlayLines.begin(); i != EntirePlayLines.end(); ++i){
		if ((*i).first.compare(currentspeaker) != 0){
			cout << endl << (*i).first << ": ";
			currentspeaker = (*i).first;
		}
		int len = currentspeaker.length();
		

		cout << "  " << (*i).second << endl;
	}

	cout << endl;




	cout << "about to return" << endl;
	return 0;
}
