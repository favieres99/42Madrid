#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"

class ASpell;

class ATarget 
{
private:
	std::string type;

public:
	ATarget();
	ATarget(std::string t);
	virtual ~ATarget();
	ATarget(const ATarget &to_copy);
	void operator=(const ATarget &to_copy);
	
	const std::string &getType() const;	
	virtual ATarget *clone() const = 0;
	void getHitBySpell(const ASpell &s) const;
};

#endif
