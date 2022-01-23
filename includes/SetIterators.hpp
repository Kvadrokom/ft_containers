#ifndef SETITERATORS_H
#define SETITERATORS_H

#include <string>
#include <iostream>
#include <exception>
#include "Container.hpp"
#include "MapReverseIterator.hpp"
#include "MapIterator.hpp"
#include "RbTree.hpp"

namespace ft
{
	template <class T>
	class set_iterators
	{
		public:
			typedef std::bidirectional_iterator_tag 					iterator_category;
			typedef ft::Node_set<typename ft::remove_const<T>::type >*	node_ptr;
			typedef typename ft::iterator_traits<T*>::value_type 		value_type;
			typedef typename ft::iterator_traits<T*>::reference 		reference;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;

			set_iterators() : box(NULL), root(NULL) {};
			explicit set_iterators(const node_ptr& box, const node_ptr &root) : box(box), root(root) {};
			set_iterators(const set_iterators &other) : box(other.box), root(other.root) {};
			~set_iterators(){};

			template <class Type>
			operator set_iterators<const Type>() const 
			{
				return set_iterators<const Type>(box, root);
			}

			pointer operator->() const { return &root->value; }
			reference	operator*()const{return root->value;}
			node_ptr getPtr() const { return root; }

			set_iterators& operator++()
			{
				if (root == NULL)
					return *this;
				else if (root->right)
					root = min(root->right);
				else if (root == max(box->parent))
					root = NULL;
				else
				{
					while (root->parent->right == root)
						root = root->parent;
					root = root->parent;
				}
				return *this;
			}

			set_iterators& operator--()
			{	
				if (root == NULL)
					root = max(box->parent);
				else if (root->left)
					root = max(root->left);
				else
				{
					while (root->parent->left == root)
						root = root->parent;
					root = root->parent;
				}
				return *this;
			}

			set_iterators operator--(int)
			{
				set_iterators it(*this);
				--(*this);
				return it;
			}

			set_iterators operator++(int)
			{
				set_iterators it(*this);
				++(*this);
				return it;
			}

			node_ptr	min(node_ptr node) const
			{
				if (node)
				{
					while(node->left)
						node = node->left;
				}
				return node;
			}

			node_ptr	max(node_ptr node) const
			{
				if (node)
				{
					while(node->right)
						node = node->right;
				}
				return node;
			}

			friend bool	operator==(const set_iterators& it1, const set_iterators& it2)
			{
				return it1.root == it2.root;
			}

			friend bool	operator!=(const set_iterators& it1, const set_iterators& it2)
			{
				return !(it1 == it2);
			}

		private:
			node_ptr	box;
			node_ptr	root;
	};
}

#endif