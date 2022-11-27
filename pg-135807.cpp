#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
1. 각각 최대공약수를 구한다. 
2. 최대공약수의 약수들도 구한다 - 생각해보니 필요없네 
반대쪽에 대해서는 나누어지면 안되는 상황인데 최대공약수로 나눌 수 있으면 최대공약수의 약수들로도 다 나눌 수 있음. 
3. 그것들로 돌면서 가장 큰 값을 찾는다 끝!
*/

// a, b의 최대공약수 반환
int gcd(int a, int b)
{
    if(a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

// x의 모든 약수 반환
vector<int> getDivisor(int x)
{
    vector<int> arr;
    int limit = sqrt(x);
    for(int i = 1; i <= limit; i++)
    {
        if(x % i == 0)
        {
            arr.push_back(i);
            if(x / i != i)
            {
                arr.push_back(x / i);
            }
        }
    }
    sort(arr.begin(), arr.end(), greater());
    return arr;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0], gcdB = arrayB[0];
    for(int i = 0; i < arrayA.size(); i++)
    {
        gcdA = gcd(gcdA, arrayA[i]);
    }

    for(int i = 0; i < arrayB.size(); i++)
    {
        gcdB = gcd(gcdB, arrayB[i]);
    }

    vector<int> divisorA = getDivisor(gcdA);
    vector<int> divisorB = getDivisor(gcdB);

    bool isDone = true;
    for(int j = 0; j < arrayB.size(); j++)
    {
        if(arrayB[j] % gcdA == 0)
        {
            isDone = false;
            break;
        }
    }
    if(isDone)
    {
        answer = gcdA;
    }
    
    isDone = true;
    for(int j = 0; j < arrayA.size(); j++)
    {
        if(arrayA[j] % gcdB == 0)
        {
            isDone = false;
            break;
        }
    }
    if(isDone)
    {
        answer = max(answer, gcdB);
    }

    return answer;
}