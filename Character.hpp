/*
 * Character class definitions
 * Created by Casey Chesshir
 * May 5, 2016
 */

 #ifndef CHARACTER_HPP_
 #define CHARACTER_HPP_

 #include <iostream>
 #include <string>

using namespace std;

 class Character{
 public:
 	Character(string name);
	~Character();
	string name;
	void speak();
 };

 #endif
