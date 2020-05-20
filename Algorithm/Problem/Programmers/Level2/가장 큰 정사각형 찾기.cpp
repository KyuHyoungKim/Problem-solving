#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int max = 0;
    for (int y = 0; y < board.size() - 1; ++y)
        for (int x = 0; x < board[0].size() - 1; ++x)
        {
            if (board[y + 1][x + 1])
            {
                int min = board[y][x];
                if (board[y + 1][x] < min)
                    min = board[y + 1][x];
                if (board[y][x + 1] < min)
                    min = board[y][x + 1];

                board[y + 1][x + 1] = min + 1;
                if (max < board[y + 1][x + 1])
                    max = board[y + 1][x + 1];
            }
        }
    
    if(!max)
    {
        for(int y = 0 ; y < board.size(); ++y)
            for(int x = 0 ; x < board[0].size(); ++x)
                if(board[y][x])
                    return 1;
    }
    
    return max * max;
}
