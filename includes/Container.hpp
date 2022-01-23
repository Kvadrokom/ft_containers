#ifndef CONTAINER_H
#define CONTAINER_H

#include <iterator>
#include "Utilities.hpp"

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category 	iterator_category;
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::difference_type 		difference_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
   };

   template <typename T>
    struct iterator_traits<T*> 
	{
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef random_access_iterator_tag 		iterator_category;
		typedef T*								pointer;
		typedef T& 								reference;
    };

	template <typename T>
    struct iterator_traits<const T*> 
	{
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef random_access_iterator_tag 		iterator_category;
		typedef const T*						pointer;
		typedef const T&						reference;
    };

	template <bool B, typename T, typename F>
	struct conditional
	{
		typedef F type;
	};

	template <typename T, typename F>
	struct conditional <true, T, F>
	{
		typedef T type;
	};

	template <typename T, typename F>
	struct is_same
	{
		static const bool value = false;
	};

	template <typename T>
	struct is_same<T, T>
	{
		static const bool value = true;
	};

	template <typename T>
	void	swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

	template<bool B, typename T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*  is_integral   */

	template<typename T> 
	struct is_integral 
	{
		static const bool value = false;
	};

	template<typename T>
	std::ostream &operator<<(std::ostream &out, is_integral<T> ex)
	{
		out << ex.value;
		return out;
	}

	template<typename T>
	bool operator==(is_integral<T> lhs, std::is_integral<T> rhs)
	{
		return lhs.value == rhs.value;
	}

	template<typename T>
	bool operator==(std::is_integral<T> rhs, is_integral<T> lhs)
	{
		return  rhs.value == lhs.value;
	}

	template<> struct is_integral<bool> {static const bool value = true;};
	template<> struct is_integral<int> {static const bool value = true;};
	template<> struct is_integral<char> {static const bool value = true;};
	template<> struct is_integral<short>{static const bool value = true;};
	template<> struct is_integral<long int> {static const bool value = true;};
	template<> struct is_integral<wchar_t> {static const bool value = true;};
	template<> struct is_integral<char16_t> {static const bool value = true;};
	template<> struct is_integral<signed char> {static const bool value = true;};
	template<> struct is_integral<long long int> {static const bool value = true;};
	template<> struct is_integral<unsigned char> {static const bool value = true;};
	template<> struct is_integral<unsigned short>{static const bool value = true;};
	template<> struct is_integral<unsigned int>{static const bool value = true;};
	template<> struct is_integral<unsigned long int>{static const bool value = true;};
	template<> struct is_integral<unsigned long long int>{static const bool value = true;};

	/*  is_integral   */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	T decval(){}

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
	                             InputIt2 first2, InputIt2 last2)
	{
	    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) 
		{
	        if (*first1 < *first2) return true;
	        if (*first2 < *first1) return false;
	    }
	    return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
				InputIt2 first2, InputIt2 last2)
	{
		for (; first1 != last1 && (first2 != last2); ++first1, ++first2)
		{
			if (!(*first1 == *first2)) {
	            return false;
	        }
		}
		return true;
	}

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
				InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
	    return true;
	}
}

#endif