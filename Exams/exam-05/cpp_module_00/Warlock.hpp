#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;
		
	Warlock();
	Warlock(const Warlock &to_copy);
	void operator=(const Warlock &to_copy);

public:
	Warlock(std::string n, std::string t);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &t);	
	void introduce() const;
};

#endif
