#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
private:
	std::vector<ASpell *> spells;
	
	SpellBook(const SpellBook &to_copy);
	void operator=(const SpellBook &to_copy);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *s);
	void forgetSpell(const std::string &s);
	ASpell *createSpell(const std::string &s);
};

#endif
