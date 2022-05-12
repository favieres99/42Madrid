#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* t)
{
	ATarget *target;

	if (t == 0)
		return ;
	target = createTarget(t->getType());
	if (!target)
		targets.push_back(t);	
}

void TargetGenerator::forgetTargetType(const std::string &t)
{
	std::vector<ATarget *>::iterator i;

	i = targets.begin();
	while (i != targets.end())
	{
		if ((*i)->getType() == t)
		{
			targets.erase(i);
			return ;
		}
		i++;
	}
}

ATarget *TargetGenerator::createTarget(const std::string &t)
{
	std::vector<ATarget *>::iterator i;

	i = targets.begin();
	while (i != targets.end())
	{
		if ((*i)->getType() == t)
			return (*i);
		i++;
	}
	return (0);
}
