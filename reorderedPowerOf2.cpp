#include<iostream>
using namespace std;

// C++ khong ung ho viec tra ve dia chi cua bien cuc bo toi ben ngoai ham, vi the neu muon truyen ra ngoai phai dinh nghia mot bien nhu static
/*int* count(int N) {
	static int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (N > 0) {
		arr[N % 10]++;
		N /= 10;
	}
	return arr;
}*/

bool equals(int arr[], int arr2[]) {
	for (int i = 0; i <= 9; ++i) {
		if (arr[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

/*bool reorderedPowerOf2(int N) {
	int* countN;
	countN = count(N);
	for (int i = 0; i < 31; ++i) {
		if (equals(countN, count(1 << i))) {
			return true;
		}
	}
	return false;
}*/

bool reorderedPowerOf2(int N) {
	int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	while (N > 0) {
		arr[N % 10] ++;
		N /= 10;
	}
	int num = 0;
	for (int i = 0; i < 31; ++i) {
		int num = 1 << i;
		int arr2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		while (num > 0) {
			arr2[num % 10] ++;
			num /= 10;
		}
		if (equals(arr, arr2)) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << reorderedPowerOf2(10) << endl;
	cout << reorderedPowerOf2(16) << endl;
	cout << reorderedPowerOf2(812) << endl;
	cout << reorderedPowerOf2(1052) << endl;
	cout << reorderedPowerOf2(4102) << endl;
	return 0;
}