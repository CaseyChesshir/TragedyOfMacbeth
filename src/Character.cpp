#include "Character.hpp"
#include <string>
#include <iostream>
#include <locale>

Character::Character(string name, std::vector<string> &playlines){
	std::locale loc;
	std::vector<string>::iterator it = playlines.begin();
	while(it != playlines.end()){
		if((*it).compare(toupper(name,loc))){
			lines.push_back((*it));
		}
	}
}

void Character::speak(){
	cout << lines.back() << endl;
	lines.pop_back();
}


