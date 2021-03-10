#include<iostream>
using namespace std;

bool checkSpecialNumber(long long n){
	if (n > 9876543210) return false;
	int s[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	while (n > 0) {
		if (++s[n % 10] == 2) return false;
		n = n / 10;
	}
	return true;
}

int main() {
	cout << checkSpecialNumber(14699820);
	cout << checkSpecialNumber(1234567890);
	return 0;
}