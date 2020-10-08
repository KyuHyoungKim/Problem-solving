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

// �̺�Ž������ ����
int main() {
	freopen("input.txt", "r", stdin);
	int N, atk_init;
	long long hp_max = 1; // �ּҰ� 1, �׸��� ��� ���� Potion���� ��츦 ����� 1�� �ʱ�ȭ
	long long left, right, mid;
	scanf("%d %d", &N, &atk_init);
	vector<room_info> rooms(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &rooms[i].type, &rooms[i].atk, &rooms[i].hp);
		if (rooms[i].type == MONSTER)
			hp_max += (long long)rooms[i].atk * (rooms[i].hp / atk_init);
		// atk�� �ʱⰪ���� �����Ǵ� ��� �޴� ���������� ��� ����(������ �ִ밪)
		// ��� 1�� ������ �͵� �ְ�, ���� ���� �� ������ �������� �ʴ� ��� 1�Ͼ� ���¾Ƽ� �ִ� �� ���� �� ŭ
		
		// �־��� ��� 10^6 * 10^6 * 123,456 = 1.23456 * 10^17  -> long long�� �ִ밪���� ũ���ѵ�..
		// max�� �̽��� long long���� Ǭ ����鵵 ���� Ʋ���� 2%�� �Ѿ�°� ���� �ϴ��� �Ѿ����ߴ�.
	}

	left = 1;
	right = hp_max;
	while (left <= right) {
		mid = (right + left) / 2; // mid : HP_max
		long long atk = atk_init;
		long long hp = mid;

		for (int i = 0; i < N; i++) {
			if (rooms[i].type == MONSTER) { // Monster��
				// ����� ü���� ������� �ʰ�, Monster�� ���� �� ������ �� �� ����ϰ�
				long long turn_cnt = rooms[i].hp / atk;
				if (rooms[i].hp % atk)
					turn_cnt++;
				// Monster�� ���� �� ���� �޴� �������� ����ؼ� hp���� ����
				//Monster�� �״� �Ͽ��� ���� �ʱ� ������ 1 ����
				hp -= rooms[i].atk * (turn_cnt - 1); 
				if (hp <= 0) // ��簡 �״� ���
					break;
			}
			else if (rooms[i].type == POTION) { // Potion��
				hp += rooms[i].hp; //ü�� ȸ��
				if (hp > mid) //�ִ� ü��(mid)�� �Ѿ ��� �ִ� ü������ ����
					hp = mid;
				atk += rooms[i].atk;
			}
		}

		if (hp <= 0)
			left = mid + 1; // ��簡 ���� ���
		else {
			right = mid - 1; // ��簡 �� ���(���� ���⼺��)
			hp_max = mid;
		}
	}
	
	printf("%lld", hp_max);
	return 0;
}