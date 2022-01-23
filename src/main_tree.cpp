#include "../includes/RbTree.hpp"
#include <string>

int main()
{
	ft::Node<int> *a;
	ft::Node<int> *b;
	ft::RBTree< ft::Node<int>, std::less<int> > tree;
	a = tree.make_node(int());
	tree.insert(&a, tree.make_node(10));
}