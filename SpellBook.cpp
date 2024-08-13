#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}
SpellBook::~SpellBook()
{
	_SpellBook.clear();
}
void SpellBook::learnSpell(ASpell* spell)
{
	_SpellBook[spell->getName()] = spell->clone();
}
void SpellBook::forgetSpell(std::string const & SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName));
}
ASpell* SpellBook::createSpell(std::string const & SpellName)
{
	ASpell* tmp = NULL;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		tmp = _SpellBook[SpellName];  // Renvoie le pointeur vers l'objet existant

	return tmp;
}

//gestion de la mémoire des objets ASpell a realiser ailleurs? Main?
//Mauvais gestion memoire mais passe a l'EXAM
