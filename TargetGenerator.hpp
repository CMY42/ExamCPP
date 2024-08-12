#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "ATarget.hpp"
#include <map>
#include <string>
#include <iostream>

class TargetGenerator
{
	private :
	TargetGenerator(TargetGenerator const & src);
	TargetGenerator & operator = (TargetGenerator const & rhs);
	std::map <std::string, ATarget *> _TargetBook;

	public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const & target);
	ATarget* createTarget(std::string const & target);
};
#endif
