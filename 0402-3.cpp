#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[2500][2500];
int pal(int s, int e, string &word)
{
    if (s > e)
        return 0;
    if (s == e)
        return 1;
    int &ret = cache[s][e];
    if (ret != -1)
        return ret;
    ret = pal(s + 1, e, word);
    ret = max(ret, pal(s, e - 1, word));
    ret = max(ret, pal(s + 1, e - 1, word));
    if (word[s] == word[e] && pal(s + 1, e - 1, word) + 2 == e - s + 1)
    {
        ret = max(ret, pal(s + 1, e - 1, word) + 2);
    }
    return ret;
}
int solution(string s)
{
    memset(cache, -1, sizeof(cache));
    return pal(0, s.size() - 1, s);
}