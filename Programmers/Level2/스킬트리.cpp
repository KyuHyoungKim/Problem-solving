#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int pos = 0;
    vector<int> temp;

    for(int i = 0; i <skill_trees.size() ; i++)
    {
        if(!temp.empty())
            temp.clear();
        for(int j = 0; j<skill_trees[i].size(); j++)
        {
            pos = 0;
            pos = skill.find(skill_trees[i][j]);
            if(pos!=-1)
                temp.push_back(pos);
        }
        if(temp.empty())
            answer++;
        else
        {
            for(int j = 0 ; j<temp.size()-1;j++)
            {
                if(temp[0]!=0)
                    break;

                if(temp[j]>temp[j+1] || temp[j+1]-temp[j]>1)
                    break;

                if(j == temp.size()-2)
                answer++;
            }
            if(temp.size()==1&&temp[0]==0)
                answer++;
        }
    }
    return answer;
}
