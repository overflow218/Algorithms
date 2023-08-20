#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<string> opers;
vector<long long> nums;

long long limit = 1000000000;

long long mod(long long x, long long y)
{
    long long tmp = abs(x) % abs(y);
    if(x < 0) tmp = -tmp;
    return tmp;
}

long long divide(long long x, long long y)
{
    long long tmp = abs(x) / abs(y);
    if(x * y < 0) tmp = -tmp;
    return tmp;
}

void play(long long x)
{
    stack<long long> st;
    st.push(x);
    int numIdx = 0;
    bool isValid = true;

    for(int i = 0; i < opers.size(); i++)
    {
        if(opers[i][0] == 'N')
        {
            st.push(nums[numIdx++]);
            continue;
        }

        // stack에 최소 1개필요 
        if(st.empty())
        {
            isValid = false;
            break;
        }

        if(opers[i][0] == 'P')
        {
            st.pop();
            continue;
        }
        if(opers[i][0] == 'I')
        {
            long long tmp = st.top();
            st.pop();
            st.push(-tmp);
            continue;
        }
        if(opers[i] == "DUP")
        {
            st.push(st.top());
            continue;
        }

        // 최소 2개의 연산자 필요
        if(st.size() < 2){
            isValid = false;
            break;
        }
        long long a = st.top();
        st.pop();
        long long b = st.top();
        st.pop();
        
        if(opers[i] == "SWP")
        {
            st.push(a);
            st.push(b);
        }
        if(opers[i][0] == 'A')
        {
            st.push(a + b);
        }
        if(opers[i] == "SUB")
        {
            st.push(b - a);
        }
        if(opers[i] == "MUL")
        {
            st.push(a * b);
        }
        if(opers[i] == "DIV")
        {
            if(a == 0)
            {
                isValid = false;
                break;
            }
            st.push(divide(b, a));
        }
        if(opers[i] == "MOD")
        {
            if(a == 0)
            {
                isValid = false;
                break;
            }
            st.push(mod(b, a));
        }

        if(abs(st.top()) > limit)
        {
            isValid = false;
            break;
        }
    }

    if(!isValid || st.size() != 1 || abs(st.top()) > limit)
    {
        printf("ERROR\n");
    } else 
    {
        printf("%lld\n", st.top());
    }
}

int main()
{
    char buf[5] = {0};
    scanf("%s", buf);
    while(buf[0] != 'Q')
    {
        // END 인 경우 
        if(buf[0] == 'E')
        {
            int n, tmp;
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &tmp);
                play(tmp);
            }

            // opers = vector<string>();
            // nums = vector<long long>();
            opers.clear();
            nums.clear();
            printf("\n");
            scanf("%s", buf);
            continue;   
        }

        if(buf[0] == 'N')
        {
            long long tmp;
            scanf("%lld", &tmp);
            nums.push_back(tmp);
        }
        string oper = buf;
        opers.push_back(oper);
        scanf("%s", buf);
    }

    return 0;
}