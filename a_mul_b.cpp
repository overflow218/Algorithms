#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char A[300010];
char B[300010];

// 올림을 시행해주는 함수 카라추바 중간에 뺄셈이 있어서 -인 경우도 처리해줘야함
// 모든 정수는 배열에 담겨있고, 편의상 뒤집힌 순서를 유지한다고 가정하겠음.
// vec[0]이 제일 작은 수를 표현함
void olim(vector<int> & vec)
{
    // 자리수가 넘어갈 수 있으니 넉넉하게 넣어둔다.
    vec.push_back(0);
    int limit = vec.size();
    for(int i = 0; i < limit; i++)
    {
        // 양수일때는 올림가능하면 넘겨주면 됨.
        if(vec[i] > 0)
        {
            vec[i + 1] += vec[i] / 10;
            vec[i] %= 10;
        } 
        // 음수일때는 내려줘야함. 이게 곱셈이고, 수식적으로 절대로 전체가 -가 되는 경우는 없기때문에 
        // 앞자리에서 땡겨오면 됨.
        else if(vec[i] < 0)
        {
            // -1 ~ -10 은 앞자리에서 1개
            // -11 ~ -20은 앞자리에서 2개 
            // .. 이 규칙을 활용해보면
            int needed = (9 - vec[i]) / 10;
            vec[i] += 10 * needed;
            vec[i + 1] -= needed;
        }
    }

    // 맨앞에 있는 불필요한 0은 제거해준다
    while(!vec.empty() && vec.back() == 0)
    {
        vec.pop_back();
    }
}

// 10 ^ k 로 곱해주는 연산
void shift(vector<int> &vec, int k)
{
    vector<int> newVec(k, 0);
    int originalSize = vec.size();
    for(int i = 0; i < k; i++)
    {
        vec.push_back(0);
    }
    for(int i = originalSize - 1; i >= 0; i--)
    {
        vec[i + k] = vec[i];
        vec[i] = 0;
    }
}

// vec1이 더 큰거라고 가정하고 vec1에 더해줄거임. 
void add(vector<int> &vec1, vector<int> &vec2)
{
    for(int i = 0; i < vec2.size(); i++)
    {
        vec1[i] += vec2[i];
    }
    olim(vec1);
}

// vec1이 더 큰거라고 가정하고 vec1에 빼줄거임. 
// 음 왠지 틀리는게 빼기에서 뭔가 잘못되는거 같은데 ㅋㅋ..
void subtract(vector<int> &vec1, vector<int> &vec2)
{
    for(int i = 0; i < vec2.size(); i++)
    {
        vec1[i] -= vec2[i];
    }
    olim(vec1);
}

// 크기가 작을때는 그냥 단순한 방법의 곱셈으로 충분쓰
// n자리수 * m자리수 => 최대 n + m + 1 자리수임 
vector<int> simpleMultiply(vector<int> a, vector<int> b)
{
    int sizeA = a.size(), sizeB = b.size();
    vector<int> ret(sizeA + sizeB + 1, 0);

    for(int i = 0; i < sizeA; i++)
    {
        for(int j = 0; j < sizeB; j++)
        {
            ret[i + j] += a[i] * b[j];
        }
    }

    olim(ret);
    return ret;
}

vector<int> karatuba(vector<int> a, vector<int> b)
{
    // 만약에 둘중 하나라도 비어있는 거면 그냥 0이니까 바로 종료해주기
    if(a.empty() || b.empty())
    {
        return vector<int>();
    }

    // 편의상 a >= b 라고 가정
    if(a.size() < b.size())
    {
        return karatuba(b, a);
    }

    // 그리고 크기가 작은경우에는 그냥 곱하는게 빠르니까 그렇게 구현해주기
    int size = a.size();
    if(size <= 100)
    {
        return simpleMultiply(a, b);
    }

    // a = a1 * 10 ^ half + a0
    // b = b1 * 10 ^ half + b0 이거나 b의 자리수가 half보다 작다면
    // b = b0 이렇게 될거임 
    int half = size / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());

    vector<int> b0(b.begin(), b.begin() + min((int)b.size(), half));
    vector<int> b1(b.begin() + min((int)b.size(), half), b.end());

    // z0 = a0 * b0
    // z1 = a1 * b1
    // z2 = (a1 + a0) * (b1 + b0) - z0 - z1
    vector<int> z0 = karatuba(a0, b0);
    vector<int> z1 = karatuba(a1, b1);
    // a1 = a1 + a0
    add(a1, a0);

    // b1 = b1 + b0
    // 이거 b1이 비어있거나 더 작을 수 있어서 문제 생기네 ㅋㅋ..
    vector<int> z2;
    if(b1.size() < b0.size())
    {
        add(b0, b1);
        z2 = karatuba(a1, b0);
    } else 
    {
        add(b1, b0);
        z2 = karatuba(a1, b1);
    }

    subtract(z2, z0);
    subtract(z2, z1);

    // 결과 = z1 * 10 ^ (2 * half) + z2 * 10 ^ half + z0
    shift(z1, 2 * half);
    shift(z2, half);
    add(z1, z2);
    add(z1, z0);

    return z1;
}
int main()
{    
    scanf("%s %s", A, B);
    vector<int> a, b;
    
    // 배열에 담아주는 선처리
    for(int i = strlen(A) - 1; i >= 0; i--)
    {
        a.push_back(A[i] - '0');
    }
    for(int i = strlen(B) - 1; i >= 0; i--)
    {
        b.push_back(B[i] - '0');
    }

    vector<int> ans = karatuba(a, b);
    if(ans.empty())
    {
        printf("0\n");
    } else 
    {
        for(int i = ans.size() - 1; i >= 0; i--)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
