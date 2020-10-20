#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
struct comp {
	bool comp_in_x;
	comp(bool b) {
		comp_in_x = b;
	}
	bool operator()(const Point& a, const Point& b) {
		return comp_in_x ? a.x < b.x : a.y < b.y;
	}
};

inline int dist(Point& a, Point& b);
int find_min_dist(int left, int right);

const bool COMP_X = true, COMP_Y = false;
vector<Point> points;

int main() {
	freopen("input.txt", "r", stdin);

	int N, res;
	scanf("%d", &N);

	points = vector<Point>(N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &points[i].x, &points[i].y);
	sort(points.begin(), points.end(), comp(COMP_X));

	res = find_min_dist(0, N - 1);
	printf("%d", res);
	return 0;
}


inline int dist(Point& a, Point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int find_min_dist(int left, int right) {
	int mid = (left + right) / 2;
	int ret;
	if (right - left == 1)
		return dist(points[left], points[right]);
	if (right - left == 2)
		return min({ dist(points[left], points[mid]), dist(points[mid], points[right]), dist(points[right], points[left]) });

	ret = min(find_min_dist(left, mid), find_min_dist(mid + 1, right));

	vector<Point> mid_points;
	int mid_size;
	mid_points.reserve(right - left);
	for (int i = mid; i >= left; i--) {
		int distance = points[i].x - points[mid + 1].x;
		if (distance * distance >= ret)
			break;
		mid_points.push_back(points[i]);
	}
	for (int i = mid + 1; i <= right; i++) {
		int distance = points[i].x - points[mid].x;;
		if (distance * distance >= ret)
			break;
		mid_points.push_back(points[i]);
	}

	mid_size = mid_points.size();
	sort(mid_points.begin(), mid_points.end(), comp(COMP_Y));

	for (int i = 0; i < mid_size - 1; i++)
		for (int j = i + 1; j < mid_size; j++) {
			if ((mid_points[j].y - mid_points[i].y) * (mid_points[j].y - mid_points[i].y) >= ret)
				break;
			ret = min(ret, dist(mid_points[i], mid_points[j]));
		}

	return ret;
}