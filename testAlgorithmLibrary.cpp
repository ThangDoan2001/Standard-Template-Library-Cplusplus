#include <iostream>     // std::cout
#include <algorithm>   
#include <vector>    
#include <set>// std::vector

void myfunction(int i) {  // function:
	std::cout << ' ' << i;
}	

struct myclass {           // function object type:
	void operator() (int i) { std::cout << ' ' << i; }
} myobject;

bool myfunction2(int i, int j) { return (i < j); }

bool myfunction3(int i, int j) { return (i > j); }

int main() {
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(30);
	myvector.push_back(20);

	std::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);


	// for each
	std::cout << "myset contains:";
	for_each(s.begin(), s.end(), myfunction);
	std::cout << '\n';

	// sort
	sort(myvector.begin(), myvector.end(), myfunction2);
	std::cout << "myset contains:";
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << ' ' << *it;
	}
	std::cout << "\n";

	// lower_bound and upper bound
	std::vector<int>::iterator low, up;
	low = std::lower_bound(myvector.begin(), myvector.end(), 20);
	up = std::upper_bound(myvector.begin(), myvector.end(), 20);

	std::cout << "lower_bound at position " << (low - myvector.begin()) << '\n';
	std::cout << "upper_bound at position " << (up - myvector.begin()) << '\n';

	// or:
	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myobject);
	std::cout << '\n';

	// binary search
	std::cout << "looking for a 30... ";
	if (std::binary_search(myvector.begin(), myvector.end(), 30))
		std::cout << "found!\n"; else std::cout << "not found.\n";


	// min_element and max_element
	std::cout << "The smallest element is " << *std::min_element(myvector.begin(), myvector.end()) << '\n';
	std::cout << "The largest element is " << *std::max_element(myvector.begin(), myvector.end()) << '\n';

	int myints[] = { 1,2,3 };

	// next_permutation and prev_permutation with reverse - de sinh hoan vi

	std::sort(myints, myints + 3); // first must be lowest

	std::cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (std::next_permutation(myints, myints + 3));

	std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

	std::reverse(myints, myints + 3);

	std::cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (std::prev_permutation(myints, myints + 3));

	return 0;
}
