#define INF 123456789

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> enemies;
vector<vector<int>> DP;
int N, W;
// state
// 0 : 둘 다 차있는 것
// 1 : 위에가 차있는 것 (outer가 차있는 것)
// 2 : 아래가 차있는 것 (inner가 차있는 것)

int solution(int idx, int state);
bool check_enemies(int idx1, int circle1, int idx2, int circle2);

int main(){
	freopen("input.txt","r",stdin);

	int T;
	scanf("%d", &T);

	while(T--){
		int res;
		scanf("%d %d", &N, &W);
		enemies = vector<vector<int>>(N,vector<int>(2));
		for(int n = 0 ; n < 2; n++)
			for(int i = 0 ; i < N; i++)
				scanf("%d", &enemies[i][n]);
		
		bool st_end_inner = check_enemies(0, 0, N - 1, 0);
		bool st_end_outer = check_enemies(0, 1, N - 1, 1);

		DP = vector<vector<int>>(N,vector<int>(3));	
		res = solution(N-1,0);
		if(N > 2){
			if(st_end_inner){
				int temp = enemies[0][0];
				DP = vector<vector<int>>(N,vector<int>(3));	
				enemies[0][0] = INF;
				res = min(res, solution(N - 1, 2));
				enemies[0][0] = temp;
			}
			if(st_end_outer){
				int temp = enemies[0][1];
				DP = vector<vector<int>>(N,vector<int>(3));	
				enemies[0][1] = INF;
				res = min(res, solution(N - 1, 1));
				enemies[0][1] = temp;
			}
			if(st_end_outer && st_end_inner){
				DP = vector<vector<int>>(N,vector<int>(3));	
				DP[0][0] = 2;
				enemies[0][0] = enemies[0][1] = INF;
				res = min(res, solution(N - 2, 0));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

int solution(int idx, int state){
	if(idx < 0)
		return 0;
	if(DP[idx][state])
		return DP[idx][state];

	int ret = 0;
	bool inner = check_enemies(idx, 0, idx - 1, 0);
	bool outer = check_enemies(idx, 1, idx - 1, 1);
	bool both = check_enemies(idx, 0, idx, 1);

	if(state == 0){
		ret = min(solution(idx,1), solution(idx,2)) + 1;
		if(both)
			ret = min(ret, solution(idx - 1, 0) + 1);
		if(inner && outer)
			ret = min(ret, solution(idx - 2, 0) + 2);
	}
	else if(state == 1){
		ret = solution(idx - 1, 0) + 1;
		if(inner)
			ret = min(ret, solution(idx - 1, 2) + 1);
	}
	else if(state == 2){
		ret = solution(idx - 1,0) + 1;
		if(outer)
			ret = min(ret, solution(idx - 1, 1) + 1);
	}

	DP[idx][state] = ret;
	return ret;
}

bool check_enemies(int idx1, int circle1, int idx2, int circle2){
	bool ret = false;
	if(idx1 < 0 || idx2 < 0)
		return ret;
	if(enemies[idx1][circle1] + enemies[idx2][circle2] <= W)
		ret = true;

	return ret;
}


