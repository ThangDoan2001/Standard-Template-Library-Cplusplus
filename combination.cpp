#include<iostream>
#include<stdio.h>

using namespace std;

int binom(int n, int k) {
	if (k > n) return 0;
	if (k == 0)return 1;
	return binom(n - 1, k) + binom(n - 1, k - 1);
	// Cong thuc Pascal (k+1)C(n+1) = kCn + (k+1)Cn
}

int binom2(int n, int k) {
    int res = 1;
    int x = min(k, n - k);
    for (int i = 1; i <= x; i++) {
        // phep tinh nay bat dau o n va dung lai o k do do phan tu da la n!/ k!
        // amazing :)))
        res = res * n / i;
        n--;
    }
    return res;
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%dC%d = %d \n", k, n, binom(n, k));
        printf("---------------------------------\n");
    }
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%dC%d = %d \n", k, n, binom2(n, k));
        printf("---------------------------------\n");
    }
    return 0;
}