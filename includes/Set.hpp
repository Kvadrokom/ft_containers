#ifndef Set_H
#define Set_H

#include <string>
#include <iostream>
#include <exception>
#include "Container.hpp"
#include "SetIterators.hpp"
#include "MapReverseIterator.hpp"
#include "MapIterator.hpp"
#include "RbTree.hpp"
#include "SetReverseIterators.hpp"

namespace ft
{
	template<class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> > 
	class Set
	{
		public:
			typedef Key															Key_type;
			typedef Key															value_type;
			typedef Compare														value_compare;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef std::ptrdiff_t 												difference_type;
			typedef size_t														size_type;
			typedef Node_set<Key>												Node;
			typedef value_type&													reference;
			typedef typename Alloc::template rebind<Node>::other 				node_allocator_type;
			typedef RBTree<Key, Compare, node_allocator_type>					tree_type;
			typedef typename ft::set_iterators<value_type>						iterator;
			typedef typename ft::set_iterators<const value_type>				const_iterator;
			typedef typename ft::set_reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::set_reverse_iterator<const_iterator>			const_reverse_iterator;

			explicit Set( const Compare& comp = key_compare(), const Alloc& alloc = Alloc()):sz(0), box(NULL), alloc(alloc), comp(comp) 
			{
				box = tree.make_node(Key());
			}

			template< class InputIt >
			Set( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()):sz(0), box(NULL), alloc(alloc), comp(comp)
			{
				box = tree.make_node(Key());
				insert(first, last);
			}

			Set(const Set &other):sz(other.sz), alloc(other.alloc), comp(other.comp)
			{
				box = tree.make_node(Key());
			}

			~Set()
			{
				tree.erase(&box->parent);
				tree.erase(&box);
			}

			Set& operator=( const Set& other )
			{
				clear();
				comp = other.comp;
				alloc = other.alloc;
				insert(other.begin(), other.end());
				return *this;
			}

			void	clear()
			{
				tree.erase(&box->parent);
				box->parent = NULL;
				sz = 0;
			}

			bool empty() const { return sz == 0; }

			size_type size() const { return sz; }

			iterator begin() { return iterator(box, tree.min(box->parent)); }

			const_iterator begin() const { return const_iterator(box, tree.min(box->parent)); }

			iterator end() { return iterator(box, NULL); }

			const_iterator end() const { return const_iterator(box, NULL); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			size_type	max_size() const 
			{
				node_allocator_type alloc;
				return alloc.max_size();
			}

			iterator insert (iterator, const value_type& value)
			{
				sz += tree.insert(&box->parent, tree.make_node(value));
				Node *ptr = tree.find(box->parent, value);
				return iterator(box, ptr);
			}

			iterator find (const Key_type& k)
			{
				Node *ptr = tree.find(box->parent, k);
				return iterator(box, ptr);
			}

			ft::pair<iterator, bool> insert (const value_type& value)
			{
				bool ins = tree.insert(&box->parent, tree.make_node(value));
				if (ins)
					++sz;
				Node *ptr = tree.find(box->parent, value);
				return ft::pair<iterator, bool>(iterator(box, ptr), ins);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (; first != last; ++first)
					insert(*first);
			}

			void	swap(Set& other)
			{
				ft::swap(sz, other.sz);
				ft::swap(box, other.box);
				ft::swap(alloc, other.alloc);
				ft::swap(comp, other.comp);
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			size_type erase (const Key_type& key)
			{
				int ins = tree.clear(&box->parent, key);
				if (ins)
					--sz;
				return ins;
			}

			void erase (iterator it)
			{
				int res = tree.clear(&box->parent, *it);
				if (res)
					--sz;
			}

			iterator lower_bound (const Key_type& val)
			{
				return iterator(box, tree.lower(box->parent, val));
			}

			iterator upper_bound (const Key_type& val)
			{
				Node *node = tree.lower(box->parent, val);
				iterator it(box, node);
				if (node && node->value == val)
					++it;
				return it;
			}

			ft::pair<iterator, iterator> equal_range (const Key_type& val)
			{
				return ft::make_pair(lower_bound(val), upper_bound(val));
			}

			size_type count(const Key_type& key) const
			{
				if (tree.find(box->parent, key))
					return 1;
				return 0;
			}

			void	print()
			{
				for (iterator it = begin(); it != end(); ++it)
					std::cout << *it << ' ';
				std::cout << '\n';
			}

			allocator_type get_allocator() const { return alloc; }

			value_compare value_comp() const { return comp; }

			key_compare key_comp() const { return comp; }

		private:
			size_type		sz;
			tree_type		tree;
			Node*			box;
			allocator_type	alloc;
			key_compare		comp;
	};

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return  ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return  ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return !(lhs == rhs) ;
	}

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::Set<Key, Compare, Alloc>& lhs,
	const ft::Set<Key, Compare, Alloc>& rhs )
	{
		return !(rhs > lhs);
	}
}

#endif