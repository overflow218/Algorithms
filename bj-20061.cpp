#include <iostream>
using namespace std;

int blue = 0, green = 0, ans = 0;
int type[4] = {1, 2, 4, 8};

void put(bool isBlue, int t, int x, int y)
{
    if(isBlue)
    {
        // blue에 놓기
        if(t <= 2)
        {
            int lastIdx = 0;
            for(int i = 0; i <= 5; i++)
            {
                if(blue & (type[x] << (4 * i))) break; 
                lastIdx = i;
            }
            blue |= type[x] << (4 * lastIdx);
            if(t == 2)
            {
                blue |= type[x] << (4 * (lastIdx - 1));
            }
        } else 
        {
            // x랑 x + 1에 놓아야함. 
            int lastIdx = 0;
            int check = type[x] + type[x + 1];
            for(int i = 0; i <= 5; i++)
            {
                if(blue & (check << (4 * i))) break; 
                lastIdx = i;
            }
            blue |= check << (4 * lastIdx);
        }
    } else 
    {
        // green에 놓기
        if(t == 2)
        {
            // y랑 y + 1에 놓아야함. 
            int lastIdx = 0;
            int check = type[y] + type[y + 1];
            for(int i = 0; i <= 5; i++)
            {
                if(green & (check << (4 * i))) break; 
                lastIdx = i;
            }
            green |= check << (4 * lastIdx);
        } else 
        {
            int lastIdx = 0;
            for(int i = 0; i <= 5; i++)
            {
                if(green & (type[y] << (4 * i))) break; 
                lastIdx = i;
            }
            green |= type[y] << (4 * lastIdx);
            if(t == 3)
            {
                green |= type[y] << (4 * (lastIdx - 1));
            }
        }
    }
}

// target번 터뜨리기
void bomb(int &target)
{
    while(true)
    {
        bool isDone = true;
        // 터트릴꺼있는지 체크
        for(int i = 5; i >= 0; i--)
        {
            // i번째 행 or 열을 날려버려야 하는 경우
            if(((target >> (4 * i)) & 15) == 15)
            {
                ans++;
                int tmp = target << 4;
                for(int j = i; j >= 0; j--)
                {
                    target &= ~(15 << (4 * j));
                    target |= tmp & (15 << (4 * j));
                }
                isDone = false;
                break;
            }
        }
        if(isDone) break;
    }
}

// 0,1번 영역에 블록이 놓인 열/행 개수만큼 옆으로 이동
void clear(int &target)
{
    int cnt = 0;
    if(target & 15) cnt++;
    if(target & (15 << 4)) cnt++;
    target = target << (4 * cnt);
}

int main()
{
    int n, t, x, y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t >> x >> y;
        // 블록 놓아주기
        put(true, t, x, y);
        put(false, t, x, y);
        
        // 터뜨릴거 있으면 터뜨리기
        bomb(blue);
        bomb(green);

        // 0, 1 영역에 있으면 칸 떙겨주기
        clear(blue);
        clear(green);
    }

    int cnt = 0;
    for(int i = 0; i < 24; i++)
    {
        if(blue & (1 << i))cnt++;
        if(green & (1 << i))cnt++;
    }

    printf("%d\n%d\n", ans, cnt);
    return 0;
}