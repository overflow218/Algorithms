#include<iostream>
#include <vector>
#include <cstring>
using namespace std;

char original[1000001] = {0};
char target[40] = {0};
vector<char> vec;
int targetLen;

void bomb()
{
    int size = vec.size();
    if(size < targetLen) return;
    for(int i = 0; i < targetLen; i++)
    {
        if(target[targetLen - 1 - i] != vec[size - 1 - i]) return;
    }
    // bomb
    for(int i = 0; i < targetLen; i++)
    {
        vec.pop_back();
    }
}
int main()
{
    scanf("%s %s", original, target);
    int limit = strlen(original);
    targetLen = strlen(target);

    for(int i = 0; i < limit; i++)
    {
        vec.push_back(original[i]);
        bomb();
    }
    
    if(vec.size() == 0)
    {
        printf("FRULA\n");
    } else 
    {
        for(int i = 0; i < vec.size(); i++)
        {
            printf("%c", vec[i]);
        }
        printf("\n");
    }
    
    return 0;
}