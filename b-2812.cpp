#include <iostream>
#include <vector>
using namespace std;

char s[500001] = {0};

int find(vector<bool> &isValid, int idx)
{
    for(int i = idx - 1; i >= 0; i--)
    {
        if(isValid[i]) return i;
    }
    return idx;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    vector<bool> isValid(n + 1, true);

    int front = 0, back = 1, cnt = 0, limit = n - 1;
    while(cnt < k)
    {
        if(s[front] >= s[back])
        {
            if(back == limit)
            {
                isValid[back] = false;
                back = front;
                front = find(isValid, front);
                cnt++;
                limit = back;
            } else 
            {
                front = back;
                back++;
            }
        } else 
        {
            isValid[front] = false;
            int nFront = find(isValid, front);
            if(nFront == front)
            {
                front = back;
                back++;
            } else 
            {
                front = nFront;
            }
            cnt++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(isValid[i])
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}