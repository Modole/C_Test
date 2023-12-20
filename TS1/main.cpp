#include <bits/stdc++.h>
using namespace std;
struct node {
	// 数量，价值，性价比
	double w, v, s;
} p[10000];
bool cmp(node a, node b) {
	return a.s > b.s;
}
int main() {
	int k, t, s;
	cin >> k;
	while (k--) {
		double sum = 0;
		cin >> t >> s;
		for (int i = 0; i < s; i++) {
			cin >> p[i].w >> p[i].v;
			p[i].s = p[i].v / p[i].w;
		}
		sort(p, p + s, cmp);
		for (int i = 0 ; i < s; i++) {
			// 比较剩余数量和需能够拿的数量
			if (t >= p[i].w) {
				// 如果能装完，就将这个物品全装了
				sum += p[i].v;
				// 获取剩余的容量
				t -= p[i].w;
			} else {
				// 如果拿不完,就将能拿完的装起来
				sum += p[i].s * t;
				break;
			}
		}
		printf("%.2lf\n", sum);

	}
}
