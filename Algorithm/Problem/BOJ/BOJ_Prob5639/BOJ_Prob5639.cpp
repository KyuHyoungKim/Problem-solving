#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
class Node {
public:
	int data = 0;
	int pLeft = -1;
	int pRight = -1;
};
Node make_Node(int Data) {
	Node ret;
	ret.data = Data;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int temp;
	vector<Node> Nodes;
	scanf("%d", &temp);
	Nodes.push_back(make_Node(temp));
	while (scanf("%d", &temp) > 0) {
		int pnt = 0;
		Nodes.push_back(make_Node(temp));
		while (pnt >= 0) {
			if (temp < Nodes[pnt].data)
			{
				if (Nodes[pnt].pLeft < 0) break;
				pnt = Nodes[pnt].pLeft;
			}
			else
			{
				if (Nodes[pnt].pRight < 0) break;
				pnt = Nodes[pnt].pRight;
			}
		}
		if (Nodes[pnt].data > temp) Nodes[pnt].pLeft = Nodes.size() - 1;
		else Nodes[pnt].pRight = Nodes.size() - 1;
	}
	stack<int> st;
	vector<int> checked(Nodes.size());
	st.push(0);
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		if (Nodes[now].pLeft < 0 && Nodes[now].pRight < 0) {
			printf("%d\n", Nodes[now].data);
			checked[now]++;
		}
		else if ((Nodes[now].pLeft > 0 && checked[Nodes[now].pLeft]) || (Nodes[now].pRight > 0 && checked[Nodes[now].pRight])) {
		printf("%d\n", Nodes[now].data);
		checked[now]++;
		}
		else {
			st.push(now);
			if (Nodes[now].pRight > 0) st.push(Nodes[now].pRight);
			if (Nodes[now].pLeft > 0) st.push(Nodes[now].pLeft);
		}
	}

	return 0;
}