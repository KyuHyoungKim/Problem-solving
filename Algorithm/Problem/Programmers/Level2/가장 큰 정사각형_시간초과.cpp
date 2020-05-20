#include <iostream>
#include<vector>
using namespace std;
int Find_Square(vector<vector<int>> board, int start_x, int start_y, int Length);

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    int Length = 0;
    if (board.size() > board[0].size())
        Length = board[0].size();
    else
        Length = board.size();

    answer = Find_Square(board, 0, 0, Length);
    if(answer == 1)
    {
        for(int y = 0 ; y < board.size(); ++y)
            for(int x = 0 ; x < board[0].size(); ++x)
                if(board[y][x])
                    return answer;
        return 0;
    }
    return answer;
}

int Find_Square(vector<vector<int>> board, int start_x, int start_y, int Length)
{
    int ret = Length * Length;
    
    if (Length == 1)
        return Length;
    
    for (int y = start_y; y < start_y + Length; ++y)
    {
        for (int x = start_x; x < start_x + Length; ++x)
        {
            if (!board[y][x])
            {
                if (start_x + Length < board[0].size())
                    return Find_Square(board, start_x + 1, start_y, Length);
                else if (start_y + Length < board.size())
                    return Find_Square(board, 0, start_y + 1, Length);
                else
                    return Find_Square(board, 0, 0, Length - 1);
            }
        }
    }
    return ret;
}
