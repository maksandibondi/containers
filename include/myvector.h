#ifndef VECTOR_H
#define VECTOR_H
#include <bits/allocator.h>
#include <bits/alloc_traits.h>
#include <ext/new_allocator.h>
#include <iterator-traits.h>
#include <math.h>
#include <cstring>
#include <cstddef>
#include <new>
#include <stdexcept>
#include <exception>


template <typename T>
class myvector {

public:
	typedef myRandomAccessIterator<T> iterator;

	typedef myConstRandomAccessIterator<T> const_iterator;

	// Constructors

	myvector() :
		start(),
		_size(),
		_capacity()
	{
	}

	myvector(size_t size) :
		start(new T[size]),
		_size(size),
		_capacity(_size)//Attempts to allocate a block of storage mwith a
						//size large enough to contain n elements of
						//member type value_type (an alias of the
						//allocator's template parameter), and returns a
						//pointer to the first element.

	{
	}

	myvector(size_t size, T value) :
		start(new T[size]),
		_size(size),
		_capacity(_size)
	{
		for (size_t index = 0; index < _size; index++) {
			start[index] = value;
		}
	}

	myvector(const std::initializer_list<T>& list) :
		start(new T[list.size()]),
		_size(list.size()),
		_capacity(_size)

	{
		// calling copy constructor from initializer list
		int index = 0;
		for (iterator it = begin(); it != end(); it++) {
		(*it) = T(*(list.begin() + index));
		index++;
		}

		//std::memcpy(start, list.begin(), list.size() * sizeof(T));
	}

	myvector(const myvector& _myvector) :
		_capacity(_myvector.capacity()),
		start(new T[_capacity]),
		_size(_myvector.size())
	{
		//has to insert a pointer and not an iterator
		//std::memcpy(start, _myvector.start, _myvector.size() * sizeof(T));

		int index = 0;
		for (iterator it = begin(); it != end(); it++) {
		(*it) = T(*(_myvector.cbegin()+index));
		index++;
		}

	}

	myvector& operator = (const std::initializer_list<T>& list) {
		start = new T[list.size()];
		_size = list.size();
		_capacity = _size;
		std::memcpy(start, list.begin(), list.size() * sizeof(T));
		/*
		int index = 0;
		for (iterator it = begin(); it != end(); it++) {
		(*it) = T(list.begin() + index)
		index++;
		}
		*/
	}

	~myvector() {
		delete[] start;
	}

	// Iterators

	iterator begin() {
		return iterator(this->start, this->start, this->_capacity);
		throw std::runtime_error("no memory pointed");
	}

	iterator end() {
		return iterator(this->start + _size, this->start, this->_capacity);
		throw std::runtime_error("no memory pointed");
	}

	const_iterator cbegin() const {
		return const_iterator(this->start, this->start, this->_capacity);
		throw std::runtime_error("no memory pointed");
	}

	const_iterator cend() const {
		return const_iterator(this->start + _size, this->start, this->_capacity);
		throw std::runtime_error("no memory pointed");
	}

	T& front() { return *begin(); }

	const T& front() const { return *begin(); }

	T& back() { return *(end() - 1); }

	const T& back() const { return *(end() - 1); }

	// Insertion and resizing

	void reserve(size_t capacity) {
		if (capacity > _capacity) {
			T* newdata = new T[capacity];
			_capacity = capacity;
			int i = 0;
			for (iterator it = begin(); it != end(); it++) {

				(*(newdata + i)) = T(*it);
				i++;
			}
			start = newdata;
		}
	}

	void resize(size_t size) {
		if (size < _size) {
			for (iterator it = begin() + size; it != end(); it++) {
				(*(it.current)).~T();
			}
			_size = size;
		}
		else if (size > _capacity) {
			_size = size;
			reserve(size);
		}
		else {
			_size = size;
		}

	}

	void push_back(T obj) {
		if (end() != iterator(this->start + _capacity, this->start, this->_capacity)) {
			*(end()) = T(obj);
			++end();
			++_size;

		}
		else {
			reserve(_capacity*2);
			*(end()) = T(obj);
			++end();
			++_size;
		}
	}

	void pop_back() {
		(*(start + _size)).~T();
		--_size;
	}

	iterator erase(iterator position) {
		if (position + 1 != end()) {
			for (iterator it = position + 1; it != end(); it++) {
				(*position) = T(*it);
			}
		}
		resize(_size - 1);
		return position;
	}

	iterator erase(iterator _position_first, iterator _position_last) {
		ptrdiff_t diff = _position_last - _position_first;
		int i = 0;
		if (_position_last != end()) {
			diff += 1;
			for (iterator it = _position_last + i + 1; it != end(); it++) {
				*(_position_first + i) = T(*it);
				i++;
			}
		}

		resize(_size - diff);
		return _position_first;
	}

	void clear() {
		erase(begin(), end());
	}

	iterator insert(iterator position, const T& el) {
		resize(_size + 1);
		for (iterator it = end()-1; it != position; it--) {
			(*it) = T(*(it-1));
		}
		*position = el;
		return position;
	}

	void insert(iterator position, const_iterator first, const_iterator last) {
		ptrdiff_t diff = last - first; // how many elements we insert
		ptrdiff_t index = position - begin();
		resize(_size + diff);
		//
		for (iterator it = end() - 1; it != begin()+index+diff-1; it--) {
			(*it) = T(*(it - diff));
		}
		int i = 0;
		for (iterator itt = begin()+index; itt != begin()+index+diff; itt++) {
			(*itt) = T(*(first+i));
			i++;
		}
	}


	// Accessors

	const size_t size() const {
		return _size;
	}

	const size_t capacity() const {
		return _capacity;
	}

	T& operator[](int position) {
		if (position < _size) {
			return *(start + position);
		}
		throw std::runtime_error("out of range");
	}

	T* operator -> () {
		return this;
	}



private:
	T* start;
	size_t _size;
	size_t _capacity;

};

#endif
