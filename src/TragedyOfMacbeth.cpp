#include <iostream>
#include "Character.hpp"
#include "json/json.h"
#include "TragedyOfMacbeth.hpp"
#include "Act.hpp"
#include "Act1.hpp"

using namespace std;

int main(){
	cout << "initializing" << endl;
	
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

	return 0;
}
