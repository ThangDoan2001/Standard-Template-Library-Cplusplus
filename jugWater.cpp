// cho 2 binh nuoc chua x, y l nuoc, tinh so buoc nho nhat de co the tao ra z lit nuoc tu 2 binh chi tu 2 thao tac do het, do day
#include<iostream>
using namespace std;

int process(int x, int y, int z) {
	int count = 0, a = 0, b = 0;
	
	while (a != z && b != z && (a + b) != z) {
		if (a == 0) {
			count ++;
			a = x;
		}
		else if (b == y) {
			count ++;
			b = 0;
		}
		else{
			count ++;
			int c = b + a;
			b = c > y ? y : c;
			a = c - b;
		}
	}
	return count;
}

int jugWater(int x, int y, int z) {
	if (x == z || y == z) return 1;
	if (z == 0) return 0;
	if (x == 0 || y == 0 || x == y) return -1;
	if (x % 5 == 0 && y % 5 == 0 && z % 5 != 0) return -1;
	if (x % 2 == 0 && y % 2 == 0 && x % 2 != 0) return -1;
	int a = process(x, y, z);
	int b = process(y, x, z);
	return a > b ? b : a;
}

int main() {
	int res = process(8, 7, 3);
	cout << res;
	return 0;
}