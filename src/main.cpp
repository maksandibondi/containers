#include "main.h"
#include <iostream>
#include <algorithm>
#include "myvector.h"
#include "iterator-traits.h"
#include <string>

int main(){
	// myvector test
		myvector<int> vec(1);
		vec[0] = 1;
		myvector<int>::iterator it;
		//it = vec.begin();
		//it = vec.end();
		vec.push_back(2);
		int inc = 1;
		for (auto itt = vec.begin(); itt != vec.end(); itt++) {
			*itt = inc;
			inc++;
		}

		int firstt = vec[0];
		int secc = vec[1];



		// reverse amd const iterators conversion
		std::reverse_iterator<myvector<int>::iterator> myreverseitback(vec.begin());
		std::reverse_iterator<myvector<int>::iterator> myreverseitfront(vec.end());
		inc = 1;
		for (myreverseitfront; myreverseitfront != myreverseitback; myreverseitfront++) {
			*myreverseitfront = inc;
			inc++;
		}

		firstt = vec[0];
		secc = vec[1];

		// add more operators to iterator <, > etc
		std::sort(vec.begin(), vec.end());

		firstt = vec[0];
		secc = vec[1];

		std::string a;
		std::getline(std::cin,a);
}
