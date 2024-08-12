#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include <map>
#include "SpellBook.hpp" // (EX02)

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _SpellBook; // (EX02)
		Warlock(Warlock const &src);
		Warlock & operator = (Warlock const &rhs);
		//std::map <std::string, ASpell*> _SpellBook; (EX01)

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget &target);
};
#endif
