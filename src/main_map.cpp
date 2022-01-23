#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <iterator>
#include "Container.hpp"
#include "Vector.hpp"
#include "../includes/Container.hpp"
#include "../includes/Vector.hpp"
#include "MapReverseIterator.hpp"
#include <vector>
#include "Map.hpp"

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#define HOW 100000

bool fncomp (char lhs, char rhs) {return lhs<rhs;}
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

template <class T, class V, class C>
void fillMap(ft::Map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}
namespace dt
{
	template <class T> 
	void swap ( T& a, T& b )
	{
	  T c(a); a=b; b=c;
	}
}


int	main()
{
	// std::vector<int> v;
	// ft::map<int, int> mp;

	// for (int i = 0, j = 10; i < 300000; ++i, ++j) {
    //     mp.insert(ft::make_pair(i, j));
    // }
    // ft::map<int, int> mp2(mp.begin(), mp.end());
    // ft::map<int, int>::iterator it = mp2.begin();
    // for (int i = 0; i < 300000; ++i, it++) {
    //     v.push_back(it->first);
    //     v.push_back(it->second);
    // }

	// ft::map<int, int> mp3;
	// for (int i = 0, j = 5; i < 300000; ++i, ++j) {
    //     mp3.insert(ft::make_pair(i, j));
	// }
	// mp3 = mp2;

	/* CONSTRUCTORS */
	//////////////////
	{
		// bool    res = true;
    	// ft::map<char,int> first_ft;
    	// first_ft['a']=10;
    	// first_ft['b']=30;
    	// first_ft['c']=50;
    	// first_ft['d']=70;  
    	// ft::map<char,int> second_ft (first_ft.begin(),first_ft.end());
    	// ft::map<char,int> third_ft (second_ft); 
    	// ft::map<char,int,classcomp> fourth_ft;
    	// bool(*fn_pt)(char,char) = fncomp;
    	// std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
    	// ft::map<char,int,bool(*)(char,char)> fifth_ft (fn_pt);
    	// std::map<int,int> map_std;
    	// for (size_t i = 1; i < 10; i++)
    	// {
    	//     map_std.insert(std::make_pair(i,i));
    	// }
    	// std::map<int,int>::iterator it_std = map_std.begin();
    	// ft::map<int,int> map_ft;
    	// for (size_t i = 1; i < 10; i++)
    	// {
    	//     map_ft.insert(ft::make_pair(i,i));
    	// }
    	// ft::map<int,int>::iterator it_ft = map_ft.begin(); 

    	// for (; it_ft != map_ft.end(); it_ft++, it_std++)
    	// {
    	//     if (it_ft->first != it_std->first ||
    	//         it_ft->second != it_std->second)
    	//         res = false;
    	// }
		// std::cout << '\n';
	}

	/* Clear */
	//////////////////
	{
		// std::map<char,int> mymap;
    	// mymap['x']=100;
    	// mymap['y']=200;
    	// mymap['z']=300;

    	// ft::Map<char,int> mymap_ft;
    	// mymap_ft['x']=100;
    	// mymap_ft['y']=200;
    	// mymap_ft['z']=300;
    	// mymap.clear();
    	// mymap_ft.clear();
    	// ft::Map<char,int>::iterator it_ft=mymap_ft.begin();
    	// std::map<char,int>::iterator it_std=mymap.begin();
    	// for (; it_ft!=mymap_ft.end(); ++it_ft, ++it_std)
    	// {
    	//     if (it_ft->first == it_std->first && it_ft->second == it_std->second)
    	//         std::cout << FGRN("[OK] ");
    	//     else
    	//         std::cout << FRED("[KO] ");
    	// }
    	// if (it_std == mymap.end())
    	// {
    	//     if (it_ft == mymap_ft.begin())
    	//         std::cout << FGRN("[OK] ");
    	//     else
    	//         std::cout << FRED("[KO] ");
    	// }
    	// mymap['a']=1101;
    	// mymap['b']=2202;
    	// mymap_ft['a']=1101;
    	// mymap_ft['b']=2202;
    	// it_ft=mymap_ft.begin();
    	// it_std=mymap.begin();
    	// for (; it_ft!=mymap_ft.end(); ++it_ft, ++it_std)
    	// {
    	//     if (it_ft->first == it_std->first && it_ft->second == it_std->second)
    	//         std::cout << FGRN("[OK] ");
    	//     else
    	//         std::cout << FRED("[KO] ");
    	// }
	}

	
	/* COMPARE CLASS */
	//////////////////
	{
		// ft::Map<int, int> mp;
		// std::vector<int> v;
		// fillMap(mp);
    	// for ( ft::Map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    	// ft::Map<int, int, std::greater<int> > mp1;
    	// fillMap(mp1);
    	// v.push_back(mp1.begin()->first);
    	// mp1.erase(41);
    	// v.push_back(mp1.begin()->first);
    	// mp1.erase(29);
    	// v.push_back(mp1.begin()->first);
    	// ft::Map<int, int, std::greater<int> > mp2;
    	// mp2.insert(ft::make_pair(3, 3));
    	// v.push_back(mp2.begin()->first);
    	// mp2.erase(3);
    	// if (mp2.begin() == mp2.end())
    	//     v.push_back(1);
    	// ft::Map<int, int, std::plus<int> > mp3;
    	// fillMap(mp3);
    	// for ( ft::Map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    	// ft::Map<int, int, std::minus<int> > mp4;
    	// fillMap(mp4);
    	// for ( ft::Map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    	// ft::Map<int, int, std::greater_equal<int> > mp5;
    	// fillMap(mp5);
    	// for ( ft::Map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    	// ft::Map<int, int, std::multiplies<int> > mp6;
    	// fillMap(mp6);
    	// for ( ft::Map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    	// ft::Map<int, int, std::bit_xor<int> > mp7;
    	// fillMap(mp7);
    	// for ( ft::Map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    	// for ( ft::Map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    	// std::map<int, int, std::logical_and<int> > mp8;
    	// fillMap(mp8);
    	// for ( std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    	// for ( std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    	// v.push_back(mp1.size());
	}

	/* Clear */
	//////////////////
	{
		// ft::Map<int, int> mp;
		// long *adr1 = reinterpret_cast<long *>(&mp);
		// std::cout << adr1 << "\n";
		// std::vector<int> v;
		// mp.clear();
    	// for (int i = 0, j = 0; i < 5; ++i, ++j)
    	//     mp.insert(ft::make_pair(i, j));
    	// v.push_back(mp.size());
    	// mp.clear();
    	// v.push_back(mp.size());
    	// ft::Map<int, int>::iterator it = mp.begin();
    	// if (it == mp.end())
    	//     v.push_back(1);
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << "\n";
	}

	

	/* Clear */
	//////////////////
	{
		// ft::Map<int, int> mp;
		// std::vector<int> v;
		// mp.clear();
    	// for (int i = 0, j = 0; i < 250000; ++i, ++j)
    	//     mp.insert(ft::make_pair(i, j));
    	// v.push_back(mp.size());
    	// mp.clear();
    	// v.push_back(mp.size());
    	// ft::Map<int, int>::iterator it = mp.begin();
    	// if (it == mp.end())
    	//     v.push_back(1);
	}

	/* INPUT IT */
	//////////////////
	{
		// ft::Map<int, int> mp;
    	// std::vector<int> v;
    	// for (int i = 0, j = 0; i < 500000; ++i, ++j)
    	//     mp.insert(ft::make_pair(i, j));
    	// ft::Map<int, int> mp2;
    	// mp2.insert(mp.begin(), mp.end());
    	// ft::Map<int, int>::iterator it2 = mp2.begin();
    	// for (; it2 != mp2.end(); ++it2) {
        // 	v.push_back(it2->first);
        // 	v.push_back(it2->second);
    	// }
	}

	/* SWAP */
	//////////////////
	{
		// std::vector<int> v;
		// ft::Map<int, int> mp;
		// long *adr0 = reinterpret_cast<long *>(&mp);
		// std::cout << adr0 << "\n";
    	// for (int i = 0, j = 0; i < 250000; ++i, ++j)
    	//     mp.insert(ft::make_pair(i, j));
    	// ft::Map<int, int> mp2;
    	// for (int i = 250000, j = 0; i < 350000; ++i, --j)
    	//     mp.insert(ft::make_pair(i, j));
    	// long *adr1 = reinterpret_cast<long *>(&mp);
    	// long *adr2 = reinterpret_cast<long *>(&mp2);
		// std::cout << adr1 << " " << adr2 << "\n";
    	// mp.swap(mp2);
    	// if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    	// 	v.push_back(1);
    	// v.push_back(mp2.size());
    	// ft::Map<int, int>::iterator it = mp2.begin();
    	// for (; it != mp2.end(); ++it) {
    	//     v.push_back(it->first);
    	//     v.push_back(it->second);
    	// }
    	// dt::swap(mp, mp2);
		// // mp.swap(mp2);
    	// ft::Map<int, int>::iterator it2 = mp2.begin();
    	// for (; it2 != mp2.end(); ++it2) {
        // 	v.push_back(it2->first);
        // 	v.push_back(it2->second);
    	// }
	}

	/* COUNT */
	//////////////////
	{
		// std::vector<int> v;
		// ft::Map<int, int> mp;
		// v.push_back(mp.count(0));
		// mp.insert(ft::make_pair(0, 0));
		// v.push_back(mp.count(0));
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << "\n";
		// }
	}

	/* INSERT HINT */
	//////////////////
	{
		// ft::Map<int, int> mp;
		// std::vector<int> v;
		// ft::Map<int, int>::iterator it = mp.end();
    	// for (int i = 0, j = 0; i < 500000; ++i, ++j) {
    	//     mp.insert(it, ft::make_pair(i, j));
    	// }
    	// ft::Map<int, int>::iterator it2 = mp.begin();
    	// for (; it2 != mp.end(); ++it2) {
    	//     v.push_back(it2->first);
    	//     v.push_back(it2->second);
    	// }
	}


	/* UPPER BOUND */
	//////////////////
	{
		// std::vector<int> v;
		// ft::Map<int, int> mp;
    	// ft::Map<int, int, std::greater<int> > mp2;
    	// mp.insert(ft::make_pair(10, 10));
    	// mp2.insert(ft::make_pair(10, 10));
    	// if (mp.upper_bound(11) == mp.end())
    	//     v.push_back(1);
    	// if (mp2.upper_bound(1) == mp2.end())
    	//     v.push_back(1);
    	// mp.insert(ft::make_pair(20, 20));
    	// mp.insert(ft::make_pair(30, 30));
    	// mp.insert(ft::make_pair(40, 40));
    	// mp.insert(ft::make_pair(50, 50));
    	// mp.insert(ft::make_pair(60, 60));
    	// mp2.insert(ft::make_pair(20, 20));
    	// mp2.insert(ft::make_pair(30, 30));
    	// mp2.insert(ft::make_pair(40, 40));
    	// mp2.insert(ft::make_pair(50, 50));
    	// mp2.insert(ft::make_pair(60, 60));
    	// ft::Map<int, int>::iterator it;
    	// for (int i = 1; i < 60; i += 10) {
    	//     it = mp.upper_bound(i);
    	//     v.push_back(it->first);
    	// }
    	// for (int i = 11; i < 70; i += 10) {
    	//     it = mp2.upper_bound(i);
    	//     v.push_back(it->first);
    	// }
    	// ft::Map<int, int> mp3;
    	// for (int i = 0, j = 0; i < 500000; ++i, ++j) {
    	//     mp3.insert(ft::make_pair(i, j));
    	// }
    	// ft::Map<int, int> mp4;
    	// mp.insert(ft::make_pair(-10, 10));
    	// mp.insert(ft::make_pair(-20, 20));
    	// v.push_back((--mp.upper_bound(0))->first);
    	// mp3.upper_bound(490000);
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	}

	
		/* USING ALLOCATOR */
	/////////////////////////////
	{
		ft::Map<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > >  mp;
		for (int i = 0, j = 10; i < 10; ++i, ++j)
		{
        	mp.insert(ft::make_pair(i, j));
    	}

		std::map<int, int, std::less<int>, std::allocator<std::pair<const int, int> > >  mp1;
		for (int i = 0, j = 10; i < 10; ++i, ++j)
		{
        	mp1.insert(std::make_pair(i, j));
    	}
		
		std::map<int, int>::iterator it1 = mp1.begin();
		std::cout << "\n";
		for (; it1 != mp1.end(); ++it1)
		{
			std::cout << it1->first << " ";
		}

		std::cout << "\n";

		ft::Map<int, int>::iterator it = mp.begin();
		std::cout << "\n";
		for (; it != mp.end(); ++it)
		{
			std::cout << it->first << " ";
		}
	}
}