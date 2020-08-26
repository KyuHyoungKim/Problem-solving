#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int gca(int a, int b) {
	return (b) ? gca(b, a % b) : a;
}
int main() {
	int N, ring;
	scanf("%d %d", &N, &ring);
	while (--N) {
		int ring__, mod;
		scanf("%d", &ring__);
		mod = gca(ring, ring__);
		printf("%d/%d\n", ring / mod, ring__ / mod);
	}
	return 0;
}