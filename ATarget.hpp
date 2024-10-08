#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;

	public:
		ATarget(std::string type);
		virtual ~ATarget();
		ATarget(ATarget const & src);
		ATarget & operator = (ATarget const & rhs);
		std::string const & getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;
};

#endif
