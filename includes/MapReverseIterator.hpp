#ifndef MAPREVERSEITERATOR_H
#define MAPREVERSEITERATOR_H

#include <string>
#include <iostream>
#include "Container.hpp"

namespace ft
{
	template <typename Iterator>
	struct map_reverse_iterator 
	{
	private:
		Iterator iter;

	public:
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		map_reverse_iterator():iter(Iterator()){}
		
		explicit map_reverse_iterator(const Iterator& iter) : iter(iter){}

		~map_reverse_iterator(){}
		map_reverse_iterator(const map_reverse_iterator &other) { iter = other.iter; }
		map_reverse_iterator& operator=(const map_reverse_iterator& other)
		{
			iter = other.iter;
			return *this;
		}

		template <class ConstIter>
		operator  map_reverse_iterator< ConstIter>() const { return map_reverse_iterator<ConstIter>(iter); }

		template <class Iter>
        map_reverse_iterator&	operator=(map_reverse_iterator<Iter> const & other) 
		{
			iter = other.base();
			return *this;
		}

		Iterator base() { return iter; }
		Iterator base() const { return iter; }
		reference operator *() const 
		{
			return iter.getPtr()->value;
		}

		pointer operator->() { return &(iter.getPtr()->value); }
		value_type &operator[](difference_type n) { return (iter.getPtr())[n]; }
		map_reverse_iterator &operator++()
		{
			--iter;
			return *this;
		}
		map_reverse_iterator& operator--(){++iter; return *this;}
		map_reverse_iterator operator++( int )
		{
			map_reverse_iterator copy = *this;
			--iter;
			return copy;
		}
		map_reverse_iterator operator--( int )
		{
			map_reverse_iterator copy = *this;
			++iter;
			return copy;
		}
		map_reverse_iterator operator +(difference_type n) const { return map_reverse_iterator(base() - n); }
		map_reverse_iterator operator -(difference_type n) const { return map_reverse_iterator(base() + n); }
		map_reverse_iterator& operator +=(difference_type n )
		{
			iter -= n;
			return *this;
		}
		map_reverse_iterator& operator -=( difference_type n )
		{
			iter += n;
			return *this;
		}

		bool operator ==(map_reverse_iterator& rhs) const
		{
			return iter == rhs.iter;
		}

		bool operator !=(map_reverse_iterator& rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator !=(map_reverse_iterator rhs) const
		{
			return iter != rhs.iter;
		}

		bool operator <(map_reverse_iterator& rhs) const
		{
			return iter > rhs.iter;
		}

		bool operator <(map_reverse_iterator rhs) const
		{
			return iter > rhs.iter;
		}

		bool operator <=(map_reverse_iterator& rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator <=(map_reverse_iterator rhs) const
		{
			return iter >= rhs.iter;
		}

		bool operator>(map_reverse_iterator& rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>(map_reverse_iterator rhs) const
		{
			return iter < rhs.iter;
		}

		bool operator>=(map_reverse_iterator& rhs) const
		{
			return iter <= rhs.iter;
		}

		bool operator>=(map_reverse_iterator rhs) const
		{
			return iter <= rhs.iter;
		}

		friend map_reverse_iterator operator+(int num, const map_reverse_iterator& it)
		{
			map_reverse_iterator newIT(it);
			return (newIT += num);
		}

		friend map_reverse_iterator operator-(int num, const map_reverse_iterator& it)
		{
			map_reverse_iterator newIT(it);
			return (newIT -= num);
		}

		difference_type operator-(const map_reverse_iterator& it)
		{
			return (it.iter - iter);
		}


	};

	template <typename Iterator>
	bool operator !=(map_reverse_iterator<Iterator>& rhs, map_reverse_iterator<Iterator>& lhs) 
	{
		return rhs.base() != lhs.base();
	}
}


#endif