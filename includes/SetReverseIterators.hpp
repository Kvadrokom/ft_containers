#ifndef SETREVERSEITERATOR_H
#define SETREVERSEITERATOR_H

#include <string>
#include <iostream>
#include "Container.hpp"
#include "MapReverseIterator.hpp"
#include "Utilities.hpp"

namespace ft
{
	template <typename Iterator>
	struct set_reverse_iterator 
	{
	private:
		Iterator iter;

	public:
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		set_reverse_iterator() : iter(Iterator()){};
		explicit set_reverse_iterator(const Iterator &iter) : iter(iter) {}
		~set_reverse_iterator(){}
		set_reverse_iterator(const set_reverse_iterator &other) { iter = other.iter; }
		set_reverse_iterator& operator=(const set_reverse_iterator& other)
		{
			iter = other.iter;
			return *this;
		}

		template <class ConstIter>
		operator  set_reverse_iterator< ConstIter>() const { return set_reverse_iterator<ConstIter>(iter); }

		Iterator base() { return iter; }
		Iterator base() const { return iter; }
		reference operator *() 
		{
			Iterator tmp = iter;
			--tmp;
			return *tmp;
		}
		pointer operator->() const { return &(operator*()); }
		reference operator[](difference_type n) { return (iter[-n - 1]); }
		set_reverse_iterator &operator++()
		{
			--iter;
			return *this;
		}
		set_reverse_iterator& operator--(){++iter; return *this;}
		set_reverse_iterator operator++( int )
		{
			set_reverse_iterator copy = *this;
			--iter;
			return copy;
		}
		set_reverse_iterator operator--( int )
		{
			set_reverse_iterator copy = *this;
			++iter;
			return copy;
		}
		set_reverse_iterator operator +(typename Iterator::difference_type n) const { return set_reverse_iterator(base() - n); }
		set_reverse_iterator operator -(typename Iterator::difference_type n) const { return set_reverse_iterator(base() + n); }
		set_reverse_iterator& operator +=( typename Iterator::difference_type n )
		{
			iter -= n;
			return *this;
		}
		set_reverse_iterator& operator -=( typename Iterator::difference_type n )
		{
			iter += n;
			return *this;
		}

		bool operator ==(set_reverse_iterator& rhs) const
		{
			return iter == rhs.iter;
		}

		bool operator !=(set_reverse_iterator& rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator !=(set_reverse_iterator rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator <(set_reverse_iterator& rhs) const
		{
			return iter > rhs.iter;
		}

		bool operator <=(set_reverse_iterator& rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator>(set_reverse_iterator& rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>=(set_reverse_iterator& rhs) const
		{
			return iter <= rhs.iter;
		}
	};
	template <typename Iterator>
	bool operator !=(set_reverse_iterator<Iterator>& rhs, set_reverse_iterator<Iterator>& lhs) 
	{
		return rhs.base() != lhs.base();
	}
}

#endif