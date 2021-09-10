#ifndef TEST_HPP
# define TEST_HPP

#ifndef NS
# define NS std

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <vector>

#endif // !NS

template<typename K, typename T>
std::ostream& operator<<(std::ostream& os, const std::map<K, T>& m)
{
	os << "{";
	for (typename std::map<K,T>::const_iterator it = m.begin(); it != m.end(); ++it) {
		os << it->first << ": " << it->second << ", ";
	}
	os << "}";
	return os;
}

template<typename K, typename T>
std::ostream& operator<<(std::ostream& os, const ft::map<K, T>& m)
{
	os << "{";
	for (typename ft::map<K,T>::const_iterator it = m.begin(); it != m.end(); ++it) {
		os << it->first << ": " << it->second << ", ";
	}
	os << "}";
	return os;
}

#include <sstream>

namespace ft
{
	template <typename T>
	std::string
		to_string(T a)
	{
		std::ostringstream temp;

		temp << a;
		return (temp.str());
	}
}

static int
test_stack()
{
	NS::stack <int> s;

	assert(s.empty());
	s.push(1);
	assert(!s.empty());
	assert(s.top() == 1);
	s.push(2);
	assert(s.top() == 2);
	assert(s.size() == 2);
	s.push(3);
	assert(s.top() == 3);
	assert(s.size() == 3);
	s.pop();
	assert(s.top() == 2);
	assert(s.size() == 2);
	s.pop();
	assert(s.top() == 1);
	assert(s.size() == 1);
	s.pop();
	assert(s.empty());
	assert(s.size() == 0);
	//lexicographical comparaison
	s.push(1);
	s.push(2);
	s.push(3);
	NS::stack <int> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	assert(s == s2);
	assert(s >= s2);
	assert(s <= s2);
	assert(!(s != s2));
	s2.pop();
	assert(s != s2);
	s2.push(2);
	assert(s > s2);
	assert(s >= s2);
	assert(!(s < s2));
	assert(!(s <= s2));
	assert(s2 < s);
	s2.pop();
	s2.push(4);
	assert(s < s2);
	assert(s2 > s);
	assert(s <= s2);
	assert(s2 >= s);
	assert(s != s2);
	assert(s2 != s);
	assert(!(s2 == s));
	assert(!(s == s2));
	return 0;
}

template <class T>
static void
	init_vector(T& vref)
{
	vref.push_back(1);
	vref.push_back(2);
	vref.push_back(3);
}

static int
	test_vector()
{
	NS::vector <int> v;
	assert(v.empty());
	v.push_back(1);
	assert(!v.empty());
	assert(v.size() == 1);
	assert(v[0] == 1);
	v.push_back(2);
	assert(v.size() == 2);
	assert(v[0] == 1);
	assert(v[1] == 2);
	v.push_back(3);
	assert(v.size() == 3);
	assert(v[0] == 1);
	assert(v[1] == 2);
	assert(v[2] == 3);
	v.pop_back();
	assert(v.size() == 2);
	assert(v[0] == 1);
	assert(v[1] == 2);
	v.pop_back();
	assert(v.size() == 1);
	assert(v[0] == 1);
	v.pop_back();
	assert(v.empty());
	assert(v.size() == 0);
	//lexicographical comparaison
	init_vector(v);
	NS::vector <int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	assert(v == v2);
	assert(v >= v2);
	assert(v <= v2);
	assert(!(v != v2));
	v2.pop_back();
	assert(v != v2);
	v2.push_back(2);
	assert(v > v2);
	assert(v >= v2);
	assert(!(v < v2));
	assert(!(v <= v2));
	assert(v2 < v);
	v2.pop_back();
	v2.push_back(4);
	assert(v < v2);
	assert(v2 > v);
	assert(v <= v2);
	assert(v2 >= v);
	assert(v != v2);
	assert(v2 != v);
	assert(!(v2 == v));
	assert(!(v == v2));
	//max _size test
	assert(v.max_size() == v2.max_size());
	assert(v.max_size() > 0);
	//resize test
	v.resize(10);
	assert(v.size() == 10);
	v.resize(5);
	assert(v.size() == 5);
	v.resize(10);
	assert(v.size() == 10);
	v.resize(0);
	assert(v.size() == 0);
	assert(v.empty());
	//reserve test
	v.reserve(10);
	assert(v.capacity() >= 10);
	v.reserve(5);
	assert(v.capacity() >= 10);
	v.reserve(20);
	assert(v.capacity() >= 20);
	v.reserve(0);
	assert(v.capacity() >= 20);
	v.reserve(1);
	assert(v.capacity() >= 20);
	//assign test
	v.assign(10, 1);
	assert(v.size() == 10);
	assert(v[0] == 1);
	v.assign(10, 2);
	assert(v.size() == 10);
	assert(v[0] == 2);
	v.assign(10, 3);
	assert(v.size() == 10);
	assert(v[0] == 3);
	v.assign(0, 4);
	assert(v.size() == 0);
	assert(v.empty());
	//insert test
	init_vector(v);
	v.insert(v.begin(), 0);
	assert(v.size() == 4);
	assert(v[0] == 0);
	assert(v[1] == 1);
	assert(v[2] == 2);
	assert(v[3] == 3);
	v.insert(v.begin() + 1, 0);
	assert(v.size() == 5);
	assert(v[0] == 0);
	assert(v[1] == 0);
	assert(v[2] == 1);
	assert(v[3] == 2);
	assert(v[4] == 3);
	v.insert(v.begin() + 2, 0);
	assert(v.size() == 6);
	assert(v[0] == 0);
	assert(v[1] == 0);
	assert(v[2] == 0);
	assert(v[3] == 1);
	assert(v[4] == 2);
	assert(v[5] == 3);

	//erase test
	v.erase(v.begin());
	assert(v.size() == 5);
	assert(v[0] == 0);
	assert(v[1] == 0);
	assert(v[2] == 1);
	assert(v[3] == 2);
	assert(v[4] == 3);
	v.erase(v.begin() + 1);
	assert(v.size() == 4);
	assert(v[0] == 0);
	assert(v[1] == 1);
	assert(v[2] == 2);
	assert(v[3] == 3);
	v.erase(v.begin() + 2);
	assert(v.size() == 3);
	assert(v[0] == 0);
	assert(v[1] == 1);
	assert(v[2] == 3);
	v.erase(v.begin() + 1);
	assert(v.size() == 2);
	assert(v[0] == 0);
	assert(v[1] == 3);
	v.erase(v.begin() + 1);
	assert(v.size() == 1);
	assert(v[0] == 0);
	v.erase(v.begin());
	assert(v.size() == 0);
	assert(v.empty());
	//clear test
	init_vector(v);
	v.clear();
	v2.clear();
	assert(v.size() == 0);
	assert(v.empty());
	assert(v == v2);
	assert(v >= v2);
	assert(v <= v2);
	assert(!(v != v2));
	//swap test
	init_vector(v);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v.swap(v2);
	assert(v.size() == 3);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 6);
	assert(v2.size() == 3);
	init_vector(v2);
	//move test
	v.clear();
	v2.clear();
	init_vector(v);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v.swap(v2);
	assert(v.size() == 3);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 6);
	assert(v2.size() == 3);
	init_vector(v2);
	//move assign test
	v.clear();
	v2.clear();
	init_vector(v);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v.swap(v2);
	assert(v.size() == 3);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 6);
	assert(v2.size() == 3);
	init_vector(v2);
	//move assign test
	v.clear();
	v2.clear();
	init_vector(v);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v.swap(v2);
	assert(v.size() == 3);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 6);
	assert(v2.size() == 3);
	init_vector(v2);
	//move assign test
	v.clear();
	v2.clear();
	init_vector(v);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v.swap(v2);
	assert(v.size() == 3);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 6);
	assert(v2.size() == 3);
	init_vector(v2);
	// at test
	v.clear();
	init_vector(v);
	assert(v.at(0) == 1);
	//_capacity test
	assert(v.capacity() <= v.max_size());
	// insert test
	v.clear();
	init_vector(v);
	v.insert(v.begin() + 1, 4);
	assert(v.size() == 4);
	assert(v[0] == 1);
	assert(v[1] == 4);
	assert(v[2] == 2);
	assert(v[3] == 3);
	v.insert(v.begin() + 1, 5);
	assert(v.size() == 5);
	assert(v[0] == 1);
	assert(v[1] == 5);
	assert(v[2] == 4);
	assert(v[3] == 2);
	assert(v[4] == 3);
	//end insert test
	v.clear();
	init_vector(v);
	v.insert(v.end(), 4);
	assert(v.size() == 4);
	assert(v[0] == 1);
	assert(v[1] == 2);
	assert(v[2] == 3);
	assert(v[3] == 4);
	v.insert(v.end(), 5);
	assert(v.size() == 5);
	assert(v[0] == 1);
	assert(v[1] == 2);
	assert(v[2] == 3);
	assert(v[3] == 4);
	assert(v[4] == 5);
	//front test
	v.clear();
	init_vector(v);
	assert(v.front() == 1);
	//back test
	v.clear();
	init_vector(v);
	assert(v.back() == 3);
	//assign test
	v.clear();
	init_vector(v);
	v.assign(4, 4);
	assert(v.size() == 4);
	assert(v[0] == 4);
	assert(v[1] == 4);
	assert(v[2] == 4);
	assert(v[3] == 4);
	v.assign(4, 5);
	assert(v.size() == 4);
	assert(v[0] == 5);
	assert(v[1] == 5);
	assert(v[2] == 5);
	assert(v[3] == 5);
// test vector with strings
	NS::vector<std::string> v3;
	std::string hello = "hello";
	std::string world = "world";
	std::string dot = "!";

	v3.push_back(hello);
	std::cout << hello <<std::endl;
	v3.push_back("world");
	v3.push_back("!");
	assert(v3.size() == 3);
	assert(v3[0] == "hello");
	assert(v3[1] == "world");
	assert(v3[2] == "!");
	v3.push_back("hello");
	v3.push_back("world");
	v3.push_back("!");
	assert(v3.size() == 6);
	//compare
	NS::vector<std::string> v4;
	v4.push_back("hello");
	v4.push_back("world");
	v4.push_back("!");
	v4.push_back("hello");
	v4.push_back("world");
	v4.push_back("!");
	assert(v4 == v3);
	assert(!(v4 != v3));
	//comparisons
	assert(v4 <= v3);
	assert(v4 >= v3);
	assert(!(v4 < v3));
	assert(!(v4 > v3));
	//iterators tests
	v4.clear();
	v4.push_back("hello");
	v4.push_back("world");
	v4.push_back("!");
	v4.push_back("hello");
	v4.push_back("world");
	v4.push_back("!");
	NS::vector<std::string>::iterator it = v4.begin();
	assert(*it == "hello");
	++it;
	assert(*it == "world");
	++it;
	assert(*it == "!");
	++it;
	assert(*it == "hello");
	++it;
	assert(*it == "world");
	++it;
	assert(*it == "!");
	++it;
	assert(it == v4.end());
	--it;
	assert(*it == "!");
	--it;
	assert(*it == "world");
	--it;
	assert(*it == "hello");
	--it;
	assert(*it == "!");
	--it;
	assert(*it == "world");
	--it;
	assert(*it == "hello");
	//reverse iterators
	NS::vector<std::string>::reverse_iterator rit = v4.rbegin();
	assert(*rit == "!");
	++rit;
	assert(*rit == "world");
	++rit;
	assert(*rit == "hello");
	++rit;
	assert(*rit == "!");
	++rit;
	assert(*rit == "world");
	++rit;
	assert(*rit == "hello");
	++rit;
	assert(rit == v4.rend());
	--rit;
	assert(*rit == "hello");
	--rit;
	assert(*rit == "world");
	--rit;
	assert(*rit == "!");
	--rit;
	assert(*rit == "hello");
	--rit;
	assert(*rit == "world");
	--rit;
	assert(*rit == "!");
	//lexicographic
	v4.clear();
	v4.push_back("hello");
	v4.push_back("world");
	v4.push_back("!");
	v3.clear();
	v3.push_back("hello");
	v3.push_back("world");
	v3.push_back("!");
	assert(v4 == v3);
	assert(v4 >= v3);
	assert(v3 <= v4);
	assert(v4 <= v3);
	assert(v3 >= v4);
	assert(v4 <= v4);
	assert(v4 >= v4);
	assert(v3 <= v3);
	assert(v3 >= v3);
	v4.push_back("oii");
	assert(v4 > v3);
	assert(v3 < v4);
	assert(v4 != v3);
	//v5 size_t
	NS::vector<size_t> v5;
	for (size_t i = 0; i <= 10000000; i++)
	{
		v5.push_back(i);
	}
	assert(v5.size() == 10000001);
	assert(v5[10000000] == 10000000);
	NS::vector<size_t>::iterator it5 = v5.begin(), ite5 = v5.end();
	assert((ite5 - it5) == 10000001);
	for (; it5 != ite5; ++it5)
			*it5 = (ite5 - it5);
	//same with strings
	NS::vector<std::string> v6;
	for (size_t i = 0; i <= 10000000; i++)
	{
		v6.push_back(ft::to_string(i));
	}
	assert(v6.size() == 10000001);
	assert(v6[10000000] == "10000000");
	NS::vector<std::string>::iterator it6 = v6.begin(), ite6 = v6.end();
	assert((ite6 - it6) == 10000001);
	size_t index = 0;
	for (; it6 != ite6; ++it6)
			assert(*it6 == ft::to_string(index++));
	return 0;
}


static int
	test_lexicographic()
{
	NS::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	//lexicographic
	NS::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	//use lexicographical_compare
	assert (NS::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) == false);
	assert (NS::lexicographical_compare(v2.begin(), v2.end(), v.begin(), v.end()) == false);
	v2.push_back(7);
	assert (NS::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) == true);
	assert (NS::lexicographical_compare(v2.begin(), v2.end(), v.begin(), v.end()) == false);
	v2.pop_back();
	v2.pop_back();
	v2.push_back(8);
	assert (NS::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) == true);
	assert (NS::lexicographical_compare(v2.begin(), v2.end(), v.begin(), v.end()) == false);
	return 0;
}
/*
#undef NS
#define NS ft
*/
static int
	test_map()
{
	NS::map<int, int> m;
	m[1] = 1;
	NS::map<int, int> mm(m);
	NS::map<int, int> mmm;
	mmm = mm;
	mmm.clear();
	mm.clear();
	std::cout << m << std::endl << "--------" << std::endl;
	m[2] = 2;
	std::cout << m <<  std::endl << "--------" << std::endl;
	m[3] = 3;
	std::cout << m << std::endl << "--------" << std::endl;
	//check
	assert(m.size() == 3);

	assert(m[1] == 1);
	assert(m[2] == 2);
	assert(m[3] == 3);
	//erase
	std::cout << m << std::endl << "-------------------------" << std::endl;
	m.erase(1);
	std::cout << m << std::endl << "-------------------------" << std::endl;
	assert(m.size() == 2);
	assert(m[2] == 2);
	assert(m[3] == 3);
	//clear
	m.clear();
	//std::cout << m << std::endl << "--------" << std::endl;
	assert(m.size() == 0);
	//insert
	m.insert(NS::pair<int, int>(1, 1));
	m.insert(NS::pair<int, int>(2, 2));
	m.insert(NS::pair<int, int>(3, 3));
	std::cout << m.size() << std::endl;
	assert(m.size() == 3);
	assert(m[1] == 1);
	assert(m[2] == 2);
	assert(m[3] == 3);
	//erase
	m.erase(1);
	assert(m.size() == 2);
	assert(m[2] == 2);
	assert(m[3] == 3);
	//clear
	m.clear();
	assert(m.size() == 0);
	//string keys
	NS::map<std::string, int> m2;
	m2["hello"] = 1;
	m2["world"] = 2;
	m2["!"] = 3;
	//check
	assert(m2.size() == 3);
	assert(m2["hello"] == 1);
	assert(m2["world"] == 2);
	assert(m2["!"] == 3);
	//erase
	std::cout << m2 << std::endl << "-------------------------" << std::endl;
	m2.erase("hello");
	//assert find("hello") fails
	assert(m2.find("hello") == m2.end());
	std::cout << m2 << std::endl << "-------------------------" << std::endl;
	assert(m2.size() == 2);
	assert(m2["world"] == 2);
	assert(m2["!"] == 3);
	//clear
	m2.clear();
	assert(m2.size() == 0);
	//lexicographic
	m2.insert(NS::pair<std::string, int>("hello", 1));
	m2.insert(NS::pair<std::string, int>("world", 2));
	m2.insert(NS::pair<std::string, int>("!", 3));
	assert(m2.size() == 3);
	assert(m2["hello"] == 1);
	assert(m2["world"] == 2);
	assert(m2["!"] == 3);
	//compare
	NS::map<std::string, int> m3;
	m3.insert(NS::pair<std::string, int>("hello", 1));
	m3.insert(NS::pair<std::string, int>("world", 2));
	m3.insert(NS::pair<std::string, int>("!", 3));
	assert(m2 == m3);
	assert(m2 >= m3);
	assert(m3 <= m2);
	assert(m2 <= m3);
	assert(m2 <= m2);
	assert(m2 >= m2);
	assert(m3 >= m3);
	assert(m3 <= m3);
	assert(m3 >= m3);
	m3.insert(NS::pair<std::string, int>("oii", 4));
	//std::cout << "m2 \n" << m2 << std::endl;
	//std::cout << "m3 \n" << m3 << std::endl;
	//std::cout << "------------------------------------------------" << std::endl;
	/*std::cout << "{";
	for (NS::map<std::string, int>::iterator it = m2.begin(); it != m2.end(); it++)
		std::cout << it->first << ":" << it->second << ", ";
	std::cout << "}" << std::endl;
	std::cout << "{";
	for (NS::map<std::string, int>::iterator it = m3.begin(); it != m3.end(); it++)
		std::cout << it->first << ":" << it->second << ", ";
	std::cout << "}" << std::endl;*/
	assert(m3 < m2);
	assert(m2 > m3);
	assert(m3 != m2);
	assert(m2 != m3);
	m3.erase("oii");
	//std::cout << "m2 \n" << m2 << std::endl;
	//std::cout << "m3 \n" << m3 << std::endl;
	assert(m3 == m2);
	assert(!(m3 != m2));
	assert(m2 == m2);
	assert(m3 == m3);
	m3.clear();
	assert(m3 == m3);
	assert(m2 == m2);
	assert(m3 != m2);
	assert(m2 != m3);
	m3.insert(NS::pair<std::string, int>("oii", 4));
	assert(m3 != m2);
	assert(m2 == m2);
	assert(m3 == m3);
	m3.clear();
	m2.clear();
	//erase test
	m2.insert(NS::pair<std::string, int>("hello", 1));
	m2.insert(NS::pair<std::string, int>("world", 2));
	m2.insert(NS::pair<std::string, int>("!", 3));
	m2.erase("hello");
	assert(m2.size() == 2);
	//assert find fails
	assert(m2.find("hello") == m2.end());
	std::cout << "hello can't be found using find() (this is expected)" << std::endl;
	//assert you can't find it with iterator
	for (NS::map<std::string, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		if (it->first == "hello")
		{
			std::cout << "hello found using iterator (this is not expected)" << std::endl;
			assert(false);
		}
	}
	std::cout << "hello can't be found using iterator (this is expected)" << std::endl;
	assert(m2["world"] == 2);
	assert(m2["!"] == 3);
	m2.clear();
	assert(m2.size() == 0);
	//insert test
	m2.insert(NS::pair<std::string, int>("hello", 1));
	m2.insert(NS::pair<std::string, int>("world", 2));
	m2.insert(NS::pair<std::string, int>("!", 3));
	m2.insert(NS::pair<std::string, int>("hello", 4));
	assert(m2.size() == 3);
	assert(m2["hello"] == 1);
	assert(m2["world"] == 2);
	assert(m2["!"] == 3);
	m2.clear();
	m.clear();
	m3.clear();
	//m4 size_t size_t
	NS::map<size_t, size_t> m4;
	size_t size = 81790;
	for (size_t i = 0; i < size; i++)
	{
		m4.insert(NS::pair<size_t, size_t>(i, i));
	}
	//std::cout << m4 << std::endl << "-------------------------" << std::endl;
	std::cout << "m4" << std::endl;
//	std::cout << m4 << std::endl;
	assert(m4.size() == size);
	std::cout << "m2[" << m4.size() << "] \n" << m4[m4.size() - 1] << std::endl;
	assert(m4[m4.size() - 1] == size - 1);
	assert(m4[(m4.size() - 1)/2] == (size - 1)/2);
	assert(m4.find(m4.size() - 1) != m4.end());
	std::cout << m4.find(m4.size() - 1)->first << std::endl;
	//std::cout << m4.end()->first << std::endl;
	assert(m4.find(m4.size()) == m4.end());

	m4.clear();
	for (size_t i = 0; i < size; i++)
	{
		m4.insert(NS::pair<size_t, size_t>(i^0x4ACBD0E, i^0x4ACBD0E));
	}
	//std::cout << m4 << std::endl << "-------------------------" << std::endl;
	std::cout << "m4" << std::endl;
	//std::cout << m4 << std::endl;
	assert(m4.size() == size);
	assert(m4[(size/2)^0x4ACBD0E] == ((size/2) ^0x4ACBD0E));
	return 0;
}


static int
	is_integral_test() 
{
	assert(ft::is_integral<int>::value == true);
	assert(ft::is_integral<unsigned int>::value == true);
	assert(ft::is_integral<long>::value == true);
	assert(ft::is_integral<unsigned long>::value == true);
	assert(ft::is_integral<char>::value == true);
	assert(ft::is_integral<unsigned char>::value == true);
	assert(ft::is_integral<signed char>::value == true);
	assert(ft::is_integral<wchar_t>::value == true);
	assert(ft::is_integral<bool>::value == true);
	assert(ft::is_integral<float>::value == false);
	assert(ft::is_integral<double>::value == false);
	assert(ft::is_integral<long double>::value == false);
	assert(ft::is_integral<std::string>::value == false);
	assert(ft::is_integral<NS::vector<int> >::value == false);
	assert((ft::is_integral<std::map<int, int> >::value == false));
	return 0;
}


static int
	pair_test()
{
	NS::pair<int, int> p(1, 2);
	assert(p.first == 1);
	assert(p.second == 2);
	return 0;
}

static int
	make_pair_test()
{
	NS::pair<int, int> p = NS::make_pair(1, 2);
	assert(p.first == 1);
	assert(p.second == 2);
	return 0;
}

static int
	swap_test()
{
	NS::pair<int, int> p1(1, 2);
	NS::pair<int, int> p2(3, 4);
	NS::swap(p1, p2);
	assert(p1.first == 3);
	assert(p1.second == 4);
	assert(p2.first == 1);
	assert(p2.second == 2);
	//check that swap is not a deepcopy
	p1.first = 5;
	p1.second = 6;
	assert(p1.first == 5);
	assert(p1.second == 6);
	assert(p2.first == 1);
	assert(p2.second == 2);
	//swap vectors
	NS::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	NS::vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	NS::swap(v1, v2);
	assert(v1.size() == 3);
	assert(v1[0] == 4);
	assert(v1[1] == 5);
	assert(v1[2] == 6);
	assert(v2.size() == 3);
	assert(v2[0] == 1);
	assert(v2[1] == 2);
	assert(v2[2] == 3);
	return 0;
}

//map_order_test
static int map_order_test()
{
	ft::map<int, int> map;

	map.insert(ft::pair<int, int>(10, 1));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(20, 2));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(30, 3));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(4, 40));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(5, 50));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(6, 60));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	map.insert(ft::pair<int, int>(7, 70));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	for (size_t i = 0; i < map.size(); i++)
	{
		std::cout << "(" << i << "," << map[i] << ") ";
	}
	std::cout << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	NS::map<std::string, int> m3;
	std::cout << m3 << std::endl << "------------------------------------------------" << std::endl;
	m3.insert(NS::pair<std::string, int>("hello", 1));
	std::cout << m3 << std::endl << "------------------------------------------------" << std::endl;
	m3.insert(NS::pair<std::string, int>("world", 2));
	std::cout << m3 << std::endl << "------------------------------------------------" << std::endl;
	m3.insert(NS::pair<std::string, int>("!", 3));
	std::cout << m3 << std::endl << "------------------------------------------------" << std::endl;
	m3.insert(NS::pair<std::string, int>("oii", 4));
	std::cout << m3 << std::endl << "------------------------------------------------" << std::endl;

	return 0;
}

static int map_iter_test()
{
	NS::map<int, int> map;
	map.insert(NS::pair<int, int>(10, 1));
	map.insert(NS::pair<int, int>(20, 2));
	map.insert(NS::pair<int, int>(30, 3));
	map.insert(NS::pair<int, int>(4, 40));
	map.insert(NS::pair<int, int>(5, 50));
	map.insert(NS::pair<int, int>(6, 60));
	map.insert(NS::pair<int, int>(7, 70));
	std::cout << map << std::endl << "------------------------------------------------" << std::endl;
	NS::map<int, int>::iterator it = map.begin();
	NS::map<int, int>::iterator ite = map.end();
	while (it != ite)
	{
		std::cout << "(" << it->first << "," << it->second << ") ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	//rerverse iterator
	NS::map<int, int>::reverse_iterator rit = map.rbegin();
	NS::map<int, int>::reverse_iterator rite = map.rend();
	while (rit != rite)	
	{
		std::cout << "(" << rit->first << "," << rit->second << ") ";
		rit++;
	}
	std::cout << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	return 0;
}

#define ENTROPY "2727"

#endif
