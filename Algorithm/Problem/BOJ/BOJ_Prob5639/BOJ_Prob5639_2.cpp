#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
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
vector<Node> Nodes;
void postorder(int now) {
	if (Nodes[now].pLeft > 0) postorder(Nodes[now].pLeft);
	if (Nodes[now].pRight > 0) postorder(Nodes[now].pRight);
	printf("%d\n", Nodes[now]);
}
int main() {
	freopen("input.txt", "r", stdin);
	int temp;
	scanf("%d", &temp);
	Nodes.push_back(make_Node(temp));
	while (scanf("%d", &temp) > 0) {
		int pnt = 0, pnt_next = 0;
		Nodes.push_back(make_Node(temp));
		while (pnt_next >= 0) {
			pnt = pnt_next;
			if (temp < Nodes[pnt].data)
			{
				pnt_next = Nodes[pnt].pLeft;
				if (pnt_next < 0) Nodes[pnt].pLeft = Nodes.size() - 1;
			}
			else
			{
				pnt_next = Nodes[pnt].pRight;
				if (pnt_next < 0) Nodes[pnt].pRight = Nodes.size() - 1;
			}
		}
	}
	postorder(0);
	return 0;
}