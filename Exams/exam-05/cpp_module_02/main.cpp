#include "ASpell.hpp"		
#include "Dummy.hpp"		
#include "Polymorph.hpp"		
#include "Warlock.hpp"
#include "ATarget.hpp"		
#include "Fireball.hpp"		
#include "SpellBook.hpp"
#include "BrickWall.hpp"		
#include "Fwoosh.hpp"
#include "TargetGenerator.hpp"

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
  
  richard.forgetSpell("Polymorph");
  std::cout << "l" << std::endl;
  richard.forgetSpell("cdedeed");
  std::cout << "l1" << std::endl;
  richard.forgetSpell("Fireball");
  std::cout << "l2" << std::endl;
  richard.forgetSpell("cdedeed");
  std::cout << "l3" << std::endl;
  richard.launchSpell("Polymorph", *wall);
  std::cout << "l4" << std::endl;
  richard.launchSpell("Fireball", *wall);
  std::cout << "l5" << std::endl;
  richard.learnSpell(0);
  std::cout << "l6" << std::endl;
  richard.launchSpell("wddwdw", model1);

  tarGen.forgetTargetType("Inconspicuous Red-brick Wall");
}
