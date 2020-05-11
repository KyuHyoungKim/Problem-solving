#include <vector>

using namespace std;

int Find_Area_Size(vector<vector<int>>* picture, vector<vector<bool>>* checked, int pos_y, int pos_x, int value, int max_size_y, int max_size_x);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int area_size;
    vector<vector<bool>> checked(m, vector<bool>(n, false));

    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (checked[y][x])
                continue;
            else
            {
                if (!picture[y][x])
                    checked[y][x] = true;
                else
                {
                    ++number_of_area;
                    area_size = Find_Area_Size(&picture, &checked, y, x, picture[y][x], m, n);
                    if (area_size > max_size_of_one_area)
                        max_size_of_one_area = area_size;
                }
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int Find_Area_Size(vector<vector<int>>* picture, vector<vector<bool>>* checked, int pos_y, int pos_x,int value, int max_size_y, int max_size_x)
{    
    int ret = 1;
    (*checked)[pos_y][pos_x] = true;
    
    for(int i = 0 ; i < 4; i++)
    {
        int Y = pos_y + dy[i];
        int X = pos_x + dx[i];
        if (Y >= 0 && Y < max_size_y && X >= 0 && X < max_size_x && !(*checked)[Y][X])
        {
            if(!(*picture)[Y][X])
                (*checked)[Y][X] = true;
            else if ((*picture)[Y][X] == value)
            {
                (*checked)[Y][X] = true;
                ret += Find_Area_Size(picture, checked, Y, X, value, max_size_y, max_size_x);
            }
        }
    }
    return ret;
}
