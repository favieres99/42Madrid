#include <map>
#include <iostream>

void map_test()
{
	std::cout << std::endl << "===== STD::MAP TESTS =====" << std::endl << std::endl;

	std::cout << std::endl << "===== Constructors =====" << std::endl << std::endl;
	std::cout << "Create an empty map m1 and fill it with insert fct : " << std::endl;
	std::map<int, std::string> m1;
	m1.insert(std::pair<int, std::string> (15, "quinze"));
	m1.insert(std::pair<int, std::string> (1, "un"));
	m1.insert(std::pair<int, std::string> (32, "trente deux"));
	m1.insert(std::pair<int, std::string> (25, "vingt cinq"));
	m1.insert(std::pair<int, std::string> (12, "douze"));
	m1.insert(std::pair<int, std::string> (21, "vingt et un"));
	std::cout << "Display m1 : " << std::endl;
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::map<int, std::string>::iterator itb = ++m1.begin();
	std::map<int, std::string>::iterator ite = --m1.end();
	ite--;
	std::cout << "Create a map m2 with a range of iterators from " << itb->first << " to " << ite->first << std::endl;
	std::map<int, std::string> m2(itb, ite);
	std::cout << "Display m2 : " << std::endl;
	for (std::map<int, std::string>::iterator it = m2.begin(); it != m2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Create a copy map of m1 using copy constructor : " << std::endl;
	std::map<int, std::string> copy(m1);
	std::cout << "Display copy : " << std::endl;
	for (std::map<int, std::string>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Create a copy2 map of m1 using assignation operator : " << std::endl;
	std::map<int, std::string> copy2 = m1;
	std::cout << "Display copy2 : " << std::endl;
	for (std::map<int, std::string>::iterator it = copy2.begin(); it != copy2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "===== Iterators =====" << std::endl << std::endl;
	std::cout << "Display m1 from rbegin to rend :" << std::endl;
	for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Compare iterators : " << std::endl;
	std::map<int, std::string>::iterator itc = m1.begin();
	std::map<int, std::string>::const_iterator citc = m1.begin();
	std::cout << "m1.begin() == const m1.begin() : " << (itc == citc) << std::endl;
	std::cout << "m1.begin() != const m1.begin() : " << (itc != citc) << std::endl;

	std::cout << std::endl << "===== Capacity =====" << std::endl << std::endl;
	std::cout << "m1 size : " << m1.size() << " - empty : " << m1.empty() << " - max size : " << m1.max_size() << std::endl;

	std::cout << std::endl << "===== Element access =====" << std::endl << std::endl;
	std::cout << "access elements with m1[key] : " << std::endl;
	std::cout << "m1[1] : " << m1[1] << " - m1[32] : " << m1[32] << " - m1[21] : " << m1[21] << std::endl;
	std::cout << "insert an element using a non existing key, m1[4] = quatre, and display m1" << std::endl;
	m1[4] = "quatre";
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "===== Modifiers =====" << std::endl << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool> ret_insert = m1.insert(std::make_pair(1, "test"));
	std::cout << "insert on an already existing key, return : iterator key : " << ret_insert.first->first \
	<< " - value : " << ret_insert.first->second << " - bool : " << ret_insert.second << std::endl;
	ret_insert = m1.insert(std::make_pair(27, "vingt-sept"));
	std::cout << "insert on a non-existing key, return : iterator key : " << ret_insert.first->first \
	<< " - value : " << ret_insert.first->second << " - bool : " << ret_insert.second << std::endl;

	ret_insert = m1.insert(std::make_pair(12, "pouic"));
	std::map<int, std::string>::iterator douze = ret_insert.first;
	std::map<int, std::string>::iterator onze = m1.insert(douze, std::make_pair(11, "onze"));
	std::cout << "insert 11 with an hint position 12 - ret iterator : " << onze->first << " - " << onze->second << std::endl;

	std::map<int, std::string>::iterator treize = m1.insert(douze, std::make_pair(13, "treize"));
	std::cout << "insert 13 with an hint position 12 - ret iterator : " << treize->first << " - " << treize->second << std::endl;


	std::cout << std::endl << "Create a new m3 map and display it : " << std::endl;
	std::map<int, std::string> m3;
	m3.insert(std::pair<int, std::string> (-10, "moins dix"));
	m3.insert(std::pair<int, std::string> (427, "Quatre cent vingt-sept"));
	m3.insert(std::pair<int, std::string> (8, "huit"));
	for (std::map<int, std::string>::iterator it = m3.begin(); it != m3.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
	std::cout << std::endl << "use m3.begin() and m3.end() as iterators to insert in m1, display m1 : " << std::endl;
	m1.insert(m3.begin(), m3.end());
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;


	ret_insert = m1.insert(std::make_pair(25, "pouic"));
	std::cout << std::endl << "Erase 25 by iterator and print m1: " << std::endl;
	std::map<int, std::string>::iterator vingtcinq = ret_insert.first;
	m1.erase(vingtcinq);
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Erase 427 by key and print the return : " << std::endl;
	size_t ret1 = m1.erase(427);
	std::cout << "ret1 : " << ret1 << std::endl;
	std::cout << "Try to erase 321 (that doesn't exist) by key and print the return : " << std::endl;
	size_t ret2 = m1.erase(321);
	std::cout << "ret2 : " << ret2 << std::endl;

	std::map<int, std::string>::iterator itt = m1.begin();
	itt++;
	itt++;
	std::map<int, std::string>::iterator ittee = m1.end();
	ittee--;

	std::cout << std::endl << "Erase by range between " << "itt : " << itt->first << " and ittee : " << ittee->first << std::endl;
	m1.erase(itt, ittee);
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
		std::cout << "size : " << m1.size() << std::endl;

	std::cout << std::endl << "Swap m1 and m3, print them : " << std::endl;
	m1.swap(m3);
	std::cout << "m1 : " << std::endl;
	for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
	std::cout << "m3 : " << std::endl;
	for (std::map<int, std::string>::iterator it = m3.begin(); it != m3.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "clear m3 and print its size : " << std::endl;
	m3.clear();
	std::cout << "size of m3 : " << m3.size() << std::endl;

	std::cout << std::endl << "===== Observers =====" << std::endl << std::endl;
	std::map<char,int> mymap;
	std::cout << "make a new mymap and use its key_comp() to print it : " << std::endl;
	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;// key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	std::cout << std::endl << "make a new mymap2 and use its value_comp() to print it : " << std::endl;
	std::map<char,int> mymap2;

	mymap2['x']=1001;
	mymap2['y']=2002;
	mymap2['z']=3003;

	std::cout << "mymap2 contains:\n";

	std::pair<char,int> highest2 = *mymap2.rbegin();// last element

	std::map<char,int>::iterator it2 = mymap2.begin();
	do {
	std::cout << it2->first << " => " << it2->second << '\n';
	} while ( mymap2.value_comp()(*it2++, highest2) );

	std::map<int, std::string>::iterator un = m1.find(1);
	std::map<int, std::string>::iterator huit = m1.find(8);
	std::cout << std::endl << "Create an iterator huit = m1.find(8) and un m1.find(1). As 1 doesn't exit in m1, un should be egal to end" << std::endl << "display m1 from huit to un (end) : "  << std::endl;
	for (std::map<int, std::string>::iterator it = huit; it != un; it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << "Use m1.count(1) : " << m1.count(1) << " and m1.count(8) : " << m1.count(8) << std::endl;
	std::cout << std::endl << "Make a new mymap3 and print it :" << std::endl;
	std::map<char,int> mymap3;
	std::map<char,int>::iterator itlow,itup;

	mymap3['a']=20;
	mymap3['b']=40;
	mymap3['c']=60;
	mymap3['d']=80;
	mymap3['e']=100;

	for (std::map<char, int>::iterator it = mymap3.begin(); it != mymap3.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	itlow=mymap3.lower_bound ('b');// itlow points to b
	itup=mymap3.upper_bound ('d');// itup points to e (not d!)

	std::cout << "itlow = mymap3.lower_bound('b') : " << itlow->first << " itup = mymap3.upper_bound('e') : " << itup->first << std::endl;
	std::cout << "erase(itlow, itup) and display : " << std::endl;
	mymap3.erase(itlow,itup);// erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap3.begin(); it!=mymap3.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int> mymap4;

	mymap4['a']=10;
	mymap4['b']=20;
	mymap4['c']=30;

	std::cout << std::endl << "make a new mymap4 : " << std::endl;
	for (std::map<char, int>::iterator it = mymap4.begin(); it != mymap4.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << "rett<iterator, iterator> = mymap4.equal_range('b') : " << std::endl;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> rett;
	rett = mymap4.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << rett.first->first << " => " << rett.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << rett.second->first << " => " << rett.second->second << '\n';

	int psize;
	std::map<char,int> mymap5;
	std::pair<const char,int>* p;
	std::cout << std::endl << "use allocator of mymap5 : p = get_allocator().allocate(5)" << std::endl;
	// allocate an array of 5 elements using mymap's allocator:
	p=mymap5.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap5.get_allocator().deallocate(p,5);

	std::cout << std::endl << "Time test :" << std::endl;
	srand(time(NULL));
	std::map<int, char> tab;
	for (int i = 0; i < 10000000; i++)
	{
		int nb = rand() % 100000;
		tab.insert(std::make_pair<int, char>(nb, 'e'));
	}
}
