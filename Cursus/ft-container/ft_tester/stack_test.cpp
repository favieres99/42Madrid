#include "includes/main.hpp"

void	stack_test()
{
	ft::stack<int> st;
	std::cout << "Empty : " << st.empty() << std::endl;
	std::cout << "using push(3) : ";
	st.push(3);
	std::cout << "Empty now : " << st.empty() << std::endl;
	std::cout << "Size : " << st.size() << " - Top : " << st.top() << std::endl;
	std::cout << "Push a second element (5)" << std::endl;
	st.push(5);
	std::cout << "Size : " << st.size() << " - Top : " << st.top() << std::endl;
	std::cout << "using pop, new top : ";
	st.pop();
	std::cout << st.top() << std::endl;


	std::cout << std::endl << "=== Comparisons ===" << std::endl;
	std::cout << "2 stacks : foo = three ints with a value of 100, bar = two ints with a value of 200" << std::endl;
	
	ft::stack<int> foo;
	foo.push(300);
	foo.push(300);
	foo.push(300);

	ft::stack<int> bar;
	bar.push(200);
	bar.push(200);

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}