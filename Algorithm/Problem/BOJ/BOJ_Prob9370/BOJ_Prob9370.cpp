#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891 //최악의 경우 경로의 최대 길이 2000 * 1000 < 1234567891
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class edge_info {
public:
	int node, dist;
	bool check; 
	//heap에 지나가야만 하는 edge인지 혹은 그 edge를 지나서 온 경로인지 확인하는 boolean 변수 check
};

class comp { // heap의 comparator
public:
	bool operator()(const edge_info& a, const edge_info& b) {
		return a.dist > b.dist;
	}
};

edge_info make_edge(int node, int dist, bool check) {
	edge_info ret;
	ret.node = node;
	ret.dist = dist;
	ret.check = check;
	return ret;
}

// 다익스트라로 풀이
int main() {
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	while (T--) {
		// 변수 선언
		int N, M, K; // N : node 개수, M : 간선개수, K : 목적지 후보 개수
		int start, visited_node_1, visited_node_2; // 시작점, 거쳐야만 하는 간선의 노드들
		vector<bool> res; // 최단거리로 갔을 때, 거처야하는 간선을 거쳤는지 여부
		vector<vector<edge_info>> graph;
		vector<int> Destination;// 목적지 후보들
		vector<int> Distance;	// 다익스트라에서 각 노드별 최단거리 저장하기 위한 vector
		priority_queue<edge_info, vector<edge_info>, comp> pq;
		
		// 입력 및 초기화부분 
		scanf("%d %d %d", &N, &M, &K);
		scanf("%d %d %d", &start, &visited_node_1, &visited_node_2);

		graph = vector<vector<edge_info>>(N + 1);
		Destination = vector<int>(K);
		Distance = vector<int>(N + 1, INF);
		res = vector<bool>(N + 1, false);

		for (int i = 0; i < M; i++) {
			int node1, node2, dist;
			bool check = false;
			scanf("%d %d %d", &node1, &node2, &dist);
			if ((node1 == visited_node_1 && node2 == visited_node_2) || (node1 == visited_node_2 && node2 == visited_node_1))
				check = true; // 지나가야하는 경로인 경우
			graph[node1].push_back(make_edge(node2, dist, check));
			graph[node2].push_back(make_edge(node1, dist, check));
			// edge_info : 12bite (sizeof연산자로 확인)
			// 최악의 경우 50000 * 12bite = 600000bite ~ 600KB
		}

		for (int i = 0; i < K; i++)
			scanf("%d", &Destination[i]);
		sort(Destination.begin(), Destination.end()); // 문제의 출력 조건인 오름차순 출력을 위해 정렬


		// 다익스트라 알고리즘
		pq.push(make_edge(start, 0, false));
		Distance[start] = 0;
		while (!pq.empty()) {
			int node_curr = pq.top().node;
			int dist_curr = pq.top().dist;
			bool check_curr = pq.top().check || res[node_curr];
			pq.pop();

			if (Distance[node_curr] < dist_curr) // 최단경로가 아닌 것 처리
				continue;
			for (int i = 0; i < graph[node_curr].size(); i++) {
				int node_next = graph[node_curr][i].node;
				int dist_next = graph[node_curr][i].dist + dist_curr;
				bool check_next = graph[node_curr][i].check || check_curr;

				// 이 반복문 안에서 지금 보고있는 edge가 최단경로인 경우에만 heap에 push하고
				// Distance 및 res 갱신

				// 최단경로가 여러개인 경우에는 정답 후보인지만 갱신

				if (Distance[node_next] > dist_next) { // 최단경로인 경우
					pq.push(make_edge(node_next, dist_next, check_next));
					Distance[node_next] = dist_next;
					res[node_next] = check_next;
				}
				else if (Distance[node_next] == dist_next) // 최단경로가 여러개일 때 
					res[node_next] = res[node_next] || check_next;
			}
		}


		// 출력
		for (int i = 0; i < K; i++)
			if (res[Destination[i]])
				printf("%d ", Destination[i]);
		printf("\n");
	}
	return 0;
}