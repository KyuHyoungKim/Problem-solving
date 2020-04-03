#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> laptop_temp;

int attatch(vector<vector<int>> Sticker, vector<vector<int>>* laptop, int i, int j);

int main()
{
	int N = 0, M = 0, K = 0;
	int X = 0, Y = 0;
	int temp = 0, result = 0;
	scanf_s("%d %d %d", &N, &M, &K);
	vector<vector<int>> laptop(N, vector<int>(M));

	for (int trial = 0; trial < K; trial++)
	{
		scanf_s("%d %d", &Y, &X);
		vector<vector<int>> Sticker(Y, vector<int>(X));
		// sticker shape input
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
				cin >> Sticker[i][j];
		int i = 0, j = 0;
		// find stikcer's position
		for (int n = 0; n < 4; n++)
		{
				for (i = 0; i < N; i++)
				{
					if (Y + i > N)
						break;
					for (j = 0; j < M; j++)
					{
						if (X + j > M)
							break;
						else
						{
							temp = attatch(Sticker, &laptop, i, j);	// Check and attatch
							if (temp)
							{
								result += temp;
								goto Exit;
							}
						}
					}
				}
			//rotate;
			vector<vector<int>> temp_rot(Sticker[0].size(), vector<int>(Sticker.size()));
			for (int i = 0; i < Sticker.size(); i++)
				for (int j = 0; j < Sticker[0].size(); j++)
					temp_rot[j][i] = Sticker[static_cast<int>(Sticker.size()) - 1 - i][j];
			Sticker.swap(temp_rot);

			int temp_xy = X;
			X = Y;
			Y = temp_xy;
		}
	Exit:;
	}

	printf("%d", result);

	return 0;
}

int attatch(vector<vector<int>> Sticker, vector<vector<int>>* laptop, int i, int j)
{
	int ret = false;
	int cnt = 0;
	laptop_temp = *laptop;
	for (int a = 0; a < Sticker.size(); a++)
	{
		for (int b = 0; b < Sticker[0].size(); b++)
		{
			if (Sticker[a][b])
			{
				if (!laptop_temp[i + a][j + b])
				{
					laptop_temp[i + a][j + b] = true;
					cnt++;
				}
				else
					return ret;
			}
		}
	}
	ret = cnt;
	*laptop = laptop_temp;
	return ret;
}