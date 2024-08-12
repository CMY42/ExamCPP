#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}
SpellBook::~SpellBook()
{
	for (auto it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
		delete it->second; //it->second est la valeur ici pointeur ASpell*		//EXAM PASSE SANS?

	_SpellBook.clear();
}
void SpellBook::learnSpell(ASpell* spell)
{
	if (spell) // EXAM PASSE SANS?
	_SpellBook[spell->getName()] = spell->clone();
}
void SpellBook::forgetSpell(std::string const & SpellName)
{
	/*auto it = _SpellBook.find(SpellName);
	if (it != _SpellBook.end())
	{
		delete it->second; // Libère l'objet avant de le retirer de la map
		_SpellBook.erase(it);
	}*/ // Version correcte pour gestion memoire

	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName));
}
ASpell* SpellBook::createSpell(std::string const & SpellName)
{
	ASpell* tmp = nullptr;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		tmp = _SpellBook[SpellName];  // Renvoie le pointeur vers l'objet existant

	return tmp;
}

//gestion de la mémoire des objets ASpell a realiser ailleurs? Main?
