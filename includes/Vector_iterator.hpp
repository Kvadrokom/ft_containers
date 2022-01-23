#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include <string>
#include <iostream>
#include "Container.hpp"
#include <iterator>

namespace ft
{

	template <class T>
	class vector_iterator
		{

			public:
				typedef typename iterator_traits<T>::value_type	 		value_type;
				typedef typename iterator_traits<T>::difference_type	difference_type;
				typedef typename iterator_traits<T>::pointer			pointer;
				typedef typename iterator_traits<T>::reference			reference;
				typedef	std::random_access_iterator_tag 				iterator_category;
				typedef typename iterator_traits<T>::pointer			iterator_type;

				explicit vector_iterator(const T& ptr) : ptr(ptr){};

				vector_iterator() : ptr(T()){};

				template <class Type>
				operator vector_iterator<Type>() const 
				{
					return vector_iterator<Type>(ptr);
				}

				template <class Iter>
				vector_iterator&	operator=(const vector_iterator<Iter>& other) 
				{
					ptr = other.getPtr();
					return *this;
				}

				reference& operator*() { return *ptr; }

				pointer* operator->() { return ptr; }

				friend bool	operator ==(const vector_iterator& it1, const vector_iterator& it2)  {return it1.ptr == it2.ptr;}
				friend bool	operator !=(const vector_iterator& it1, const vector_iterator& it2) {return it1.ptr != it2.ptr;}
				friend bool	operator <(const vector_iterator& it1, const vector_iterator& it2)  {return it1.ptr < it2.ptr;}
				friend bool	operator >(const vector_iterator& it1, const vector_iterator& it2)  {return it1.ptr > it2.ptr;}
				friend bool	operator <=(const vector_iterator& it1, const vector_iterator& it2)  {return it1.ptr <= it2.ptr;}
				friend bool	operator >=(const vector_iterator& it1, const vector_iterator& it2)  {return it1.ptr >= it2.ptr;}
				vector_iterator&	operator +=(int n)
				{
					ptr += n;
					return *this;
				}

				vector_iterator&	operator -=(int n)
				{
					ptr -= n;
					return *this;
				}

				vector_iterator& operator++()
				{
					++ptr;
					return *this;
				}

				vector_iterator	operator ++(int)
				{
					vector_iterator copy = *this;
					*this += 1;
					return copy;
				}

				vector_iterator	operator --(int)
				{
					vector_iterator copy = *this;
					*this -= 1;
					return copy;
				}

				vector_iterator& operator--()
				{
					--ptr;
					return *this;
				}

				vector_iterator operator-(int n){return vector_iterator(ptr - n);}
				vector_iterator operator+(int n){return vector_iterator(ptr + n);}

				difference_type operator-(const vector_iterator& it)const {return (ptr - it.ptr);}

				reference& operator [](size_t index){return ptr[index];}

				value_type*	getPtr(){return ptr;}
				pointer	getPtr() const {return ptr;}

				friend vector_iterator operator+(int num, const vector_iterator& it)
				{
					vector_iterator newIT(it);
					return (newIT += num);
				}

				friend vector_iterator operator-(int num, const vector_iterator& it)
				{
					vector_iterator newIT(it);
					return (newIT -= num);
				}

			private:
				T	ptr;
		};
}




#endif