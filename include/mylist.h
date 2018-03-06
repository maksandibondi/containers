#ifndef _MYLIST_
#define _MYLIST_
#include "iterator-traits.h"
//-------------------------------------------------------------------
// Traits contain the definition of iterators/allocators when applied
// to different containers


// Node
template <typename T>
class mynode {
	friend my_list<T>;
	friend myListIterator<T>;
	mynode<T>* _prev;
	mynode<T>* _next;
	T _data;
	mynode() {}
	mynode(const T& data, mynode<T>* prev, mynode<T>* next):  _data(data), _prev(prev), _next(next) {
	}
	~mynode() {
		delete _prev;
		delete _next;
	}
};

// List
template <typename T>
class my_list {
	mynode<T>* root;
	size_t _size;
public:
	typedef myListIterator<T> iterator;
	typedef myConstListIterator<T> const_iterator;

	my_list() {
		root = new mynode<T>();
		root->_prev = root;
		root->_next = root;
	}

	~my_list() {
		delete root;
	}

	iterator begin() {
		return iterator(root->_next);
	}

	const_iterator cbegin() const {
		return const_iterator(root->next);
	}

	iterator end() {
		return iterator(root);
	}

	const_iterator cend() const {
		return const_iterator(root);
	}

	iterator insert(iterator position, const T& data) {
		_size++;
		mynode<T>* _tmp = new mynode<T>(data, position.node->_prev, position.node);
		position.node->_prev->_next = _tmp;
		position.node->_prev = _tmp;
		return _tmp;
	}

	iterator insert(iterator position) {
		_size++;
		return insert(position, T());
	}

	bool empty() {
		return (begin() == end());
	}

	void push_back(const T& el) {
		insert(end(), el);
	}

	size_t size() {
		return _size;
	}

};



#endif
