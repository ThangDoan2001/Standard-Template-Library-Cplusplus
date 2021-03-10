#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int s_size = s.size();
	for (int i = 0; i < s_size; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
	}
	cout << s;
	return 0;
}