#include <bits/stdc++.h>
using namespace std;
struct node {
	// ��������ֵ���Լ۱�
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
			// �Ƚ�ʣ�����������ܹ��õ�����
			if (t >= p[i].w) {
				// �����װ�꣬�ͽ������Ʒȫװ��
				sum += p[i].v;
				// ��ȡʣ�������
				t -= p[i].w;
			} else {
				// ����ò���,�ͽ��������װ����
				sum += p[i].s * t;
				break;
			}
		}
		printf("%.2lf\n", sum);

	}
}
