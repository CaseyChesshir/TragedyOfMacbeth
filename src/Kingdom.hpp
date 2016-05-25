#ifndef THANE_HPP_
#define THANE_HPP_

#include <vector>

class Kingdom{
	public:
		King king;
		Queen queen;
		std::vector<Thane> thanes;
		Army army;
};
#endif
