#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock {
    private:
        std::string _name;
        std::string _title;

        Warlock();
        Warlock(Warlock const &);
        Warlock & operator=(Warlock const &);

        std::map < std::string, ASpell * > _SpellBook;

    public:
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();
        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const & title);
        void introduce() const;
        void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget const & target);
};
