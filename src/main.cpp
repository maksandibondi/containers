#include "main.h"
#include <iostream>
#include <algorithm>
#include "myvector.h"
#include "iterator-traits.h"

int main(){
	//myvector<int> vec(3);
	myvector<int> vec(1);
	myvector<int>::iterator it = vec.begin();
	myvector<int>::iterator it1 = vec.end();
	//vec[0] = 1;
	//vec[1] = 2;
	//vec[2] = 3;
	vec[0] = 3;
	//vec.push_back(2);
	std::cout << "hello" << vec[0] << std::endl;
	return 0;
}
