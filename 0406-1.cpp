#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

vector<int> A;
vector<int> B;

int check(int x, vector<int> & array)
{
    
    for(int j = 0; j < array.size(); j++)
    {
        if(array[j] % x == 0)
        {
            return 0;
        }
    }
    return x;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    if(arrayA.size() == 1)
    {
        if(arrayA[0] % arrayB[0] != 0) answer = max(answer, arrayB[0]);
        if(arrayB[0] % arrayA[0] != 0) answer = max(answer, arrayA[0]);
        return answer;
    }
    int gcdA = gcd(arrayA[0], arrayA[1]);
    int gcdB = gcd(arrayB[0], arrayB[1]);
    
    for(int i = 2; i < arrayA.size(); i++)
    {
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    return max(check(gcdA, arrayB), check(gcdB, arrayA));
}