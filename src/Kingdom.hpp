#ifndef KINGDOM_HPP_ 
#define KINGDOM_HPP_ 
#include "King.hpp"
#include "Kingdom.hpp"
#include "Queen.hpp"
#include "Thane.hpp"

#include <vector>

class Kingdom{
	public:
		Character king;
		Character queen;
		std::vector<Character> thanes;


		Kingdom();
		~Kingdom();
};
#endif
