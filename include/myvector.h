#ifndef VECTOR_H
#define VECTOR_H
#include <bits/allocator.h>
#include <bits/alloc_traits.h>
#include <ext/new_allocator.h>
#include <iterator-traits.h>
#include <new>
#include <stdexcept>
#include <exception>

template <class T>
class myvector {

public:
	// new allocator uses operator new in ::allocate function
	//typedef __gnu_cxx::new_allocator<T> alloc_type;

	typedef  myRandomAccessIterator<T> iterator;

	T* data;
	//typename alloc_type::size_type _capacity;
	//typename alloc_type::size_type _size;
	long unsigned int _capacity;
	long unsigned int _size;


	iterator begin(){
		try{
			return iterator(data);
		} catch (std::exception ex){
			return iterator(nullptr);
		}
	}

	iterator end(){

		try{
			return iterator(data+_size);
		} catch (std::exception ex){
			return iterator(nullptr);
		}
	}

	/*
	const_iterator cbegin(){
		try{
			const_iterator(begin());
		} catch (std::exception ex){
				return nullptr;
		}
	}

	const_iterator cend(){
			try{
				const_iterator(end());
			} catch (std::exception ex){
					return nullptr;
			}
		}

	reverse_iterator rbegin(){
			try{
				const_iterator(begin());
			} catch (std::exception ex){
					return nullptr;
			}
		}

	reverse_iterator rend(){
				try{
					reverse_iterator(end());
				} catch (std::exception ex){
						return nullptr;
				}
			}

*/

	T& operator[](long unsigned int position){
			return *(begin()+position);
			throw std::runtime_error("out of range");
	}

	void push_back(int number){
		if (this->_size != this->_capacity){
			*(--end()) = number;
			++this->end();
		} else {
			_capacity = _capacity*2;
			*(--end()) = number;
			++this->end();
		}
	}

	myvector():
			_size(0),
			_capacity(_size),
			data(new T[_size]) //Attempts to allocate a block of storage with a
									  //size large enough to contain n elements of
									  //member type value_type (an alias of the
									  //allocator's template parameter), and returns a
									  //pointer to the first element.

		{
		}


	myvector(int size):
		_size(size),
		_capacity(size),
		data(new T[size]) //Attempts to allocate a block of storage with a
								  //size large enough to contain n elements of
								  //member type value_type (an alias of the
								  //allocator's template parameter), and returns a
								  //pointer to the first element.

	{
	}



};


#endif
