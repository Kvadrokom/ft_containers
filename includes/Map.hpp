#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <exception>
#include "Container.hpp"
#include "MapReverseIterator.hpp"
#include "MapIterator.hpp"

namespace ft
{
template<class Key, class T>	
	struct Node
		{
			pair<const Key, T>	value;
			int					height;
			Node*				parent;
			Node*				left;
			Node*				right;
			Node() : value(), height(0), parent(NULL), left(NULL), right(NULL) {};
			Node(pair<const Key, T> value) : value(value), height(1), parent(NULL), left(NULL), right(NULL){};
			~Node(){};
			int getHeight() { return height; }
			Node*	getLeft() {return left;}
			Node*	getRight() {return right;}
			Node*	getParent() {return parent;}
			pair<const Key, T> getValue() { return value; }
			void removeParent() { parent = NULL; }
			Node *setLeft(Node *newLeft)
			{
				if (newLeft)
					newLeft->parent = this;
				left = newLeft;
				updateHeight();
				return left;
			}
			Node*	setRight(Node* newRight)
			{
				if (newRight)
					newRight->parent = this;
				right = newRight;
				updateHeight();
				return right;
			}
			int	getBalance() const
			{
				int res;
				if (!left)
				{
					if (!right)
						res = 0;
					else
						res = -right->height;
				}
				else if (!right)
					res = left->height;
				else
					res = left->height - right->height;
				return res;
			}
			void	updateHeight()
			{
				if (!left)
				{
					if (!right)
						height = 1;
					else
						height = right->height + 1;
				}
				else if (!right)
					height = left->height + 1;
				else
					height = (right->height > left->height ? right->height : left->height) + 1;
			}
		};


	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class Map
	{
		private:

		class value_compare
			{
			public:
				Compare comp;
				value_compare (Compare c = Compare()) : comp(c) {}
			
				typedef bool 				result_type;
				typedef pair<const Key, T>	first_argument_type;
				typedef pair<const Key, T>	second_argument_type;
				bool operator() (const pair<const Key, T>& x, const pair<const Key, T>& y) const
				{
				  return comp(x.first, y.first);
				}
			};

		public:
			typedef pair<const Key, T>		value_type;
			typedef T 						mapped_type;
			typedef Key 					key_type;
			typedef Compare					key_compare;
			typedef Alloc					allocator_type;
			typedef size_t					size_type;
			typedef Node<Key, T>			Node;

		
		

		typedef common_iterator<const value_type, Node>			const_iterator;
		typedef common_iterator<value_type, Node>				iterator;
		typedef ft::map_reverse_iterator<iterator>				reverse_iterator;
		typedef ft::map_reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef typename Alloc::template rebind<Node>::other	node_allocator_type;


		// operator reverse_iterator<const_iterator>() { return  reverse_iterator<const_iterator>(iterator); }

		explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):mroot(), comp(comp), alloc(alloc)
		{
			fake_node = alloc_node.allocate(1);
			alloc_node.construct(fake_node, Node());
			min = fake_node;
			max = fake_node;
			mroot = fake_node;
			sz = 0;
		}

		template< class InputIt >
		Map( InputIt first, InputIt last, const key_compare& comp = Compare(), const Alloc& alloc = Alloc(),
			typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
		{
			this->alloc = alloc;
			this->comp = comp;
			this->v_comp = value_compare(comp);
			fake_node = alloc_node.allocate(1);
			alloc_node.construct(fake_node, Node());
			min = fake_node;
			max = fake_node;
			mroot = fake_node;
			sz = 0;
			for (; first != last; ++first)
			{
				this->insert(*first);
			}
		}

		Map(const Map &other):sz(0), comp(other.comp), alloc(other.alloc), v_comp(other.v_comp)
		{
			fake_node = alloc_node.allocate(1);
			alloc_node.construct(fake_node, Node());
			mroot = fake_node;
			max = fake_node;
			min = fake_node;
			for (const_iterator it = other.begin(); it != other.end(); ++it)
			{
				insert(*it);
			}
		}

		Map& operator=(const Map &other)
		{
			if (this == &other)
				return *this;;
			Map tmp(other);
			this->swap(tmp);
			return *this;
		}

		~Map() 
		{
			if (sz)
				clear();
			alloc_node.deallocate(fake_node, 1);
			fake_node = NULL;
		}

		void clear() 
		{
			clear_all(mroot);
			sz = 0;
			min = max = fake_node;
		}
		void	clear_all(Node* &root) 
		{
			if (root && root != fake_node)
			{
				if (root->left)
					clear_all(root->left);
				if (root->right)
					clear_all(root->right);
				delete_node(root);
			}
			root = fake_node;
		}

		void	delete_node(Node* &root)
		{
			alloc.destroy(&root->value);
			alloc_node.deallocate(root, 1);
		}

		allocator_type get_allocator() const { return alloc_node; }

		T& at( const Key& key )
		{
			Node *find = findKey(mroot, key);
			if (!findKey(mroot, key))
				throw std::out_of_range("out of range");
			return find->value.second;
		}

		const T& at( const Key& key ) const
		{
			Node *find = findKey(mroot, key);
			if (!findKey(mroot, key))
				throw std::out_of_range("out of range");
			return find->value.second;
		}

		T& operator[]( const Key& key )
		{
			return (*((this->insert(make_pair(key, mapped_type()))).first)).second;
		}

		bool empty() const { return sz == 0; }

		size_type size() const { return sz; }

		size_type max_size() const {return alloc_node.max_size();}

		void swap( Map& other )
		{
			ft::swap(sz, other.sz);
			ft::swap(mroot, other.mroot);
			ft::swap(comp, other.comp);
			ft::swap(alloc, other.alloc);
			ft::swap(max, other.max);
			ft::swap(min, other.min);
			ft::swap(fake_node, other.fake_node);
		}

		size_type count( const Key& key ) const
		{
			if (findKey(mroot, key))
				return 1;
			return 0;
		}

		iterator lower_bound (const key_type& k)
		{
			if (comp(max->value.first, k))
				return end();
			else
			{
				for (iterator it = begin(); it != end(); ++it)
				{
					if (!comp(it->first, k))
						return it;
				}
			}
			return end();
		}

		iterator upper_bound (const key_type& k)
		{
			if (comp(max->value.first, k))
				return end();
			else
			{
				for (iterator it = begin(); it != end(); ++it)
				{
					if (!comp(it->first, k))
					{
						if (!comp(k, it->first) && !comp(it->first, k))
							return ++it;
						return it;
					}
				}
			}
			return end();
		}

		ft::pair<iterator,iterator> equal_range( const Key& key )
		{
			iterator it1 = lower_bound(key);
			iterator it2 = upper_bound(key);
			return make_pair(it1, it2);
		}

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			const_iterator it1 = lower_bound(key);
			const_iterator it2 = upper_bound(key);
			return make_pair(it1, it2);
		}

		key_compare key_comp() const { return Compare(comp); }


		iterator begin() { return iterator(min, max, min, fake_node); }
		const_iterator begin() const { return const_iterator(min, max, min, fake_node); }
		iterator end() { return iterator(fake_node, max, min, fake_node); }
		const_iterator end() const{ return const_iterator(fake_node, max, min, fake_node); }
		reverse_iterator rbegin() { return reverse_iterator(iterator(max, max, min, fake_node)); }
		reverse_iterator rend() { return reverse_iterator(iterator(fake_node, max, min, fake_node)); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(const_iterator(max, max, min, fake_node)); }
		const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(fake_node, max, min, fake_node)); }

		Node *getRoot() const { return mroot; }
		void setRoot(Node *node)
		{
			mroot = node;
			if (mroot)
				mroot->removeParent();
		}

		int	height(const Node *p)
		{
			if (!p)
				return 0;
			int h1 = height(p->left);
			int h2 = height(p->right);
			return ((h1 > h2) ? h1 : h2) + 1;
		}

		int getheight() { return height; }

		void rotateleft(Node* root) // правый поворот вокруг p
		{
			enum
			{
				left,
				right
			} side;
			Node *p = root->getParent();
			if (p && p->getLeft() == root)
				side = left;
			else
				side = right;
			Node *tmp = root->getRight();
			root->setRight(tmp->getLeft());
			tmp->setLeft(root);
			if (!p)
				setRoot(tmp);
			else if (side == left)
				p->setLeft(tmp);
			else
				p->setRight(tmp);
		}

		void rotateright(Node* root) // левый поворот вокруг q
		{
			enum
			{
				left,
				right
			} side;
			Node *p = root->getParent();
			if (p && p->getLeft() == root)
				side = left;
			else
				side = right;
			Node *tmp = root->getLeft();
			root->setLeft(tmp->getRight());
			tmp->setRight(root);
			if (!p)
				setRoot(tmp);
			else if (side == left)
				p->setLeft(tmp);
			else
				p->setRight(tmp);
		}

		Node* findmin(Node* p) const// поиск узла с минимальным ключом в дереве p 
		{
			return p->left ? findmin(p->left):p;
		}

		Node* findmax(Node* p) const// поиск узла с минимальным ключом в дереве p 
		{
			return p->right ? findmax(p->right):p;
		}

		Node*	makeNewNode(const value_type& value)
		{
			Node *newNode = alloc_node.allocate(1);
			alloc_node.construct(newNode, Node(value));
			newNode->height = 1;
			return newNode;
		}

		Node*	findKey(Node *p, Key key )const
		{
			if (!p || p == fake_node)
				return NULL;
			if (p->value.first == key)
				return p;
			while (p)
			{
				if (comp(p->value.first, key))
					p = p->right;
				else if ( comp(key, p->value.first ) )
					p = p->left;
				else
					return p;
			}
			return NULL;
		}

		void	makeBalance(Node* root)
		{
			int bal = root->getBalance();
			if (bal > 1)
			{
				if(root->getLeft()->getBalance() < 0)
					rotateleft(root->getLeft());
				rotateright(root);
			}
			else if (bal < -1)
			{
				if(root->getRight()->getBalance() > 0)
					rotateright(root->getRight());
				rotateleft(root);
			}
		}

		iterator insert( iterator, const value_type& value )
		{
			insert(value);
			iterator it = find(value);
			return it;
		}

		pair<iterator, bool> insert( const value_type& value )
		{
			if (mroot == fake_node)
			{
				mroot = makeNewNode(value);
				sz++;
				max = min = mroot;
				return ft::make_pair(iterator(mroot, max, min, fake_node), true);
			}
			if (Node* p1 = findKey(mroot, value.first))
				return (ft::make_pair(iterator(p1, max, min, fake_node), false));
			Node *add = NULL;
			Node *tmp = mroot;
			while (tmp != NULL && add == NULL)
			{
				if (comp(value.first, tmp->value.first))
				{
					if (tmp->getLeft() == NULL)
						add = tmp->setLeft(makeNewNode(value));
					else
						tmp = tmp->getLeft();
				}
				else if (comp(tmp->value.first, value.first))
				{
					if (tmp->getRight() == NULL)
						add = tmp->setRight(makeNewNode(value));
					else
						tmp = tmp->getRight();
				}
			}
			tmp = add;
			while (tmp)
			{
				tmp->updateHeight();
				makeBalance(tmp);
				tmp = tmp->getParent();
			}
			sz++;
			if (comp(value.first, min->value.first))
				min = add;
			else if (comp(max->value.first, value.first))
				max = add;
			return ft::make_pair(iterator(add, max, min, fake_node), true);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			while (first != last)
				insert(*first++);
		}

		void erase(iterator pos)
		{
			erase(pos.getPtr()->value.first);
		}

		size_type	erase(const key_type& k)
		{
			Node *del = findKey(mroot, k);
			if (!del)
				return 0;
			key_type max_node = max->value.first;
			key_type min_node = min->value.first;
			if (sz)
				--sz;
			key_type val = del->value.first;
			enum
			{
				left,
				right
			} side;
			Node *p = del->getParent();
			if (p && p->getLeft() == del)
				side = left;
			else
				side = right;
			if (!del->getLeft())
			{
				if (!del->getRight())
				{
					if (!p)
					{
						setRoot(fake_node);
						alloc_node.destroy(del);
						alloc_node.deallocate(del, 1);
						min = fake_node;
						max = fake_node;
					}
					else
					{
						if (side == left)
							p->setLeft(NULL);
						else
							p->setRight(NULL);
						alloc_node.destroy(del);
						alloc_node.deallocate(del, 1);
						p->updateHeight();
						makeBalance(p);
					}
				}
				else
				{
					if (!p)
					{
						setRoot(del->getRight());
						alloc_node.destroy(del);
						alloc_node.deallocate(del, 1);
					}
					else
					{
						if (side == left)
							p->setLeft(del->getRight());
						else
							p->setRight(del->getRight());
						alloc_node.destroy(del);
						alloc_node.deallocate(del, 1);
						p->updateHeight();
						makeBalance(p);
					}
				}
			}
			else if (!del->getRight())
			{
				if(!p)
				{
					setRoot(del->getLeft());
					alloc_node.destroy(del);
					alloc_node.deallocate(del, 1);
				}
				else
				{
					if (side == left)
						p->setLeft(del->getLeft());
					else
						p->setRight(del->getLeft());
					alloc_node.destroy(del);
					alloc_node.deallocate(del, 1);
					p->updateHeight();
					makeBalance(p);
				}
			}
			else
			{
				Node *repl;
				Node *repl_par;
				Node *tmp;
				int bal = del->getBalance();
				if (bal > 0)
				{
					if (!del->getLeft()->getRight())
					{
						repl = del->getLeft();
						repl->setRight(del->getRight());
						tmp = repl;
					}
					else
					{
						repl = del->getLeft()->getRight();
						while (repl->getRight())
							repl = repl->getRight();
						repl_par = repl->getParent();
						repl_par->setRight(repl->getLeft());
						tmp = repl_par;
						repl->setLeft(del->getLeft());
						repl->setRight(del->getRight());
					}
				}
				else if (!del->getRight()->getLeft())
				{
					repl = del->getRight();
					repl->setLeft(del->getLeft());
					tmp = repl;
				}
				else
				{
					repl = del->getRight()->getLeft();
					while (repl->getLeft())
						repl = repl->getLeft();
					repl_par = repl->getParent();
					repl_par->setLeft(repl->getRight());
					tmp = repl_par;
					repl->setLeft(del->getLeft());
					repl->setRight(del->getRight());
				}
				if (!p)
					setRoot(repl);
				else if (side == left)
					p->setLeft(repl);
				else
					p->setRight(repl);
				alloc_node.destroy(del);
				alloc_node.deallocate(del, 1);
				makeBalance(tmp);
			}
			if (sz)
			{
				if (val == max_node)
					max = findmax(mroot);
				else if (val == min_node)
					min = findmin(mroot);
			}
			return 1;
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp(first);
				++first;
				erase(tmp);
			}
		}

		iterator find (const value_type& value)
		{
			return find(value.first);
		}

		iterator find (const key_type& k)
		{
			Node *tmp = findKey(mroot, k);
			if (tmp)
				return iterator(tmp, max, min, fake_node);
			return end();
		}
		const_iterator find (const key_type& k) const
		{
			Node *tmp = findKey(mroot, k);
			if (tmp)
				return const_iterator(iterator(tmp, max, min, fake_node));
			return end();
		}

		value_compare value_comp() const { return value_compare(comp); }

		private:

			size_t							sz;
			Node*							mroot;
			Compare							comp;
			Alloc							alloc;
			node_allocator_type				alloc_node;
			Node*							fake_node;
			Node*							max;
			Node*							min;
			value_compare					v_comp;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return  ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return  ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs == rhs) ;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::Map<Key, T, Compare, Alloc>& lhs,
	const ft::Map<Key, T, Compare, Alloc>& rhs )
	{
		return !(rhs > lhs);
	}
}

#endif