#ifndef KINGDOM_HPP_ 
#define KINGDOM_HPP_ 
#include "King.hpp"
#include "Queen.hpp"
#include "Thane.hpp"

#include <vector>

class Kingdom{
	public:
		King king;
		Queen queen;
		std::vector<Thane> thanes;
};
#endif
