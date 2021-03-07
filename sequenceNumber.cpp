#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<long long> sequenceNumber(long long l, long long r){
	vector<long long> res;
	queue<long long> q;
	long long k;
	//make a init sequence number array include {1,2,...r} pr {1,2,...,9}
	for(int i = 1; i <= r, i <= 9; ++i){
		q.push(i);
	}
	while(!q.empty()){
		// add a new sequenceNumber
		k = q.front()*10 + q.front()%10 + 1;
		// add 123 before 12 and ignore 890 before 89....
		if(k <= r && q.front() % 10 != 9) q.push(k);
		if(q.front() >= l){
			res.push_back(q.front());
			q.pop();
		}
		else q.pop();
	}
	return res;
}

int main(){
	vector<long long> res = sequenceNumber(100,300);
	for(int i = 0; i < res.size(); ++i){
		cout << res[i] << " ";
	}
	return 0;
}
