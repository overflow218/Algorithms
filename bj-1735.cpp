#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    // a분자 / b분모로 분수를 표현
    int a1, a2, b1, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    int a = a1 * b2 + a2 * b1;
    int b = b1 * b2;
    int div = gcd(a, b);
    printf("%d %d\n", a / div, b / div);
    
    return 0;
}