#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891 //�־��� ��� ����� �ִ� ���� 2000 * 1000 < 1234567891
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class edge_info {
public:
	int node, dist;
	bool check; 
	//heap�� �������߸� �ϴ� edge���� Ȥ�� �� edge�� ������ �� ������� Ȯ���ϴ� boolean ���� check
};

class comp { // heap�� comparator
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

// ���ͽ�Ʈ��� Ǯ��
int main() {
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	while (T--) {
		// ���� ����
		int N, M, K; // N : node ����, M : ��������, K : ������ �ĺ� ����
		int start, visited_node_1, visited_node_2; // ������, ���ľ߸� �ϴ� ������ ����
		vector<bool> res; // �ִܰŸ��� ���� ��, ��ó���ϴ� ������ ���ƴ��� ����
		vector<vector<edge_info>> graph;
		vector<int> Destination;// ������ �ĺ���
		vector<int> Distance;	// ���ͽ�Ʈ�󿡼� �� ��庰 �ִܰŸ� �����ϱ� ���� vector
		priority_queue<edge_info, vector<edge_info>, comp> pq;
		
		// �Է� �� �ʱ�ȭ�κ� 
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
				check = true; // ���������ϴ� ����� ���
			graph[node1].push_back(make_edge(node2, dist, check));
			graph[node2].push_back(make_edge(node1, dist, check));
			// edge_info : 12bite (sizeof�����ڷ� Ȯ��)
			// �־��� ��� 50000 * 12bite = 600000bite ~ 600KB
		}

		for (int i = 0; i < K; i++)
			scanf("%d", &Destination[i]);
		sort(Destination.begin(), Destination.end()); // ������ ��� ������ �������� ����� ���� ����


		// ���ͽ�Ʈ�� �˰���
		pq.push(make_edge(start, 0, false));
		Distance[start] = 0;
		while (!pq.empty()) {
			int node_curr = pq.top().node;
			int dist_curr = pq.top().dist;
			bool check_curr = pq.top().check || res[node_curr];
			pq.pop();

			if (Distance[node_curr] < dist_curr) // �ִܰ�ΰ� �ƴ� �� ó��
				continue;
			for (int i = 0; i < graph[node_curr].size(); i++) {
				int node_next = graph[node_curr][i].node;
				int dist_next = graph[node_curr][i].dist + dist_curr;
				bool check_next = graph[node_curr][i].check || check_curr;

				// �� �ݺ��� �ȿ��� ���� �����ִ� edge�� �ִܰ���� ��쿡�� heap�� push�ϰ�
				// Distance �� res ����

				// �ִܰ�ΰ� �������� ��쿡�� ���� �ĺ������� ����

				if (Distance[node_next] > dist_next) { // �ִܰ���� ���
					pq.push(make_edge(node_next, dist_next, check_next));
					Distance[node_next] = dist_next;
					res[node_next] = check_next;
				}
				else if (Distance[node_next] == dist_next) // �ִܰ�ΰ� �������� �� 
					res[node_next] = res[node_next] || check_next;
			}
		}


		// ���
		for (int i = 0; i < K; i++)
			if (res[Destination[i]])
				printf("%d ", Destination[i]);
		printf("\n");
	}
	return 0;
}