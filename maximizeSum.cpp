#include<iostream>
#include<vector>
#include<algorithm> // sort
using namespace std;

//|arr[0] - arr[1]| + |arr[1] - arr[2]| + ... + |arr[n] - arr[0]| doi vi tri cac phan tu sao cho tong nay la lon nhat

int maximizeSum(vector<int> a) {
	sort(a.begin(), a.end()); //	sort(a.begin(), a.end(), greater<int>()); neu muon sap xep theo chieu giam dan
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < a.size() / 2; ++i) {
		sum1 += a[i];
		sum2 += a[a.size() / 2 + i];
	}
	int res = 2 * (sum2 - sum1);
	return res;
}

int main() {
	int arr[] = { 4, 19, 14, 9, 7, 3, 6, 15, 13, 14 };
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(arr[i]);
	}
	cout << maximizeSum(v);
	return 0;
}