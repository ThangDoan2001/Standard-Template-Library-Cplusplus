#include<iostream>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string s) {
	int begin = 0;
	int end = 0;
	int res = 0;
	

	unordered_set<char> set;
	while (end < s.length()) {
		if (set.count(s[end]) == 0) {
			set.insert(s[end]);
			end++;
			res = (res > set.size()) ? res : set.size();
		}
		else {
			set.erase(s[begin]);
			begin++;
		}
	}
	return res;
}

int main() {
	string s = "abcdededabccc";
	cout << longestSubstringWithoutRepeatingCharacters(s);
	return 0;
}
