#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,sum,mid = 0xfffffff;
	while(cin>>n){
		 // �����ǰ�����������֮ǰ������� 
		if(mid<n){
			// �����ֵ���ӵ��ܺ���
			sum+=n-mid;
		}
		// ����midΪ��ǰ�������  
		mid = n;
		// 7 1 5 3 6 4
		// sum -> 7 - 0xfffffff = -0xffffff9
		// sum -> -0xffffff9 + 1 - 0xfffffff = 7
		// mid -> 5
		// mid -> 3
		// mid -> 6
		// mid -> 4
		// --> sum = 7
		
		
	}
	cout<<sum<<endl;
}
