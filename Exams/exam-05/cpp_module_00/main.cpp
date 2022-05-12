#include "Warlock.hpp"

int main()
{
//	Warlock bob;                            //Does not compile
//	Warlock bob1("Bob", "the magnificent");  //Compiles
//	Warlock jim1("Jim", "the nauseating");   //Compiles
//	bob1 = jim1;                              //Does not compile
//	Warlock jack1(jim1);                      //Does not compileE

    Warlock const richard("Richard", "Mistress of Magma");
    richard.introduce();
    std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
 
    Warlock* jack = new Warlock("Jack", "the Long");
    jack->introduce();
    jack->setTitle("the Mighty");
    jack->introduce();
 
    delete jack;
 
    return (0);
}
