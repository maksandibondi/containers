#ifndef _ITERATORTRAITS_
#define _ITERATORTRAITS_

#include <typeinfo>     // typeid
#include <iterator>

// Predeclarations
template <typename T>
class mynode;

template <typename T>
class my_list;

template <typename T>
class myvector;

template<typename T>
class myConstRandomAccessIterator;

template<typename T>
class myRandomAccessIterator : public std::iterator<std::random_access_iterator_tag, T> {
	friend myvector<T>;
	friend myConstRandomAccessIterator<T>;
public:
	myRandomAccessIterator() : start(), current(), capacity() {
	}

	myRandomAccessIterator(T* ptr) {
		this->current = ptr;
	}

	myRandomAccessIterator(T* ptr, T* start, size_t capacity) {
		this->current = ptr;
		this->start = start;
		this->capacity = capacity;
	}

	myRandomAccessIterator(const myRandomAccessIterator &rhs) {
		start = rhs.start;
		current = rhs.current;
		this->capacity = rhs.capacity;
	};

	myRandomAccessIterator operator =(const myRandomAccessIterator &rhs) {
		return myRandomAccessIterator(rhs.current, rhs.start, rhs.capacity);
	};

	bool operator ==(const myRandomAccessIterator &rhs) const {
		return (current == rhs.current && start == rhs.start && capacity == rhs.capacity);
	};

	bool operator !=(const myRandomAccessIterator &old) const {
		return !(*this == old);
	};

	myRandomAccessIterator & operator ++() {
		++current;
		return *this;
	}

	myRandomAccessIterator operator ++(int) {
		return myRandomAccessIterator(++current, start, capacity);
	}

	myRandomAccessIterator & operator --() {
		--current;
		return *this;
	}

	myRandomAccessIterator operator --(int) {
		return myRandomAccessIterator(--current, start, capacity);
	}

	myRandomAccessIterator operator+(ptrdiff_t n) const {
		return myRandomAccessIterator(current + n, start, capacity);
	}

	myRandomAccessIterator operator-(ptrdiff_t n) const {
		return myRandomAccessIterator(current - n, start, capacity);
	}

	ptrdiff_t operator- (const myRandomAccessIterator& rhs) const {
		return (this->current - rhs.current);
	}

	myRandomAccessIterator operator-=(ptrdiff_t n) const {
		current -= n;
		return *this;
	}

	myRandomAccessIterator operator+=(ptrdiff_t n) const {
		current -= n;
		return *this;
	}

	bool operator< (const myRandomAccessIterator& rhs) const {
		return ((this->current) < (rhs.current));
	}

	bool operator<= (const myRandomAccessIterator& rhs) const {
		((this->current) <= (rhs.current));
	}

	bool operator> (const myRandomAccessIterator& rhs) const {
		((this->current) > (rhs.current));
	}

	bool operator>= (const myRandomAccessIterator& rhs) const {
		((this->current) >= (rhs.current));
	}

	T & operator *() {
		return *current;
	}

	T * operator ->() {
		return current;
	}

private:
	T *start;   // The original starts
	T  *current; // Current iterator position (iterator in fact)
	size_t capacity;
};

template<typename T>
class myConstRandomAccessIterator : public std::iterator<std::random_access_iterator_tag, T> {
	friend myvector<T>;
public:
	myConstRandomAccessIterator() : start(), current(), capacity() {
	}

	myConstRandomAccessIterator(const myRandomAccessIterator<T> &iter):
		current(iter.current),
		start(iter.start),
		capacity(iter.capacity)
	{

	}

	myConstRandomAccessIterator(T* ptr):
		current(ptr),
		start(),
		capacity()
	{
	}

	myConstRandomAccessIterator(T* ptr, T* start, size_t capacity):
		current(ptr),
		start(start),
		capacity(capacity)
	{
	}

	myConstRandomAccessIterator(const T* ptr, const T* start, size_t capacity) :
		current(ptr),
		start(start),
		capacity(capacity)
	{
	}

	myConstRandomAccessIterator(const myConstRandomAccessIterator &rhs):
		start(rhs.start),
		current(rhs.current),
		capacity(rhs.capacity)
	{
	}

	myConstRandomAccessIterator operator =(const myConstRandomAccessIterator &rhs) {
		return myConstRandomAccessIterator(rhs.current, rhs.start, rhs.capacity);
	};

	bool operator ==(const myConstRandomAccessIterator &rhs) const {
		return (current == rhs.current && start == rhs.start && capacity == rhs.capacity);
	};

	bool operator !=(const myConstRandomAccessIterator &old) const {
		return !(*this == old);
	};

	myConstRandomAccessIterator & operator ++() {
		++current;
		return *this;
	}

	myConstRandomAccessIterator operator ++(int) {
		return myConstRandomAccessIterator(++current, start, capacity);
	}

	myConstRandomAccessIterator & operator --() {
		--current;
		return *this;
	}

	myConstRandomAccessIterator operator --(int) {
		return myConstRandomAccessIterator(--current, start, capacity);
	}

	myConstRandomAccessIterator operator+(ptrdiff_t n) const{
		return myConstRandomAccessIterator(current + n, start, capacity);
	}

	myConstRandomAccessIterator operator-(ptrdiff_t n) const {
		return myConstRandomAccessIterator(current - n, start, capacity);
	}

	ptrdiff_t operator- (const myConstRandomAccessIterator& rhs) const {
		return (this->current - rhs.current);
	}

	myConstRandomAccessIterator operator-=(ptrdiff_t n) const {
		current -= n;
		return *this;
	}

	myConstRandomAccessIterator operator+=(ptrdiff_t n) const {
		current -= n;
		return *this;
	}

	bool operator< (const myConstRandomAccessIterator& rhs) const {
		return ((this->current) < (rhs.current));
	}

	bool operator<= (const myConstRandomAccessIterator& rhs) const {
		((this->current) <= (rhs.current));
	}

	bool operator> (const myConstRandomAccessIterator& rhs) const {
		((this->current) > (rhs.current));
	}

	bool operator>= (const myConstRandomAccessIterator& rhs) const {
		((this->current) >= (rhs.current));
	}


	const T & operator *() {
		return *current;
	}

	const T * operator ->() {
		return current;
	}

private:
	const T *start;   // The original starts
	const T  *current; // Current iterator position (iterator in fact)
	size_t capacity;

};



// Iterators list
template <typename T>
class myListIterator {
	friend mynode<T>;
	friend my_list<T>;
	mynode<T>* node;

public:
	myListIterator() {}

	myListIterator(mynode<T>* x): node(x) {}

	myListIterator(const myListIterator<T>& iter) : node(iter.node) {}

	myListIterator<T> operator =(const myListIterator<T>& rhs) {
		return myListIterator(rhs.node);
	};

	bool operator ==(const myListIterator<T>& rhs) const {
		return (node == rhs.node);
	};

	bool operator !=(const myListIterator<T>& old) const {
		return !(*this == old);
	};

	T& operator*() {
		return node->_data;
	}

	T* operator->() {
		return &(operator*);
	}

	myListIterator<T> operator+(int _i) {
		int i = 0;
		while (i < _i) {
			node = node->_next;
			i++;
		}
		return *this;
	}

	myListIterator<T> operator-(int _i) {
		int i = 0;
		while (i < _i) {
			node = node->_prev;
			i++;
		}
		return *this;
	}

	myListIterator<T> operator++() {
		node = node->_next;
		return *this;
	}

	myListIterator<T> operator++(int) {
		myListIterator _tmp = *this;
		node = node->_next;
		return _tmp;
	}

	myListIterator<T> operator--() {
		node = node->_prev;
		return *this;
	}

	myListIterator<T> operator--(int) {
		myListIterator _tmp = *this;
		node = node->_prev;
		return _tmp;
	}
};

template <typename T>
class myConstListIterator {
	mynode<T>* node;
	myConstListIterator() {}
	myConstListIterator(mynode<T>* x) : node(x) {}
	myConstListIterator(const myListIterator<T>& iter) : node(iter.node) {}
	const T& operator*() {
		return node->data;
	}
	const T* operator->() {
		return &(operator*);
	}
	myConstListIterator<T> operator++() {
		node = node->_next;
		return *this;
	}
	myConstListIterator<T> operator++(int) {
		myConstListIterator _tmp = *this;
		node = node->_next;
		return _tmp;
	}
	myConstListIterator<T> operator--() {
		node = node->_prev;
		return *this;
	}
	myConstListIterator<T> operator--(int) {
		myConstListIterator _tmp = *this;
		node = node->_prev;
		return _tmp;
	}
};

#endif
