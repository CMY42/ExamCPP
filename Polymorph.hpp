#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"
#include <string>
#include <iostream>

class Polymorph : public ASpell
{
	public:
	Polymorph();
	~Polymorph();
	ASpell *clone()const;
};
#endif
