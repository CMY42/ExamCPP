#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}
TargetGenerator::~TargetGenerator()
{
	_TargetBook.clear();
}
void TargetGenerator::learnTargetType(ATarget* target)
{
	_TargetBook[target->getType()] = target -> clone();
}
void TargetGenerator::forgetTargetType(std::string const & target)
{
	if (_TargetBook.find(target) != _TargetBook.end())
		_TargetBook.erase(_TargetBook.find(target));
}
ATarget* TargetGenerator::createTarget(std::string const & target)
{
	ATarget* tmp = NULL;
	if (_TargetBook.find(target) != _TargetBook.end())
		tmp = _TargetBook[target];
	return (tmp);
}

//gestion de la mémoire des objets ATarget a realiser a la place de simplement clear le Book
//passe a l'Exam mais mauvaise gestion memoire
