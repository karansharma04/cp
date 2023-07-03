#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("./test_cases.txt", "w", stdout);
	cout<<1000<<endl;
	int N=10;
	for(int i=0;i<1000;i++) {
		cout<<N<<endl;
		for(int i=0;i<N;i++) {
			cout<<rand()%N+1<<' ';
		}
		cout<<endl;
		for(int i=0;i<N;i++) {
			cout<<rand()%N+1<<' ';
		}
		cout<<endl;
	}
	return 0;
}