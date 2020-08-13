#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
vector<pair<ll, ll>> points;

double sol(vector<pair<ll, ll>> vectors, int checked, int count);
pair<ll, ll> pair_sum(const pair<ll, ll>& a, const pair<ll, ll>& b);
double find_vector_sum(vector<pair<ll, ll>>& vectors, int cnt, pair<ll, ll> sum);

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		double res;
		vector<pair<ll, ll>> points_init(N);
		points.swap(points_init);

		for (int i = 0; i < N; i++)
			scanf("%lld %lld", &points[i].first, &points[i].second);
		res = sol({}, 0, 0);
		printf("%lf\n", res);
	}
	return 0;
}

pair<ll, ll> pair_sum(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	pair<ll, ll> ret = a;
	ret.first += b.first;
	ret.second += b.second;
	return ret;
}

double sol(vector<pair<ll, ll>> vectors, int checked, int count) {
	int cnt = 0, idx = -1;
	double ret = INF, a;
	if (count >= N / 2) {
		ret = find_vector_sum(vectors, 0, { 0,0 });
		return ret;
	}

	for (int i = 0; i < N; i++) {
		if (checked & 1 << i) continue;

		if (idx < 0)
			idx = i;
		else {
			vectors.push_back(make_pair(idx, i));
			a = sol(vectors, checked | 1 << idx | 1 << i, count + 1);
			vectors.pop_back();
			if (a < ret)
				ret = a;
		}
	}
	return ret;
}

double find_vector_sum(vector<pair<ll, ll>>& vectors, int cnt, pair<ll, ll> sum) {
	if (cnt >= N / 2)
		return sqrt(pow(sum.first,2) + pow(sum.second,2));

	double ret, a1, a2;
	pair<ll, ll> pnt1, pnt2;
	pair<ll, ll> vec;

	pnt1 = points[vectors[cnt].first];
	pnt2 = points[vectors[cnt].second];

	vec.first = pnt1.first - pnt2.first;
	vec.second = pnt1.second - pnt2.second;
	a1 = find_vector_sum(vectors, cnt + 1, pair_sum(sum, vec));

	vec.first *= -1;
	vec.second *= -1;
	a2 = find_vector_sum(vectors, cnt + 1, pair_sum(sum, vec));
	ret = a1 < a2 ? a1 : a2;
	return ret;
}