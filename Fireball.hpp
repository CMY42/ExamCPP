#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "ASpell.hpp"
#include <string>
#include <iostream>

class Fireball : public ASpell
{
	public:
	Fireball();
	~Fireball();
	ASpell *clone()const;
};
#endif
