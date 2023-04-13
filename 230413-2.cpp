#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct mineral
{
    int dia;
    int iron;
    int stone;
};

bool cmp(mineral &m1, mineral &m2)
{
    if(m1.dia != m2.dia) return m1.dia > m2.dia;
    if(m1.iron != m2.iron) return m1.iron > m2.iron;
    return m1.stone > m2.stone;
}

vector<mineral> scv;
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int diaPick = picks[0], ironPick = picks[1], stonePick = picks[2];
    int limit = min(5 * (picks[0] + picks[1] + picks[2]), (int)minerals.size());
    int dia = 0, iron = 0, stone = 0;
    for(int i = 0; i < limit; i++)
    {
        if(minerals[i][0] == 'd') dia++;
        if(minerals[i][0] == 'i') iron++;
        if(minerals[i][0] == 's') stone++;
        if(i % 5 == 4)
        {
            scv.push_back(mineral{dia, iron, stone});
            dia = 0; iron = 0; stone = 0;
        }
    }
    
    if(limit % 5 != 0)
    {
        scv.push_back(mineral{dia, iron, stone});
    }
    
    sort(scv.begin(), scv.end(), cmp);
    
    for(int i = 0;i < scv.size(); i++)
    {
        // printf("d: %d, iron: %d, stone: %d\n", scv[i].dia, scv[i].iron, scv[i].stone);
        if(diaPick > 0)
        {
            answer += scv[i].dia + scv[i].iron + scv[i].stone;
            diaPick--;
            continue;
        }
        if(ironPick > 0)
        {
            answer += 5 * scv[i].dia + scv[i].iron + scv[i].stone;
            ironPick--;
            continue;
        }
        if(stonePick > 0)
        {
            answer += 25 * scv[i].dia + 5 * scv[i].iron + scv[i].stone;
            stonePick--;
        }
    }
    return answer;
}