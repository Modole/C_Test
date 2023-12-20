#include <bits/stdc++.h>
using namespace std;

struct node {
	double mi, vi, si;
} p[100];

bool cmp(node a, node b) {
	return a.si > b.si;
}

int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> p[i].mi >> p[i].vi;
		p[i].si = p[i].vi / p[i].mi;
	}
	sort(p, p + n, cmp);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if (t >= p[i].mi) {
			t -= p[i].mi;
			sum += p[i].vi;
		} else {
			sum += p[i].si * t;
			break;
		}
	}
	printf("%.2f\n", sum);
}
