#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H

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

		reverse_iterator():iter(Iterator()){}
		
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

		template <class Iter>
        reverse_iterator&	operator=(reverse_iterator<Iter> const & other) 
		{
			iter = other.base();
			return *this;
		}

		Iterator base() { return iter; }
		Iterator base() const { return iter; }
		reference operator *() const 
		{
			return *iter.getPtr();
		}
		pointer operator->() const { return iter.getPtr(); }
		reference operator->() { return &iter.getPtr()->value; }
		value_type &operator[](difference_type n) { return (iter.getPtr())[n]; }
		reverse_iterator &operator++()
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
		reverse_iterator operator +(difference_type n) const { return reverse_iterator(base() - n); }
		reverse_iterator operator -(difference_type n) const { return reverse_iterator(base() + n); }
		reverse_iterator& operator +=(difference_type n )
		{
			iter -= n;
			return *this;
		}
		reverse_iterator& operator -=( difference_type n )
		{
			iter += n;
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

		bool operator <(reverse_iterator rhs) const
		{
			return iter > rhs.iter;
		}

		bool operator <=(reverse_iterator& rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator <=(reverse_iterator rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator>(reverse_iterator& rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>(reverse_iterator rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>=(reverse_iterator& rhs) const
		{
			return iter <= rhs.iter;
		}

		bool operator>=(reverse_iterator rhs) const
		{
			return iter <= rhs.iter;
		}

		friend reverse_iterator operator+(int num, const reverse_iterator& it)
		{
			reverse_iterator newIT(it);
			return (newIT += num);
		}

		friend reverse_iterator operator-(int num, const reverse_iterator& it)
		{
			reverse_iterator newIT(it);
			return (newIT -= num);
		}

		difference_type operator-(const reverse_iterator& it)
		{
			return (it.iter - iter);
		}


	};

	template <typename Iterator>
	bool operator !=(reverse_iterator<Iterator>& rhs, reverse_iterator<Iterator>& lhs) 
	{
		return rhs.base() != lhs.base();
	}
}


#endif
