#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(std::string n, std::string e): name(n), effects(e) {}

ASpell::ASpell(const ASpell &to_copy) { *this = to_copy; }

void ASpell::operator=(const ASpell &to_copy)
{
	name = to_copy.name;
	effects = to_copy.effects;
}

const std::string &ASpell::getName() const { return (name); }

const std::string &ASpell::getEffects() const { return (effects); }

void ASpell::launch(const ATarget &t) { t.getHitBySpell(*this); }
