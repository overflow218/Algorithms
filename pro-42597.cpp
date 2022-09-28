#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class music{
    public:
        string genre;
        int musicNumber;
        int playCount;
    public:
        music(string name, int number, int count)
        {
            genre = name;
            musicNumber = number;
            playCount = count;
        }
};

map<string, int> genreCount;
vector<music> playList;

bool cmp(music a, music b)
{
    if(a.genre != b.genre)
    {
        return genreCount[a.genre] > genreCount[b.genre];
    }
    return a.playCount > b.playCount;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < plays.size(); i++)
    {
        genreCount[genres[i]] += plays[i];
        playList.push_back(music(genres[i], i, plays[i]));
    }
    sort(playList.begin(), playList.end(), cmp);
    genreCount.clear();
    for (auto const & music:playList)
    {
        if(genreCount[music.genre] < 2)
        {
            answer.push_back(music.musicNumber);
            genreCount[music.genre]++;
        }
    }
    return answer;
}