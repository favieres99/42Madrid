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

void Warlock::learnSpell(ASpell *s) 
{ 
	std::vector<ASpell *>::iterator i;

	i = spells.begin();
	while (i != spells.end())
	{
		if ((*i)->getName() == s->getName())
			return ;
		i++;
	}
	spells.push_back(s); 
}

void Warlock::forgetSpell(std::string s) 
{ 
	std::vector<ASpell *>::iterator i;

	i = spells.begin();
	while (i != spells.end())
	{
		if ((*i)->getName() == s)
		{
			spells.erase(i);
			return ;
		}
		i++;
	}
}

void Warlock::launchSpell(std::string s, ATarget &t)
{
	std::vector<ASpell *>::iterator i;

	i = spells.begin();
	while (i != spells.end())
	{
		if ((*i)->getName() == s)
			t.getHitBySpell(**i);
		i++;
	}
}
