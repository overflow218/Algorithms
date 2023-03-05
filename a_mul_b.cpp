#include <iostream>
#include <vector>
using namespace std;

char A[300010];
char B[300010];

void clear(vector<int> & vec)
{
    // 자리수가 넘어갈 수 있으니 넉넉하게 넣어둔다.
    int limit = vec.size();
    for(int i = 0; i < limit; i++)
    {
        vec.push_back(0);
    }

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] > 10)
        {
            vec[i + 1] += vec[i] / 10;
            vec[i] %= 10;
        } else if(vec[i] < 0)
        {
            
        }
    }
}

int main()
{    
    scanf("%s %s", A, B);
    vector<int> a, b;
    
    printf("len: %d\n", strlen(A));
    for(int i = strlen(A) - 1; i >= 0; i--)
    {
        a.push_back(A[i] - '0');
    }
    for(int i = strlen(B) - 1; i >= 0; i--)
    {
        b.push_back(B[i] - '0');
    }
    return 0;
}