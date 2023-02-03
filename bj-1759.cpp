#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, C;
bool isVowel(char x)
{
    switch (x)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

void find(int idx, vector<bool> &isVisited, string &chosen, vector<char> & alphabet)
{

    if(chosen.size() == l)
    {
        int vowel = 0;
        for(int i = 0; i < l; i++)
        {
            if(isVowel(chosen[i])) vowel++;
        }
        // printf("chosen: %s, vowel: %d, mowel: %d\n", chosen.c_str(), vowel, l- vowel);
        if(vowel >= 1 && l - vowel >= 2)
        {
            printf("%s\n", chosen.c_str());
        }
    } else if(idx == C)
    {
        return;
    }
    else 
    {
        for(int i = idx; i < C; i++)
        {
            if(!isVisited[i])
            {
                isVisited[i] = true;
                chosen.push_back(alphabet[i]);
                find(i + 1, isVisited, chosen, alphabet);
                chosen.pop_back();
                isVisited[i] = false;
            }
        }   
    }
}
int main()
{
    scanf("%d %d", &l, &C);
    vector<char> alphabet(C);
    vector<bool> isVisited(C, false);
    string chosen;
    char buf[10];
    for(int i = 0; i < C; i++)
    {
        scanf("%s", buf);
        alphabet[i] = buf[0];
    }
    sort(alphabet.begin(), alphabet.end());
    find(0, isVisited, chosen, alphabet);
    return 0;
}