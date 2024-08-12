#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "ASpell.hpp"
#include <map>
#include <string>
#include <iostream>

class SpellBook
{
	private :
	SpellBook(SpellBook const & src);
	SpellBook & operator = (SpellBook const & rhs);
	std::map <std::string, ASpell *> _SpellBook;

	public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const & SpellName);
	ASpell* createSpell(std::string const & SpellName);
};
#endif
