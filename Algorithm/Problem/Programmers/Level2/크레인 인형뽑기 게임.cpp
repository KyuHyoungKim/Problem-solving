#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector <stack<int>> A(board.size());
    stack <int> basket;
    
    for(int i = board.size() - 1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j <board[0].size() ; j++)
        {
            if(board[i][j]>0)
                A[j].push(board[i][j]);
        }
    }
    
    for(int i = 0 ; i < moves.size() ; i++)
    {
        if(!A[moves[i]-1].empty())
        {
            if (basket.empty() || basket.top() != A[moves[i] - 1].top())
                basket.push(A[moves[i]-1].top());
            else
            {
                basket.pop();
                answer+=2;
            }
            A[moves[i]-1].pop();
        }
    }
    return answer;
}
