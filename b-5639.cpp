#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;

void find(int s, int e)
{
    if(s >= e)
    {
        if(s == e) printf("%d\n", tree[s]);
        return;
    }
    int idx = upper_bound(tree.begin() + s, tree.begin() + e + 1, tree[s]) - tree.begin();
    find(s + 1, idx - 1);
    find(idx, e);
    printf("%d\n", tree[s]);
}
int main()
{
    int tmp;
    while(1){
        cin >> tmp;
        if(cin.eof()) break;
        tree.push_back(tmp);
    }

    find(0, tree.size() - 1);
    return 0;
}