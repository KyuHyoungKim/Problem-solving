#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos_info {
	int y, x;
};
struct Person_info {
	Pos_info Person;
	Pos_info Dest;
};
struct BFS_Node {
	int y, x, dist;
};
struct comp {
	bool operator()(const Person_info& a, const Person_info& b) {
		if (a.Person.y != b.Person.y)
			return a.Person.y < b.Person.y;
		else
			return a.Person.x < b.Person.x;
	}
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	}
};

const int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };
int N, M, fuel;
Pos_info Taxi;
vector<vector<int>> Map;
vector<Person_info> Persons;
vector<int> dists;

BFS_Node make_node(int y, int x, int dist);
void init();
pair<int, int> BFS(int y, int x);
int BFS(Person_info p);

int main() {
	freopen("input.txt", "r", stdin);
	init();
	while (M) {
		pair<int, int> target;
		int distance;

		target = BFS(Taxi.y, Taxi.x);
		if (target.first == INF) {
			fuel = -1;
			break;
		}
		distance = BFS(Persons[target.first]);

		fuel -= (target.second + distance);
		if (fuel < 0)
			break;
		else {
			Taxi = Persons[target.first].Dest;
			Map[Persons[target.first].Person.y][Persons[target.first].Person.x] = 0;
			fuel += 2 * distance;
			M--;
		}
	}

	if (fuel < 0)
		fuel = -1;
	printf("%d", fuel);
	return 0;
}

BFS_Node make_node(int y, int x, int dist) {
	BFS_Node ret;
	ret.y = y;
	ret.x = x;
	ret.dist = dist;
	return ret;
}

void init() {
	scanf("%d %d %d", &N, &M, &fuel);
	Map.resize(N + 1, vector<int>(N + 1));
	Persons.resize(M + 1);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j])
				Map[i][j] *= -1;
		}
	scanf("%d %d", &Taxi.y, &Taxi.x);
	for (int i = 1; i <= M; i++)
		scanf("%d %d %d %d", &Persons[i].Person.y, &Persons[i].Person.x, &Persons[i].Dest.y, &Persons[i].Dest.x);
	sort(Persons.begin(), Persons.end(), comp());
	for (int i = 1; i <= M; i++)
		Map[Persons[i].Person.y][Persons[i].Person.x] = i;
}

pair<int, int> BFS(int y, int x) {
	queue<BFS_Node> q;
	vector<vector<bool>> visited(Map.size(), vector<bool>(Map.size(), false));
	vector<pair<int, int>> ret;
	q.push(make_node(y, x, 0));
	visited[y][x] = true;

	while (!q.empty()) {
		int Y = q.front().y;
		int X = q.front().x;
		int Dist = q.front().dist;
		q.pop();

		if (!ret.empty() && ret[0].second < Dist)
			break;

		if (Map[Y][X] > 0)
			ret.push_back(make_pair(Map[Y][X], Dist));

		for (int i = 0; i < 4; i++) {
			int Y_new = Y + dy[i];
			int X_new = X + dx[i];

			if (Y_new < 1 || Y_new > N || X_new < 1 || X_new > N) continue;
			if (Map[Y_new][X_new] < 0 || visited[Y_new][X_new]) continue;

			q.push(make_node(Y_new, X_new, Dist + 1));
			visited[Y_new][X_new] = true;
		}
	}
	sort(ret.begin(), ret.end(), comp());

	if (ret.empty())
		ret.push_back(make_pair(INF, INF));
	return ret.front();
}

int BFS(Person_info p) {
	queue<BFS_Node> q;
	vector<vector<bool>> visited(Map.size(), vector<bool>(Map.size(), false));
	q.push(make_node(p.Person.y, p.Person.x, 0));
	visited[p.Person.y][p.Person.x] = true;

	while (!q.empty()) {
		int Y = q.front().y;
		int X = q.front().x;
		int Dist = q.front().dist;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int Y_new = Y + dy[i];
			int X_new = X + dx[i];
			if (Y_new == p.Dest.y && X_new == p.Dest.x) {
				return Dist + 1;
				break;
			}
			if (Y_new < 1 || Y_new > N || X_new < 1 || X_new > N) continue;
			if (Map[Y_new][X_new] < 0 || visited[Y_new][X_new]) continue;
			
			q.push(make_node(Y_new, X_new, Dist + 1));
			visited[Y_new][X_new] = true;
		}
	}
	return INF;
}