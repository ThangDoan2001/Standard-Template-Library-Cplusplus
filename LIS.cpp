#include<iostream>
using namespace std;
int a[1000], n;
int memSet[1000];

int lis(int a[], int n) {
	int max = 1;
	for (int i = 0; i < n; ++i) {
		memSet[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && memSet[i] < memSet[j] + 1) {
				memSet[i] = memSet[j] + 1;
			}
		}
		if (memSet[i] > max) {
			max = memSet[i];
		}
	}
	return max;
}

void trace(int i, int a[]) {
	for (int j = 0; j < i; ++j) {
		if (a[j] < a[i] && memSet[j] == memSet[i] - 1) {
			trace(j, a);
			break;
		}
	}
	cout << a[i] << " ";
}

int main() {
	int a[] = { 2, 1, 5, 4, 3, 6 };
	int max = lis(a, 6);
	cout << max << endl;
	int index = 0;
	for (int i = 0; i < 6; ++i) {
		if (memSet[i] == max) {
			index = i;
		}
	}
	trace(index,a);
	return 0;
}