#include "includes/main.hpp"

void	vector_test()
{
	std::cout << "=== Constructors ===" << std::endl;

	ft::vector<std::string> v1;
	ft::vector<std::string> v2(5, "test");

	std::cout << "v2 :" << std::endl;
	for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << std::endl;

	ft::vector<std::string> v3(v2.begin() + 1, v2.end() - 1);
	std::cout << "v3 :" << std::endl;
	for (ft::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << v3.size() << " " << v3.capacity() << std::endl;

	ft::vector<std::string> copy(v3);
	std::cout << "v3 copy : " << std::endl;
	for (ft::vector<std::string>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << copy.size() << " " << copy.capacity() << std::endl;

	v1 = v3;
	std::cout << "v3 assignation : " << std::endl;
	for (ft::vector<std::string>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << std::endl << "=== Iterators ===" << std::endl;
	ft::vector<int> vec;
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	std::cout << "new vector : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "begin : " << *vec.begin() << " - end : " << *vec.end() << " - rbegin : " << *vec.rbegin() << " - rend : " << *vec.rend() << std::endl;

	std::cout << "new vector with reverse_it : " << std::endl;
	for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << std::endl;

	std::cout << "compare it with const_it : " << std::endl;
	ft::vector<int>::iterator co = vec.begin();
	ft::vector<int>::const_iterator cco = vec.begin();
	std::cout << " both = vec.begin() : test == : " << (co == cco) << std::endl;
	

	std::cout << std::endl << "=== Capacity ===" << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.resize(5);
	std::cout << "vector after resize(5) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.resize(12);
	std::cout << "vector after resize(12) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;

	vec.reserve(2);
	std::cout << "vector after reserve(2) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.reserve(20);
	std::cout << "vector after reserve(20) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;

	std::cout << std::endl << "=== Element Access ===" << std::endl;

	std::cout << "vector[3] : " << vec[3] << std::endl;
	std::cout << "vector.at(3) : " << vec.at(3) << std::endl;
	std::cout << "exception with vector.at(13) : " << std::endl;
	try
	{
		std::cout << vec.at(12) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "vector.front : " << vec.front() << " vector.back : " << vec.back() << std::endl;

	std::cout << std::endl << "=== Modifiers ===" << std::endl;

	std::cout << "set a new vector to modify the existing one : " << std::endl;
	ft::vector<int> modif;
	for(int i = 42; i < 47; i++)
		modif.push_back(i);
	for (ft::vector<int>::iterator it = modif.begin(); it != modif.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "assign by range of iterators : " << std::endl;
	vec.assign(modif.begin(), modif.end());
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "assign by fill : vec.assign(4,12) " << std::endl;
	vec.assign(4, 12);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "vec.push_back(45) : " << std::endl;
	vec.push_back(45);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;

	std::cout << "vec.pop_back : " << std::endl;
	vec.pop_back();
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;

	std::cout << "insert single element : " << std::endl;
	vec.insert(vec.begin() + 2, 15);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;
	std::cout << "insert fill : " << std::endl;
	vec.insert(vec.begin() + 4, 3, 21);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;
	std::cout << "insert range of iterators : " << std::endl;
	vec.insert(vec.begin() + 6, modif.begin(), modif.end());
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;

	std::cout << "erase single element : vec.begin() + 3 " << std::endl;
	vec.erase(vec.begin() + 3);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;
	std::cout << "erase range of iterator : vec.begin() + 9 -> vec.begin() + 11 " << std::endl;
	vec.erase(vec.begin() + 9, vec.begin() + 11);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;

	std::cout << "swap : vec.swap(modif) " << std::endl;
	vec.swap(modif);
	std::cout << "Display vec : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << vec.size() << " " << vec.capacity() << std::endl;
	std::cout << "Display modif : " << std::endl;
	for (ft::vector<int>::iterator it = modif.begin(); it != modif.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << modif.size() << " " << modif.capacity() << std::endl;

	std::cout << "clear modif : " << std::endl;
	modif.clear();
	for (ft::vector<int>::iterator it = modif.begin(); it != modif.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "size - capacity : " << modif.size() << " " << modif.capacity() << std::endl;
	std::cout << "empty : " << modif.empty() << std::endl;

	std::cout << std::endl << "=== Allocator ===" << std::endl;
	std::cout << "build an array using a vector get_allocator : " << std::endl;
	ft::vector<int>	test;
	int* p = test.get_allocator().allocate(5);
	for (int i = 0; i < 5; i++)
		test.get_allocator().construct(&p[i], i + 1);
	for (int i = 0; i < 5; i++)
		std::cout << p[i] << std::endl;
	for (int i = 0; i < 5; i++)
		test.get_allocator().destroy(&p[i]);
	test.get_allocator().deallocate(p, 5);

	std::cout << std::endl << "=== Relational operators ===" << std::endl;
	std::cout << "v3 == copy : " << (v3 == copy) << std::endl;
	std::cout << "v3 >= copy : " << (v3 >= copy) << std::endl;
	std::cout << "v3 <= copy : " << (v3 <= copy) << std::endl;
	std::cout << "v3 != copy : " << (v3 != copy) << std::endl;

	ft::vector<int> vec2;
	for (int i = 0; i < 5; i++)
		vec2.push_back(i + 1);
	std::cout << "comparisons between vec2 : " << std::endl;
	for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "and vec : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << std::endl;
	std::cout << "vec2 < vec : " << (vec2 < vec) << std::endl;
	std::cout << "vec2 <= vec : " << (vec2 <= vec) << std::endl;
	std::cout << "vec2 > vec : " << (vec2 > vec) << std::endl;
	std::cout << "vec2 >= vec : " << (vec2 >= vec) << std::endl;
}