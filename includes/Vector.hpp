#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>
#include <exception>
#include <iterator>
#include "Container.hpp"
#include "Iterator.hpp"
#include "Utilities.hpp"
#include "Vector_iterator.hpp"
#include <math.h>



namespace ft
{
	template<class InputIt, class ForwardIt>
	ForwardIt uninitialized_copy(InputIt first, InputIt last, ForwardIt d_first)
	{
	    typedef typename std::iterator_traits<ForwardIt>::value_type Value;
	    ForwardIt current = d_first;
	    try {
	        for (; first != last; ++first, (void) ++current) {
	            ::new (static_cast<void*>(std::addressof(*current))) Value(*first);
	        }
	        return current;
	    } catch (...) {
	        for (; d_first != current; ++d_first) {
	            d_first->~Value();
	        }
	        throw;
	    }
	}



	template <typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
	private:
		T					*arr;
		size_t				sz;
		size_t				cap;
		Alloc				alloc;

	public:
		typedef T   														value_type;
		typedef Alloc 														allocator_type;
		typedef typename allocator_type::reference 							reference;
		typedef typename allocator_type::pointer 							pointer;
		typedef typename allocator_type::const_reference 					const_reference;
		typedef typename allocator_type::const_pointer 						const_pointer;
		typedef ft::vector_iterator<T *>	    							iterator;
		typedef ft::vector_iterator<const T *>								const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 						const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type			difference_type;
		typedef std::size_t													size_type;


		explicit Vector(const allocator_type &alloc = allocator_type()) : arr(0), sz(0), cap(0), alloc(alloc){};

		explicit Vector(size_t count, const T &value = T(), const allocator_type &alloc_ = allocator_type()):
						arr(0), sz(0), cap(0), alloc(alloc_)
		{
			sz = count;
			arr = this->alloc.allocate(count);
			size_t i;
			try
			{
				for (i = 0; i < count; i++)
				{
					this->alloc.construct(arr + i, T(value));
				}
			}
			catch(...)
			{
				for (size_t j = 0; j < i; j++)
					this->alloc.destroy(arr + j);
				this->alloc.deallocate(arr, count);
				throw;
			}
			cap = count;
		}

		template< typename InputIt >
		Vector( InputIt first, InputIt last, const allocator_type& alloc_ = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0):
				arr(0), sz(0), cap(0), alloc(alloc_)
		{
			sz = last - first;
			cap = sz;
			arr = alloc.allocate(cap);
			for (size_t i = 0; i < sz; i++)
			{
				alloc.construct(arr + i, T(*first));
				first++;
			}
		}

		void	reserve(size_t n)
		{
			if (n <= cap)
				return;
			T *newarr = alloc.allocate(n);
			for (size_t i = 0; i < sz; i++)				
			{
				alloc.construct(newarr + i, T(arr[i]));
				alloc.destroy(arr + i);
			}
			alloc.deallocate(arr, cap);
			cap = n;
			arr = newarr;
		}

		Vector( const Vector& other ):alloc(other.alloc)
		{
			if (this == &other)
				return ;
			T*	tmp;
			cap = other.cap;
			tmp = alloc.allocate(cap);
			sz = other.sz;
			for (size_t i = 0; i < sz; i++)
				alloc.construct(tmp + i, T(other.arr[i]));
			arr = tmp;
		}
		~Vector()
		{
			for (size_t i = 0; i < sz; i++)
			{
				alloc.destroy(arr + i);
			}
			alloc.deallocate(arr, cap);
		}

		Vector& operator=(const Vector& other)
		{
			if (this == &other)
				return *this;;	
			cap = other.cap;
			sz = other.sz;
			const_iterator it_begin = other.begin();
			const_iterator it_end = other.end();
			value_type* tmp = alloc.allocate(cap);
			try
			{
				std::uninitialized_copy(it_begin, it_end, tmp);
			}
			catch(...)
			{
				alloc.deallocate(tmp, cap);
			}
			for (size_t i = 0; i < sz; i++)
				alloc.destroy(arr + i);
			alloc.deallocate(arr, cap);
			arr = tmp;
			return *this;
		}

		value_type&	operator[](int index)
		{
			return arr[index];
		}

		const value_type&	operator[](int index) const
		{
			return arr[index];
		}

		size_type	size()const {return sz;}

		size_type	capacity(){return cap;}

		void assign( size_type count, const T& value )
		{
			for (size_t i = 0; i < sz; i++)
				alloc.destroy(arr + i);
			sz = count;
			if (sz > cap)
			{
				alloc.deallocate(arr, cap);
				cap = sz;
				arr = alloc.allocate(cap);
			}
			for (size_t i = 0; i < sz; i++)
				alloc.construct(arr + i, T(value));
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last,
					typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
		{
			for (size_t i = 0; i < sz; i++)
				alloc.destroy(arr + i);
			sz = last - first;
			if (sz > cap)
			{
				alloc.deallocate(arr, cap);
				cap = sz;
				arr = alloc.allocate(cap);
			}
			for (size_t i = 0; i < sz; i++)
			{
				alloc.construct(arr + i, T(*first));
				first++;
			}
		}


		iterator begin() { return iterator(arr); }
		iterator end() { return iterator(arr + sz); }
		const_iterator begin() const { return const_iterator(arr); }
		const_iterator end() const { return const_iterator(arr + sz); }
		reverse_iterator rbegin() { return reverse_iterator(--end()); }
		reverse_iterator rend() { return reverse_iterator(--begin()); }
		const_reverse_iterator rbegin() const {return const_reverse_iterator(--end());}
		const_reverse_iterator rend() const { return const_reverse_iterator(--begin()); }

		iterator erase( iterator pos )
		{			
			size_type z = pos - begin();
			alloc.destroy(&arr[z]);
			for (size_t i = 0; z + i != sz; i++)
			{
				alloc.construct(arr + i + z, arr[z + i + 1]);
				alloc.destroy(arr + z + i + 1);
			}
			sz -= 1;
			return pos;
		}

		iterator erase( iterator first, iterator last )
		{
			if (first == last)
				return first;
			size_t count = last - first;
			size_t z = first - begin();
			sz -= count;
			for (; first != last; first++)
				alloc.destroy(first.getPtr());
			for (size_t i = z; i < sz; i++)
				alloc.construct(arr + i, T(arr[i + count]));
			return first;
		}

		void resize( size_type count, T value = T() )
		{
			if (sz == count)
				return;
			if (count < sz)
			{
				iterator it = begin() + count;
				for (; it != end(); it++)
					alloc.destroy(it.getPtr());
				sz = count;
			}
			else if (count > cap)
			{
				size_t cap_ = cap;
				cap *= 2;
				if (cap < count)
					cap = count;
				T* tmp = alloc.allocate(cap);
				for (size_t i = 0; i < sz; i++)
					alloc.construct(tmp + i, T(arr[i]));
				for (size_t i = sz; i < count; i++)
					alloc.construct(tmp + i, value);
				for (size_t i = 0; i < sz; i++)
					alloc.destroy(arr + i);
				alloc.deallocate(arr, cap_);
				arr = tmp;
				sz = count;
			}
			else if (count == cap || sz < count)
			{
				for (size_t i = sz; i < count; i++)
					alloc.construct(arr + i, value);
				sz = count;
			}

		}

		iterator insert( iterator pos, const T& value )
		{
			sz += 1;
			size_t z =  pos.getPtr() - arr;
			if (sz > cap)
				cap = 2 * sz;
			if (z == 0)
			{
				arr = alloc.allocate(cap);
				alloc.construct(arr, T(value));
				return begin();
			}
			T* tmp = alloc.allocate(cap);
			try
			{
				for (size_t i = 0; i < z - 1; i++)
					alloc.construct(tmp + i, T(arr[i]));
				alloc.construct(tmp + z - 1, T(value));
				for (size_t i = z; i < sz; i++)
					alloc.construct(tmp + i + 1, T(arr[i]));
			}
			catch(...)
			{
				for (size_t i = 0; i < sz - 1; i++)
					alloc.destroy(tmp + i);
				alloc.deallocate(tmp, cap);
				sz -= 1;
				throw;
			}
			for (size_t i = 0; i < sz - 1; i++)
			{
				alloc.destroy(arr + i);
			}
			alloc.deallocate(arr, cap);
			arr = tmp;
			return iterator(arr + z - 1);
		}

		void insert( iterator pos, size_t count, const T& value )
		{
			sz += count;
			size_t z =  pos - begin();
			if (sz > cap)
				cap = sz;
			T* tmp = alloc.allocate(cap);
			if (z == 0)
			{
				for (size_t i = 0; i < sz; i++)
					alloc.construct(tmp + i, T(value));
			}
			else
			{
				for (size_t i = 0; i < z; i++)
					alloc.construct(tmp + i, T(arr[i]));
				for (size_t i = z - 1; i < z + count; i++)
					alloc.construct(tmp + i, T(value));
				for (size_t i = z + count; i < sz; i++)
					alloc.construct(tmp + i, T(arr[i - count]));
			}
			
			for (size_t i = 0; i < sz; i++)
			{
				alloc.destroy(arr + i);
			}
			alloc.deallocate(arr, cap);
			arr = tmp;
		}

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last,
					typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
		{
			size_t count = last - first;
			sz += count;
			size_t z =  pos - begin();
			size_t cap_ = cap;
			if (sz > cap)
				cap *= 2;
			if (cap < sz)
				cap = sz;
			T *tmp = alloc.allocate(cap);
			try
			{
				std::uninitialized_copy(begin(), pos, tmp);
				std::uninitialized_copy(first, last, tmp + z);
				for (size_t i = z + count; i < sz; i++)
				{
					alloc.construct(tmp + i, T(arr[i - count]));
				}
			}
			catch(...)
			{
				alloc.deallocate(tmp, cap);
				sz -= count;
				cap = cap_;
				throw;
			}
			for (size_t i = 0; i < sz - count; i++)
				alloc.destroy(arr + i);
			alloc.deallocate(arr, cap_);
			arr = tmp;
		}

		Alloc get_allocator() const {return alloc;}

		reference at( size_t pos )
		{
			if (pos >= sz)
				throw std::out_of_range("out of range");
			return arr[pos];
		}

		reference front(){return *begin();}
		const_reference front() const {return *begin();}

		reference back(){return arr[sz - 1];}
		const_reference back()const {return arr[sz];}

		bool empty() const {return begin() == end();}

		size_type max_size() const
		{
			if (sizeof(value_type) == 1)
				return static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1;
			return static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1;
		}

		void clear()
		{
			for (size_t i = 0; i < sz; i++)
			{
				alloc.destroy(arr + i);
			}
			sz = 0;
		}

		T* data(){return arr;}
		const T* data() const {return arr;}

		void push_back( const T& value )
		{
			sz += 1;
			if (sz > cap)
			{
				cap = 2 * sz;
				T* tmp = alloc.allocate(cap);
				for (size_type i = 0; i < sz - 1; i++)
					alloc.construct(tmp + i, T(arr[i]));
				alloc.construct(tmp + sz - 1, T(value));
				for (size_type i = 0; i < sz - 1; i++)
					alloc.destroy(arr + i);
				alloc.deallocate(arr, cap);
				arr = tmp;
			}
			else
				alloc.construct(arr + sz - 1, T(value));
		}

		void pop_back()
		{
			alloc.destroy(arr + sz - 1);
			sz -= 1;
		}

		void swap( Vector& other )
		{
			ft::swap(arr, other.arr);
			ft::swap(sz, other.sz);
			ft::swap(cap, other.cap);
			ft::swap(alloc, other.alloc);
		}

	};
	
	template< class T, class Alloc >
	bool operator==( const ft::Vector<T, Alloc>& lhs,
					const ft::Vector<T, Alloc>& rhs )
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator!=( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	bool operator<=( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs )
	{
		return !(lhs <= rhs);
	}

	template< class T, class Alloc >
	bool operator>=( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs )
	{
		return !(rhs > lhs);
	}
};

#endif