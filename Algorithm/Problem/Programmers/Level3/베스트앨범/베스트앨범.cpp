#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct info {
    vector<pair<int, int>> play;
    string genre;
    int play_sum = 0;
};

struct comp {
    bool operator()(const info& a, const info& b) {
        return a.play_sum > b.play_sum;
    }
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, info> songs;
    vector<info> infos;

    for (int i = 0; i < genres.size(); i++) {
        songs[genres[i]].play_sum += plays[i];
        songs[genres[i]].play.push_back(make_pair(plays[i], i));
    }

    for (map<string, info>::iterator iter = songs.begin(); iter != songs.end(); iter++)
        infos.push_back(iter->second);
    sort(infos.begin(), infos.end(), comp());

    for (int i = 0; i < infos.size(); i++) {
        sort(infos[i].play.begin(), infos[i].play.end(), comp());
        for (int j = 0; j < 2 && j < infos[i].play.size(); j++)
            answer.push_back(infos[i].play[j].second);
    }
    return answer;
}