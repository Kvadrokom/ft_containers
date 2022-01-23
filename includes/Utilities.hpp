#ifndef UTIL_H
#define UTIL_H

// #include "Iterator.hpp"
// #include "Container.hpp"


namespace ft
{
	template< class T1, class T2 >
	struct pair
	{
		T1	first;
		T2	second;

		pair() : first(T1()), second(T2()) {};
		pair(const T1 &x, const T2 &y) : first(x), second(y){};
		~pair(){};

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first((p.first)), second((p.second)){};

		pair& operator=( const pair& other )
		{
			first = other.first; 
			second = other.second;
			return *this;
		}
	};

	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
  	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1, class T2>
		pair<T1, T2> make_pair(T1 t, T2 u) {return pair<T1, T2>(t, u); }


	template<class T> struct remove_const { typedef T type; };

	template<class T> struct remove_const <const T> { typedef T type; };
}

#endif