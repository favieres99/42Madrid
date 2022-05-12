#ifndef TARGETGENERATOR
#define TARGETGENERATOR

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
private:
	std::vector<ATarget *> targets;	
	
	TargetGenerator(const TargetGenerator &t);
	void operator=(const TargetGenerator &t);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* t);
 	void forgetTargetType(const std::string &t);
 	ATarget *createTarget(const std::string &t);  
};

#endif
