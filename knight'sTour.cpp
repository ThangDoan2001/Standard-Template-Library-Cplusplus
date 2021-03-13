#include<iostream>
using namespace std;

int n;
int X[100], Y[100]; //luu toa do  cac buoc di chuyen cua quan ma
int mark[100][100]; // danh dau vi tri ma quan ma da di chuyen qua

// mang mo ta 8 vi tri ma quan ma co the di chuyen o vi tri hien tai
const int hX[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int hY[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

void print_sol() {
	for (int j = 1; j <= n * n; ++j) {
		cout << "(" << X[j] << " " << Y[j] << ")\n";
	}
	exit(0);
}

void TRY(int k) {
    for (int i = 0; i < 8; i++) {
        int xx = X[k - 1] + hX[i];
        int yy = Y[k - 1] + hY[i];
        if (xx > 0 && xx <= n && yy > 0 && yy <= n && mark[xx][yy] == 0) {
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;
            TRY(k + 1);
            mark[xx][yy] = 0;
        }
    }
}

int main() {
    cin >> n;
    mark[1][1] = 1;
    X[1] = 1;
    Y[1] = 1;
    TRY(2);
    print_sol();
    return 0;
}
