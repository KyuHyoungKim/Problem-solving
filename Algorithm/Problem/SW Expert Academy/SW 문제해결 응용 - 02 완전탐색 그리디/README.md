#### 처음 풀이
  - ###### 무게중심 구하듯이 좌측에 있는 점들의 자성 중심을 계산하고 우측에 있는 점들의 자성 중심을 계산하여 풀이
    ###### 틀림, 이유는 힘에 대한 식이 거리에 대해 선형이 아니기 때문이라고 생각 중
    
#### 나중 풀이
  - ###### 이분탐색으로 풀이

#### 처음 풀이 코드
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

