#include <bits/stdc++.h>
using namespace std;

int money[7] = {100, 50, 20, 10, 5, 2, 1};

int main() {
	int t, n;
	cin>>t;
	while (t--) {
		cin >> n;
		// 遍历所有的面值
		for (int i = 0; i < 7; i++) {
			// 当遇到可以找开的最大面值后直接找出，while用来去重，比如100块找2次50面值
			while(n>=money[i]){
				n-=money[i];
				cout<<money[i]<<" ";
			}
		}
		cout << endl;
	}
	
}
