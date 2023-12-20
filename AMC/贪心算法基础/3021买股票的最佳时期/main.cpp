#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,sum,mid = 0xfffffff;
	while(cin>>n){
		 // 如果当前输入的数大于之前输入的数 
		if(mid<n){
			// 计算差值并加到总和上
			sum+=n-mid;
		}
		// 更新mid为当前输入的数  
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
