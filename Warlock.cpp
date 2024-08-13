#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) :
_name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	//_SpellBook.clear(); (EX01)
}

std::string const & Warlock::getName() const
{
	return _name;
}
std::string const & Warlock::getTitle() const
{
	return _title;
}
void Warlock::setTitle(std::string const &title)
{
	_title = title;
}
void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", "<< _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    _SpellBook.learnSpell(spell); // (EX02)

	//_SpellBook[spell->getName()] = spell->clone(); (EX01)
}
void Warlock::forgetSpell(std::string SpellName)
{
    _SpellBook.forgetSpell(SpellName); // (EX02)

	//if (_SpellBook.find(SpellName) != _SpellBook.end()) (EX01)
		//_SpellBook.erase(_SpellBook.find(SpellName));
}
void Warlock::launchSpell(std::string SpellName, ATarget &target)
{
    if (_SpellBook.createSpell(SpellName))
        _SpellBook.createSpell(SpellName) -> launch(target); // (EX02)

	//if (_SpellBook.find(SpellName) != _SpellBook.end()) (EX01)
		//_SpellBook[SpellName]->launch(target);
}

//Fonctionne a l'examen mais mauvaise gestion memoire voir Valgrind
//Est ce que les leaks sont geres dans les != main de 42? Ce qui expliquerait que ca passe
