#ifndef _ITERATORTRAITS_
#define _ITERATORTRAITS_

//#include <myvector.h>
//#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <iterator>


template<typename T>
class myForwardIterator: public std::iterator<std::forward_iterator_tag, T>{
public:
	myForwardIterator(T* ptr){
		current = ptr;
	}
	myForwardIterator(T* ptr, size_t offset){
			start = ptr;
			current = ptr+offset;
		}
	myForwardIterator(const myForwardIterator &);
	myForwardIterator &operator =(const myForwardIterator &);
	bool operator ==(const myForwardIterator &) const;
	bool operator !=(const myForwardIterator &old) const { return !(*this == old); };
	myForwardIterator & operator ++(){
		++current;
		return *this;
	}
	myForwardIterator operator ++(int){
		return myForwardIterator(++current);
	}

	myForwardIterator & operator --(){
			--current;
			return *this;
		}
	T & operator *(){
		return *current;
	}
	T * operator ->(){
		return current;
	}
	~myForwardIterator(){
		delete start;
		delete current;
	}

private :
  T *start;   // The original starts
  int length;  // The Buffer length
  T  *current; // Current iterator position
};

template<typename T>
class myRandomAccessIterator: public std::iterator<std::random_access_iterator_tag, T>{
public:
	myRandomAccessIterator(T* ptr){
		current = ptr;
	}
	/*myRandomAccessIterator(T* ptr, size_t offset){
			start = ptr;
			current = ptr+offset;
		}*/
	myRandomAccessIterator(const myRandomAccessIterator &);
	myRandomAccessIterator &operator =(const myRandomAccessIterator &);
	bool operator ==(const myRandomAccessIterator &) const;
	bool operator !=(const myRandomAccessIterator &old) const { return !(*this == old); };
	myRandomAccessIterator & operator ++(){
		++current;
		return *this;
	}
	myRandomAccessIterator operator ++(int){

		return myRandomAccessIterator(++current);
	}
	myRandomAccessIterator & operator --(){
				--current;
				return *this;
			}
	myRandomAccessIterator operator+(long unsigned int __n) const{
		return myRandomAccessIterator(current + __n);
	}
	myRandomAccessIterator operator-(long unsigned int __n) const{
			return myRandomAccessIterator(current - __n);
		}

	T & operator *(){
		return *current;
	}
	T * operator ->(){
		return current;
	}

	~myRandomAccessIterator(){
		delete start;
		delete current;
	}

private :
  T *start;   // The original starts
  T  *current; // Current iterator position
};

#endif
