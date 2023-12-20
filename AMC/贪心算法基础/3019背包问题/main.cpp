#include <bits/stdc++.h>
using namespace std;
struct node {
	double wi, vi, si;
} p[10000];
bool cmp(node a, node b) {
	return a.si > b.si;
}

int main() {
	int m, n;
	cin >>m>>n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].wi;
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].vi;
		p[i].si = p[i].vi/p[i].wi;
	}
	sort(p,p+n,cmp);
	double sum = 0;
	for(int i=0;i<n;i++){
		if(m>=p[i].wi){
			m -= p[i].wi;
			sum += p[i].vi;
		}else{
			sum += m*p[i].si;
			break;
		}
		
	}
	printf("%.2lf\n",sum);

}
