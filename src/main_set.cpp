#include "Vector.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include "Container.hpp"
#include "Map.hpp"
#include "Set.hpp"

template <class T, class C>
void fillSet(std::set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

template <class T, class C>
void fillSet(ft::Set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

int	main()
{

	/* CONSTRUCTOR */
	///////////////
	{
		// std::vector<int> v;
		// ft::Set<int> st;
		// for (int i = 0; i < 300000; ++i)
		// 	st.insert(i);
    	// ft::Set<int> st2(st.begin(), st.end());
    	// ft::Set<int>::iterator it = st2.begin();
    	// for (int i = 0; i < 300000; ++i, it++) 
		// {
    	//     v.push_back(*it);
    	// }
	}

	/* ITERATORS */
	///////////////
	{
		// std::vector<int> v;
    	// ft::Set<int> st;
		// ft::Set<int> stt;
    	// fillSet(stt);
    	// for (ft::Set<int>::iterator it = stt.begin(); it != stt.end(); it++) { v.push_back(*it); }
    	// for (ft::Set<int>::iterator it = --stt.end(); it != stt.begin(); it--) { v.push_back(*it); }
    	// ft::Set<int> mp0;
    	// ft::Set<int>::iterator ii = mp0.insert(3).first;
    	// ii++;
    	// v.push_back(*(--ii));
    	// for (int i = 0; i < 5; ++i)
    	//     st.insert(i);
    	// ft::Set<int>::iterator it = st.begin();
    	// ft::Set<int>::iterator it2 = st.end();
    	// v.push_back(*it);
    	// it++;
    	// it++;
    	// it++;
    	// it++;
    	// v.push_back(*it);
    	// it++;
    	// it--;
    	// v.push_back(*it);
    	// it2--;
    	// v.push_back(*it2);
    	// v.push_back(it2 == it);
    	// v.push_back(*(--it2));
    	// v.push_back(*(it2--));
    	// v.push_back(*(it2++));
    	// v.push_back(*(++it2));
	}

	
	/* REVERSE ITERATORS */
	///////////////{
	{
		// std::vector<int> v;
		// ft::Set<int> st;

    	// st.insert(5);
    	// st.insert(3);
    	// st.insert(7);
    	// ft::Set<int>::reverse_iterator rit = st.rbegin();
    	// ft::Set<int>::reverse_iterator rit2 = st.rend();
    	// v.push_back(*rit);
    	// rit++;
    	// rit2--;
    	// v.push_back(*rit);
    	// v.push_back(*rit2);
    	// rit++;
    	// v.push_back(*rit == *rit2);
    	// v.push_back(rit == rit2);
    	// rit2--;
    	// v.push_back(*rit);
    	// v.push_back(*rit2);
    	// v.push_back(*rit2 > *rit);
    	// v.push_back(*rit2 < *rit);
    	// v.push_back(*(--rit));
    	// v.push_back(*(++rit2));
    	// v.push_back(*(rit--));
    	// v.push_back(*(rit2++));
	}

	/* COMPARE */
	///////////////////////
	{
		// std::vector<int> v;
		// std::set<int> st;
    	// fillSet(st);
    	// for (std::set<int>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::greater<int> > st1;
    	// fillSet(st1);
    	// v.push_back(*(st1.begin()));
    	// st1.erase(41);
    	// v.push_back(*(st1.begin()));
    	// st1.erase(29);
    	// v.push_back(*(st1.begin()));
    	// std::set<int, std::greater<int> > st2;
    	// st2.insert(3);
    	// v.push_back(*(st2.begin()));
    	// st2.erase(3);
    	// if (st2.begin() == st2.end())
    	//     v.push_back(1);
    	// std::set<int, std::plus<int> > st3;
    	// fillSet(st3);
    	// for (std::set<int>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::minus<int> > st4;
    	// fillSet(st4);
    	// for (std::set<int>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::greater_equal<int> > st5;
    	// fillSet(st5);
    	// for (std::set<int>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::multiplies<int> > st6;
    	// fillSet(st6);
    	// for (std::set<int>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::bit_xor<int> > st7;
    	// fillSet(st7);
    	// for (std::set<int>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
    	// std::set<int, std::logical_and<int> > st8;
    	// fillSet(st8);
    	// for (std::set<int>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
    	// for (std::set<int>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
    	// v.push_back(st1.size());
		// for (size_t i = 0; i < v.size(); ++i)
		// 	std::cout << v[i] << ' ';
	}

	// std::cout << '\n';
	// std::cout << '\n';
	// std::cout << '\n';


	// {
	// 	std::vector<int> v;
	// 	ft::Set<int> st;
    // 	fillSet(st);
    // 	for (ft::Set<int>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
    // 	std::set<int, std::greater<int> > st1;
    // 	fillSet(st1);
    // 	v.push_back(*(st1.begin()));
    // 	st1.erase(41);
    // 	v.push_back(*(st1.begin()));
    // 	st1.erase(29);
    // 	v.push_back(*(st1.begin()));
    // 	std::set<int, std::greater<int> > st2;
    // 	st2.insert(3);
    // 	v.push_back(*(st2.begin()));
    // 	st2.erase(3);
    // 	if (st2.begin() == st2.end())
    // 	    v.push_back(1);
    // 	ft::Set<int, std::plus<int> > st3;
    // 	fillSet(st3);
    // 	for (ft::Set<int>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
    // 	ft::Set<int, std::minus<int> > st4;
    // 	fillSet(st4);
    // 	for (ft::Set<int>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
    // 	ft::Set<int, std::greater_equal<int> > st5;
    // 	fillSet(st5);
    // 	for (ft::Set<int>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
    // 	ft::Set<int, std::multiplies<int> > st6;
    // 	fillSet(st6);
    // 	for (ft::Set<int>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
    // 	ft::Set<int, std::bit_xor<int> > st7;
    // 	fillSet(st7);
    // 	for (ft::Set<int>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
    // 	ft::Set<int, std::logical_and<int> > st8;
    // 	fillSet(st8);
    // 	for (ft::Set<int>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
    // 	for (ft::Set<int>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
    // 	v.push_back(st1.size());
	// 	for (size_t i = 0; i < v.size(); ++i)
	// 		std::cout << v[i] << ' ';
	// }
	
	////////////////////////////////////////////////////////////////////

	/* ERASE IINPUTIT */
	///////////////////////
	{
		// std::vector<int> v;
		// ft::Set<int> st;
    	// for (int i = 0; i < 10; ++i)
    	//     st.insert(i);
    	// st.erase(st.begin(), --st.end());
    	// v.push_back(*(st.begin()));
	}

	/* FIND */
	///////////////////////
	{
		// std::vector<int> v;
		// ft::Set<int> st;
    	// for (int i = -750000; i < 750000; ++i) {
    	//     st.insert(i);
    	// }
    	// ft::Set<int>::iterator it = st.find(345678);
    	// v.push_back(*it);

    	// it = st.find(-345678);
    	// v.push_back(*it);

    	// it = st.find(-987654321);
    	// if (it == st.end())
    	//     v.push_back(1);
	}

	/* LOWER */
	///////////////////////
	{
		// std::vector<int> v;
		// ft::Set<int> st;
    	// std::set<int, std::greater<int> > st2;
    	// st.insert(10);
    	// st2.insert(10);
    	// if (st.lower_bound(11) == st.end())
    	//     v.push_back(1);
    	// if (st2.lower_bound(1) == st2.end())
    	//     v.push_back(1);
    	// st.insert(20);
    	// st.insert(30);
    	// st.insert(40);
    	// st.insert(50);
    	// st.insert(60);
    	// st2.insert(20);
    	// st2.insert(30);
    	// st2.insert(40);
    	// st2.insert(50);
    	// st2.insert(60);
    	// std::set<int>::iterator it;
    	// for (int i = 1; i < 60; i += 10) {
    	//     it = st.lower_bound(i);
    	//     v.push_back(*it);
    	// }
    	// for (int i = 11; i < 70; i += 10) {
    	//     it = st2.lower_bound(i);
    	//     v.push_back(*it);
    	// }
    	// std::set<int> st3;
    	// for (int i = 0; i < 500000; ++i) {
    	//     st3.insert(i);
    	// }
    	// st3.lower_bound(490000);
	}

	/* EQUAL RANGE */
	///////////////////////
	{
		// std::vector<int> v;
		// ft::Set<int> st;
    	// st.insert(10);
    	// st.insert(20);
    	// st.insert(30);
    	// st.insert(40);
    	// st.insert(50);
    	// st.insert(60);

    	// const ft::pair<ft::Set<int>::const_iterator , ft::Set<int>::const_iterator>& pair = st.equal_range(10);
    	// const ft::pair<ft::Set<int>::const_iterator , ft::Set<int>::const_iterator>& pair2 = st.equal_range(11);
    	// const ft::pair<ft::Set<int>::const_iterator , ft::Set<int>::const_iterator>& pair3 = st.equal_range(1);

    	// v.push_back(*(pair.first));
    	// v.push_back(*(pair.second));
    	// v.push_back(*(pair2.first));
    	// v.push_back(*(pair2.second));
    	// v.push_back(*(pair3.first));
    	// v.push_back(*(pair3.second));
		// for (size_t i = 0; i < v.size(); ++i)
		// 	std::cout << v[i] << ' ';
	}

	

	return 0;
}
