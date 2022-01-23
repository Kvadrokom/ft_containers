#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <iostream>
#include "Container.hpp"

namespace ft
{
	template <typename Iterator>
	struct reverse_iterator 
	{
	private:
		Iterator iter;

	public:
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		explicit reverse_iterator(const Iterator& iter) : iter(iter){}
		~reverse_iterator(){}
		reverse_iterator(const reverse_iterator &other) { iter = other.iter; }
		reverse_iterator& operator=(const reverse_iterator& other)
		{
			iter = other.iter;
			return *this;
		}

		template <class ConstIter>
		operator  reverse_iterator< ConstIter>() const { return reverse_iterator<ConstIter>(iter); }

		Iterator base() { return iter; }
		Iterator base() const { return iter; }
		typename Iterator::value_type operator *() { return *iter; }
		typename Iterator::pointer operator->() const { return iter.getPtr(); }
		typename Iterator::value_type &operator[](typename Iterator::difference_type n) { return (iter.getPtr())[n]; }
		const reverse_iterator &operator++()
		{
			--iter;
			return *this;
		}
		reverse_iterator& operator--(){++iter; return *this;}
		reverse_iterator operator++( int )
		{
			reverse_iterator copy = *this;
			--iter;
			return copy;
		}
		reverse_iterator operator--( int )
		{
			reverse_iterator copy = *this;
			++iter;
			return copy;
		}
		reverse_iterator operator +(typename Iterator::difference_type n) const { return reverse_iterator(base() - n); }
		reverse_iterator operator -(typename Iterator::difference_type n) const { return reverse_iterator(base() + n); }
		reverse_iterator& operator +=( typename Iterator::difference_type n )
		{
			iter -= n - 1;
			return *this;
		}
		reverse_iterator& operator -=( typename Iterator::difference_type n )
		{
			iter += n + 1;
			return *this;
		}

		bool operator ==(reverse_iterator& rhs) const
		{
			return iter == rhs.iter;
		}

		bool operator !=(reverse_iterator& rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator !=(reverse_iterator rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator <(reverse_iterator& rhs) const
		{
			return iter > rhs.iter;
		}

		bool operator <=(reverse_iterator& rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator>(reverse_iterator& rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>=(reverse_iterator& rhs) const
		{
			return iter <= rhs.iter;
		}
	};
	template <typename Iterator>
	bool operator !=(reverse_iterator<Iterator>& rhs, reverse_iterator<Iterator>& lhs) 
	{
		return rhs.base() != lhs.base();
	}
}


#endif