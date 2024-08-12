#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}
TargetGenerator::~TargetGenerator()
{
	for (auto it = _TargetBook.begin(); it != _TargetBook.end(); ++it)
		delete it->second; //it->second est la valeur ici pointeur ATarget*		//EXAM PASSE SANS?

	_TargetBook.clear();
}
void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target) // EXAM PASSE SANS?
		_TargetBook[target->getType()] = target;
}
void TargetGenerator::forgetTargetType(std::string const & target)
{
	/*auto it = _TargetBook.find(target);
	if (it != _TargetBook.end())
	{
		delete it->second; // Libère l'objet avant de le retirer de la map
		_TargetBook.erase(it);
	}*/ // VERSION CORRECTE AVEC GESTION MEMOIRE

	if (_TargetBook.find(target) != _TargetBook.end())
		_TargetBook.erase(_TargetBook.find(target));
}
ATarget* TargetGenerator::createTarget(std::string const & target)
{
	ATarget* tmp = nullptr;
	if (_TargetBook.find(target) != _TargetBook.end())
		tmp = _TargetBook[target];
	return (tmp);
}

//gestion de la mémoire des objets ATarget a realiser a la place de simplement clear le Book
