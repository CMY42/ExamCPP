#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;

	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();
		ASpell(ASpell const & src);
		ASpell & operator = (ASpell const & rhs);
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(ATarget const & target) const;
};

#endif
