#include "Character.hpp"
#include <string>
#include <iostream>
#include <locale>

Character::Character(string name, std::vector<string> &playlines){
	ofWomanBorn = true;
	if (name.compare("MACDUFF") == 0){
		ofWomanBorn = false;
	}
	std::locale loc;
	std::vector<string>::iterator it = playlines.begin();
	while(it != playlines.end()){
		if((*it).compare(toupper(name,loc))){
			lines.push_back((*it));
		}
	}
}

Character::~Character(){

}

void Character::speak(){
	cout << lines.back() << endl;
	lines.pop_back();
}

void Character::killMacbeth(Character macbeth){
	
	if (!ofWomanBorn){
		delete &macbeth;
	}
}
