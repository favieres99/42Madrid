#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {}

ATarget::ATarget(std::string t): type(t) {}

ATarget::ATarget(const ATarget &to_copy) { *this = to_copy; }

void ATarget::operator=(const ATarget &to_copy) { type = to_copy.type; }

const std::string &ATarget::getType() const { return (type); }

void ATarget::getHitBySpell(const ASpell &s) const { std::cout << type << " has been " << s.getEffects() << "!" << std::endl; }
