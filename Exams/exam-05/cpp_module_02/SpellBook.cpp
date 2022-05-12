#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *s)
{
	ASpell *spell;

	if (s == 0)
		return ;
	spell = createSpell(s->getName());
	if (!spell)
		spells.push_back(s);
}

void SpellBook::forgetSpell(const std::string &s)
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

ASpell *SpellBook::createSpell(const std::string &s)
{
	std::vector<ASpell *>::iterator i;

	i = spells.begin();
	while (i != spells.end())
	{
		if ((*i)->getName() == s)
			return (*i);
		i++;
	}
	return (0);
}
