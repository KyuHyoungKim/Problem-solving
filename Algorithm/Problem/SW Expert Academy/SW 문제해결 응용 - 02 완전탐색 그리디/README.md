## 균형점

- #### 처음 풀이
    ###### 무게중심 구하듯이 좌측에 있는 점들의 자성 중심을 계산하고 우측에 있는 점들의 자성 중심을 계산하여 풀이
	###### 틀림, 이유는 힘에 대한 식이 거리에 대해 선형이 아니기 때문이라고 생각 중

- #### 나중 풀이
   ###### 이분탐색으로 풀이

- #### 처음 풀이 코드
```
double solution(vector<int> pos, vector<int> mass, int cnt)
{
	int Mass_Sum_1 = 0, Mass_Sum_2 = 0;
	double Pos_Mean_1 = 0, Pos_Mean_2 = 0;
	for (int i = 0; i < cnt; i++)
	{
		Mass_Sum_1 += mass[i];
		Pos_Mean_1 += static_cast<float>(mass[i] * pos[i]);
	}
	Pos_Mean_1 /= Mass_Sum_1;
	for (int i = cnt; i < pos.size(); i++)
	{
		Mass_Sum_2 += mass[i];
		Pos_Mean_2 += static_cast<float>(mass[i] * pos[i]);
	}
	Pos_Mean_2 /= Mass_Sum_2;
	return Pos_Mean_1 + (Pos_Mean_2 - Pos_Mean_1) / (sqrt((double)Mass_Sum_2 / Mass_Sum_1) + 1);
}
```


## 최대 상금
- #### 처음 풀이
    ###### Greedy로 접근
    ###### 큰 수를 앞으로 옮기는 방식으로 풀이
    ###### 가장 큰 수가 여러 자리에 있는 경우 그 중 뒤에 있는 것을 선택
    ###### 32888 2 의 경우 88832가 아닌 88823이 되어 실패
- #### 나중 풀이
    ###### 순열이 아닌 조합이라서 완전탐색으로 접근해봄
    ###### 숫자의 개수 -1개 만큼의 횟수면 어떤 경우에서든 가장 큰 수를 만들 수 있음
    ###### 그래서 숫자의 개수 -1보다 자리 교환 횟수가 큰 경우에 발생할 의미없는 교환을 미리 처리해 연산횟수 감소
