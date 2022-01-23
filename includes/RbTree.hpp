#ifndef RBTREE_H
#define RBTREE_H

#include "Container.hpp"
#include "Utilities.hpp"

namespace ft
{
	template <typename T>
	struct Node_set
	{
		T			value;
		Node_set*	parent;
		Node_set*	right;
		Node_set*	left;
		bool		is_black;

		Node_set(const T &value) : value(value), parent(NULL), right(NULL), left(NULL), is_black(false){};
		Node_set() : value(T()), parent(NULL), right(NULL), left(NULL), is_black(false){};
		Node_set& operator=(const Node_set& other)
		{
			value = other.value;
			parent = other.parent;
			right = other.right;
			left = other.left;
			is_black = other.is_black;
			return *this;
		}
	};

	template <class T, class Compare, class Alloc = std::allocator<T> >
	class RBTree
	{
		public:
			typedef Alloc alloc_type;
			typedef typename Alloc::pointer node_p;

			node_p make_node(T value)
			{
				node_p node = alloc.allocate(1);
				alloc.construct(node, value);
				return node;
			}

			void	destroy_node(node_p node)
			{
				if (node)
				{
					alloc.destroy(node);
					alloc.deallocate(node, 1);
				}
			}

			void	change_color(node_p node)
			{
				bool colour = node->is_black;
				node->is_black = node->right->is_black;
				node->right->is_black = colour;
				node->left->is_black = colour;
			}

			node_p	lower(node_p node, T val)
			{
				node_p ptr = NULL;
				while (node)
				{
					if (comp(node->value, val))
						node = node->right;
					else
					{
						if (node->left)
						{
							ptr = lower(node->left, val);
							if (ptr)
								node = ptr;
							break;
						}
						else
							break;
					}
				}
				return node;
			}

			node_p	find(node_p node, T key) const
			{
				if (node)
				{
					if (comp(node->value, key))
						return find(node->right, key);
					else if (comp(key, node->value))
						return find(node->left, key);
				}
				return node;
			}

			node_p	max(node_p node) const
			{
				if (node)
				{
					while (node->right)
					node = node->right;
				}
				return node;
			}

			node_p	min(node_p node) const
			{
				if (node)
				{
					while (node->left)
					node = node->left;
				}
				return node;
			}

			void	erase(node_p* root)
			{
				if (*root)
				{
					if ((*root)->right)
						erase(&(*root)->right);
					if ((*root)->left)
						erase(&(*root)->left);
					destroy_node((*root));
				}
				*root = NULL;
			}

			void	insert_bst(node_p* root, node_p node)
			{
				node_p par;
				node_p grand;
				node_p tmp;
				while (node)
				{
					par = node->parent;
					grand = NULL;
					tmp = par;
					if (par)
					{
						grand = par->parent;
						if(node->is_black == false)
						{
							if(par->is_black == true)
								node = par;
							else if (grand)
							{
								if (grand->left && grand->left->is_black == false && grand->right && grand->right->is_black == false)
								{
									change_color(grand);
									node = grand;
								}
								else if (grand->right == par)
								{
									if (par->left == node)
									{
										rotateright(root, par);
										par = node;
									}
									if (par->right == node)
										rotateleft(root, grand);
									node = par->parent;
								}
								else
								{
									if (par->right == node)
									{
										rotateleft(root, par);
										par = node;
									}
									if (par->left == node)
										rotateright(root, grand);
									node = par->parent;
								}
							}
						}
						else
							node = par;
					}
					else
					{
						node->is_black = true;
						node = node->parent;
					}
				}
			}

			bool	insert(node_p *root, node_p node)
			{
				if (!*root)
				{
					*root = node;
					node->is_black = true;
				}
				else
				{
					node_p add = *root;
					while (add)
					{
						if (!comp(add->value, node->value) && !comp(node->value, add->value))
						{
							if (add != node)
								destroy_node(node);
							return false;
						}
						else if (comp(node->value, add->value))
						{
							if (add->left)
								add = add->left;
							else
							{
								add->left = node;
								node->parent = add;
								break;
							}
						}
						else
						{
							if (add->right)
								add = add->right;
							else
							{
								add->right = node;
								node->parent = add;
								break;
							}
						}
					}
				}
				insert_bst(root, node);
				return true;
			}

			void	change_parent(node_p del, node_p node)
			{
				if (del->parent)
				{
					if(del->parent->left == del)
						del->parent->left = node;
					else
						del->parent->right = node;
				}
				node->parent = del->parent;
				if (del->left)
					del->left->parent = node;
				node->left = del->left;
				if (del->right)
					del->right->parent = node;
				node->right = del->right;
				node->is_black = del->is_black;
			}

			int clear(node_p* root, T key)
			{
				node_p del = find(*root, key);
				if (del)
				{
					node_p node = NULL;
					if (del->left)
						node = delete_left(root , del);
					else if (del->right)
						node = delete_right(root , del);
					else
						delete_list(root , del);
					if (node)
						change_parent(del , node);
					if (del == *root)
					{
						if (node)
							*root = node;
						else
							*root = NULL;
					}
					destroy_node(del);
					return 1;
				}
				return 0;
			}

			node_p	delete_right(node_p *root, node_p node)
			{
				node_p tmp = min(node->right);
				if (tmp)
				{
					if (tmp == node->right)
					{
						node->right = tmp->right;
						if (tmp->right)
							tmp->right->parent = node;
					}
					else
					{
						tmp->parent->left = tmp->right;
						if (tmp->right)
							tmp->right->parent = tmp->parent;
					}
					if (tmp->is_black == true)
					{
						if (tmp->right && tmp->right->is_black == false)
							tmp->right->is_black = true;
						balance(root, tmp->parent);
					}
				}
				return tmp;
			}

			node_p	delete_left(node_p *root, node_p node)
			{
				node_p tmp = max(node->left);
				if (tmp)
				{
					if (tmp == node->left)
					{
						node->left = tmp->left;
						if (tmp->left)
							tmp->left->parent = node;
					}
					else
					{
						tmp->parent->right = tmp->left;
						if (tmp->left)
							tmp->left->parent = tmp->parent;
					}
					if (tmp->is_black == true)
					{
						if (tmp->left && tmp->left->is_black == false)
							tmp->left->is_black = true;
						balance(root, tmp->parent);
					}
				}
				return tmp;
			}

			node_p	delete_list(node_p* root, node_p node)
			{
				node_p tmp = node;
				if (tmp && tmp->parent)
				{
					if (tmp->parent->right == tmp)
						tmp->parent->right = NULL;
					else
						tmp->parent->left = NULL;
					if (tmp->is_black == true)
					{
						if (tmp->right && tmp->right->is_black == false)
							tmp->right->is_black = true;
						balance(root, tmp->parent);
					}
				}
				return tmp;
			}

			void	balance(node_p* root, node_p node)
			{
				node_p b;
				node_p l;
				node_p r;
				while (node != *root && node->is_black)
				{
					b = node->right;
					if (b)
					{
						r = b->right;
						l = b->left;
						if ((r || l) && (!r || r->is_black == true) && (!l || l->is_black == true))
						{
							if (b->is_black == true)
							{
								b->is_black = false;
								node->is_black = true;
								rotateleft(root, node);
							}
							else
								node = node->parent;
						}
						else if (r && b->is_black == true)
						{
							if (l && l->is_black == false && r->is_black == true)
							{
								rotateright(root, b);
								r = b;
								b = l;
							}
							if (r->is_black == false && (!l || l->is_black == true || !node->left))
								rotateleft(root, node);
							else
								node = node->parent;
						}
						else if (b->is_black == true && node->is_black == false)
						{
							node->is_black = false;
							b->is_black = false;
							node = node->parent;
						}
						else
							node = node->parent;
					}
					else
						break;
				}
			}

			void	rotateright(node_p* root, node_p node)
			{
				node_p l = node->left;
				l->parent = node->parent;
				if (l->parent)
				{
					if (l->parent->left == node)
						l->parent->left = l;
					else
						l->parent->right = l;
				}
				node->parent = l;
				node->left = l->right;
				if (node->left)
				{
					if (node->left->parent == l)
						node->left->parent = node;
					else
						node->left->parent = node;
				}
				l->right = node;
				node->is_black = false;
				l->is_black = true;
				if (!l->parent)
					*root = l;
			}

			void	rotateleft(node_p* root, node_p node)
			{
				node_p l = node->right;
				l->parent = node->parent;
				if (l->parent)
				{
					if (l->parent->right == node)
						l->parent->right = l;
					else
						l->parent->left = l;
				}
				node->parent = l;
				node->right = l->left;
				if (node->right)
				{
					if (node->right->parent == l)
						node->right->parent = node;
					else
						node->right->parent = node;
				}
				l->left = node;
				bool col = node->is_black;
				node->is_black = l->is_black;
				l->is_black = col;
				if (!l->parent)
					*root = l;
			}

			private: 
				Compare		comp;
				alloc_type	alloc;
	};
}

#endif