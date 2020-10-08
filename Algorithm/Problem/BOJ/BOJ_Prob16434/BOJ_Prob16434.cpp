#define _CRT_SECURE_NO_WARNINGS
#define MONSTER 1
#define POTION 2
#include <cstdio>
#include <vector>
using namespace std;

class room_info {
public:
	int type, atk, hp;
};

// 이분탐색으로 접근
int main() {
	freopen("input.txt", "r", stdin);
	int N, atk_init;
	long long hp_max = 1; // 최소가 1, 그리고 모든 방이 Potion방일 경우를 대비해 1로 초기화
	long long left, right, mid;
	scanf("%d %d", &N, &atk_init);
	vector<room_info> rooms(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &rooms[i].type, &rooms[i].atk, &rooms[i].hp);
		if (rooms[i].type == MONSTER)
			hp_max += (long long)rooms[i].atk * (rooms[i].hp / atk_init);
		// atk가 초기값으로 유지되는 경우 받는 데미지량을 모두 더함(가능한 최대값)
		// 사실 1이 더해진 것도 있고, 나눈 것이 딱 나누어 떨어지지 않는 경우 1턴씩 덜맞아서 최대 값 보다 더 큼
		
		// 최악의 경우 10^6 * 10^6 * 123,456 = 1.23456 * 10^17  -> long long형 최대값보다 크긴한데..
		// max값 이슈는 long long으로 푼 사람들도 내가 틀리는 2%를 넘어가는걸 봐서 일단은 넘어가기로했다.
	}

	left = 1;
	right = hp_max;
	while (left <= right) {
		mid = (right + left) / 2; // mid : HP_max
		long long atk = atk_init;
		long long hp = mid;

		for (int i = 0; i < N; i++) {
			if (rooms[i].type == MONSTER) { // Monster방
				// 용사의 체력을 고려하지 않고, Monster가 죽을 때 까지의 턴 수 계산하고
				long long turn_cnt = rooms[i].hp / atk;
				if (rooms[i].hp % atk)
					turn_cnt++;
				// Monster가 죽을 때 까지 받는 데미지량 계산해서 hp에서 빼줌
				//Monster가 죽는 턴에는 맞지 않기 때문에 1 빼줌
				hp -= rooms[i].atk * (turn_cnt - 1); 
				if (hp <= 0) // 용사가 죽는 경우
					break;
			}
			else if (rooms[i].type == POTION) { // Potion방
				hp += rooms[i].hp; //체력 회복
				if (hp > mid) //최대 체력(mid)을 넘어간 경우 최대 체력으로 맞춤
					hp = mid;
				atk += rooms[i].atk;
			}
		}

		if (hp <= 0)
			left = mid + 1; // 용사가 죽은 경우
		else {
			right = mid - 1; // 용사가 산 경우(공주 구출성공)
			hp_max = mid;
		}
	}
	
	printf("%lld", hp_max);
	return 0;
}