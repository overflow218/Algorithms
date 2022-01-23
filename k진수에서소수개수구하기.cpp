#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

// 최대 입력이 10 ^ 6 인데 이는 이진법으로 대략 2 ^ 20 안되는 숫자임
// 그러면 2진법으로 변환하면 20자리 정도 나온다는건데 int자리형에는 20자리가 안담김
// 그래서 String으로 바꿔서 풀어줘야 함

bool isPrime(long long x)
{
    if(x == 1)
    {
        return false;
    }
    
    long long limit = sqrt(x);
    for(long long i = 2; i <= limit; i++)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string nInK = "";

    while(n)
    {
        nInK = to_string(n % k) + nInK;
        n /= k;
    }

    char tmp[100];
    strcpy(tmp, nInK.c_str());

    char* ptr = strtok(tmp, "0");

    while (ptr != NULL) {
        string pieceNum = ptr;
        long long tmpNum = stoll(pieceNum);
        if(isPrime(tmpNum))
        {
            answer++;
        }
        ptr = strtok(NULL, "0");
  }
    return answer;
}
