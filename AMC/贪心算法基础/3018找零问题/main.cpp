#include <bits/stdc++.h>
using namespace std;

int money[7] = {100, 50, 20, 10, 5, 2, 1};

int main() {
	int t, n;
	cin>>t;
	while (t--) {
		cin >> n;
		// �������е���ֵ
		for (int i = 0; i < 7; i++) {
			// �����������ҿ��������ֵ��ֱ���ҳ���while����ȥ�أ�����100����2��50��ֵ
			while(n>=money[i]){
				n-=money[i];
				cout<<money[i]<<" ";
			}
		}
		cout << endl;
	}
	
}
