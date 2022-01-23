#ifndef MAPITERATOR_H
#define MAPITERATOR_H

#include <string>
#include <iostream>
#include "Container.hpp"
#include "MapReverseIterator.hpp"
#include "Utilities.hpp"

namespace ft
{
	template <class Value, class Node>
	class common_iterator
	{
		public:
			typedef typename ft::iterator_traits<Value*>::value_type 			value_type;
	        typedef typename ft::iterator_traits<Value*>::reference 			reference;
	        typedef typename ft::iterator_traits<Value*>::pointer				pointer;
	        typedef typename ft::iterator_traits<Value*>::difference_type		difference_type;
	        typedef std::bidirectional_iterator_tag iterator_category;

		common_iterator():ptr(0), Max(0), Min(0), fake(0) {};

		common_iterator(Node* ptr, Node* max_ , Node* min_, Node* fake) : ptr(ptr),
							Max(max_), Min(min_), fake(fake) {};

		common_iterator( const common_iterator& other):ptr(other.ptr), Max(other.Max),
						Min(other.Min), fake(other.fake){}

		template <class Type>
		operator common_iterator<const Type, Node>() const 
		{
			return common_iterator<const Type, Node>(ptr, Max, Min, fake);
		}

		common_iterator& operator=(const common_iterator& other)
		{
			ptr = other.ptr;
			Max = other.Max;
			Min = other.Min;
			fake = other.fake;
			return *this;
		}

		Node *getPtr() const { return ptr; }

		Node* min(Node* p) const// поиск узла с минимальным ключом в дереве p 
		{
			return p->left ? min(p->left):p;
		}

		Node *max(Node *root)
		{
			if (root ==NULL)
				return NULL;
			Node *r = root;
			while (r -> right != NULL)
				r = r -> right;
			return r;
		}

		value_type& operator*() { return ptr->value; }
		value_type* operator->() const{ return &ptr->value; }
		value_type* operator->() { return &ptr->value; }
		common_iterator& operator++() 
		{
			if (ptr == fake)
			{
				ptr = Min;
				return *this;
			}
			if (ptr == Max)
			{
				ptr = fake;
				return *this;
			}

			Node *p = ptr, *l = NULL;
			if (p -> right != NULL)
			{
				this->ptr = min(p->right);
				return *this;
			}	
			l = p -> parent;
			while ((l != NULL) && (p == l -> right))
			{
				p = l;
				l = l -> parent;
			}
			this->ptr = l;
			return *this;
		}

		common_iterator& operator--() 
		{
			if (ptr == Min)
			{
				ptr = fake;
				return *this;
			}
			if (ptr == fake)
			{
				ptr = Max;
				return *this;
			}
			Node *p = ptr, *l = NULL;	
			if (p -> left != NULL)
			{
				this->ptr = max(p->left);
				return *this;
			}
			l = p -> parent;
			while ((l != NULL) && (p == l -> left))
			{
				p = l;
				l = l -> parent;
			}
			this->ptr = l;
			return *this;
		}

		common_iterator operator++(int)
		{
			common_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		common_iterator operator--(int)
		{
			common_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		Node *getMax() const { return Max; }
		Node *getMin()const { return Min; }
		Node *getFake()const { return fake; }

		// common_iterator<true>(const common_iterator<false> it)
		// {
		// 	ptr = it.getPtr();
		// 	Max = it.getMax();
		// 	Min = it.getMin();
		// 	fake = it.getFake();
		// }

		bool	operator ==(const common_iterator& it) const {return this->ptr == it.ptr;}
		bool	operator !=(const common_iterator& it) const {return this->ptr != it.ptr;}

	private:
		Node*	ptr;
		Node*	Max;
		Node*	Min;
		Node*	fake;
	};
}

#endif