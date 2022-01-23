#ifndef Stack_H
#define Stack_H

#include <string>
#include <iostream>
#include <exception>
#include "Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack 
	{
		public:
			typedef T   								value_type;
			typedef Container   						container_type;
			typedef typename container_type::size_type  size_type;

			explicit Stack (const container_type& cont = container_type()) : container(cont) {}

			size_type size() const { return (container.size()); }

			value_type& top(){return (container.back());}

			bool empty() const {return container.empty();}

			const value_type& top() const{return (container.back());}

			void push (const value_type& value) {container.push_back(value);}

			void pop(){container.pop_back();}

		protected:
			container_type container;

			template <class T1, class ContainerType>
			friend bool operator == (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container == rhs.container;}

			template <class T1, class ContainerType>
			friend  bool operator!= (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container != rhs.container;}

			template <class T1, class ContainerType>
			friend bool operator<  (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container < rhs.container;}

			template <class T1, class ContainerType>
			friend bool operator<= (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container <= rhs.container;}

			template <class T1, class ContainerType>
			friend bool operator>  (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container > rhs.container;}

			template <class T1, class ContainerType>
			friend bool operator>= (const Stack<T1,ContainerType>& lhs, const Stack<T1,ContainerType>& rhs)
			{return lhs.container >= rhs.container;}
	};
}

#endif