#include<iostream>
#include<stack>
#include<string>
using namespace std;

string stackBin(int n) {
	stack<char> s;
	while (n > 0) {
		s.push(n % 2 + '0');
		n /= 2;
	}
	string res = "";
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	return res;
}

int main() {
	string res = stackBin(123);
	cout << res;
	return 0;
}