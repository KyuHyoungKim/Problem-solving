#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> Datas;
vector<pair<int,int>> pnts;
void postorder(int now) {
	if (pnts[now].first > 0) postorder(pnts[now].first);
	if (pnts[now].second > 0) postorder(pnts[now].second);
	printf("%d\n", Datas[now]);
}
int main() {
	freopen("input.txt", "r", stdin);
	int temp;
	scanf("%d", &temp);
	Datas.push_back(temp);
	pnts.push_back(make_pair(-1, -1));
	while (scanf("%d", &temp) > 0) {
		int pnt = 0, pnt_next = 0;
		Datas.push_back(temp);
		pnts.push_back(make_pair(-1, -1));
		while (pnt_next >= 0) {
			pnt = pnt_next;
			if (temp < Datas[pnt])
			{
				pnt_next = pnts[pnt].first;
				if (pnt_next < 0) pnts[pnt].first = Datas.size() - 1;
			}
			else
			{
				pnt_next = pnts[pnt].second;
				if (pnt_next < 0) pnts[pnt].second = Datas.size() - 1;
			}
		}
	}
	postorder(0);
	return 0;
}