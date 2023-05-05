#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    sort(v.begin(), v.end());
    int x, y;
    if(v[0][0] == v[1][0]) x = v[2][0];
    if(v[0][0] != v[1][0]) x = v[0][0];
    if(v[0][1] == v[1][1]) y = v[2][1];
    if(v[0][1] != v[1][1]) y = v[0][1];
    return {x, y};
}