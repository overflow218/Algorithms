#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
map<int, char> people;
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    people[0] = 'A';
    people[1] = 'C';
    people[2] = 'F';
    people[3] = 'J';
    people[4] = 'M';
    people[5] = 'N';
    people[6] = 'R';
    people[7] = 'T';

    do {
        map<char, int> current_position;
        for(int i = 0; i < 8; i++)
        {
            current_position[people[vec[i]]] = i;
        }
        bool isGood = true;
        for(int i = 0; i < n; i++)
        {
            int p1 = current_position[data[i][0]], p2 = current_position[data[i][2]], dist = data[i][4] - '0';
            int current_dist = abs(p1 - p2) - 1;
            char oper = data[i][3];
            switch (oper)
            {
            case '=':
                if(current_dist != dist)
                {
                    isGood = false;
                }
                break;
            case '<':
                if(current_dist >= dist)
                {
                    isGood = false;
                }
                break;
            default:
                if(current_dist <= dist)
                {
                    isGood = false;
                }
                break;
            }
            if(!isGood) break;
        }
        if(isGood) answer++;
    } while(next_permutation(vec.begin(), vec.end()));

    return answer;
}