#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string name;
	std::string effects;

public:
	ASpell();
	ASpell(std::string n, std::string e);
	virtual ~ASpell();
	ASpell(const ASpell &to_copy);
	void operator=(const ASpell &to_copy);

	const std::string &getName() const;
	const std::string &getEffects() const;
	virtual ASpell *clone() const = 0; 
	void launch(const ATarget &t);
};

#endif
