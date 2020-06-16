#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
using namespace std;
map<char, pair<char, char>> tree;

void pre(char node) {
	printf("%c", node);
	if (tree[node].first != '.') pre(tree[node].first);
	if (tree[node].second != '.') pre(tree[node].second);
}
void inorder(char node) {
	if (tree[node].first != '.') inorder(tree[node].first);
	printf("%c", node);
	if (tree[node].second != '.') inorder(tree[node].second);
}
void post(char node) {
	if (tree[node].first != '.') post(tree[node].first);
	if (tree[node].second != '.') post(tree[node].second);
	printf("%c", node);
}
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	char Pa, Lc, Rc;
	scanf("%d\n", &N);
	while (N--) {
		scanf("%c %c %c\n", &Pa, &Lc, &Rc);
		tree.insert(make_pair(Pa, make_pair(Lc, Rc)));
	}
	
	pre('A');
	printf("\n");
	inorder('A');
	printf("\n");
	post('A');
	printf("\n");
	return 0;
}