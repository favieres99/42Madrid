#include "Warlock.hpp"

Warlock::Warlock(std::string n, std::string t)
{
	name = n;
	title = t;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << name << ": My job here is done!" << std::endl; }

const std::string &Warlock::getName() const { return (name); }

const std::string &Warlock::getTitle() const { return (title); }

void Warlock::setTitle(const std::string &t) { title = t; }

void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!"<< std::endl; }

void Warlock::learnSpell(ASpell *s) { SB.learnSpell(s); }

void Warlock::forgetSpell(std::string s) { SB.forgetSpell(s); }

void Warlock::launchSpell(std::string s, ATarget &t) 
{ 
	ASpell *spell;
	
	spell = SB.createSpell(s);
	if (spell)
		spell->launch(t);
}