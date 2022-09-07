#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1001] = {0};

string find(int & idx)
{
    char current = buf[idx++];
    string res = "";
    if(current == 'x')
    {
        string upperLeft = find(idx);
        string upperRight = find(idx);
        string lowerLeft = find(idx);
        string lowerRight = find(idx);
        return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
    }
    return res += current;
}

int main()
{
    int c;
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        int idx = 0;
        scanf("%s", buf);
        printf("%s\n", find(idx).c_str());
    }
    return 0;
}