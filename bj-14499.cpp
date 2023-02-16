#include <iostream>
using namespace std;

int arr[20][20] = {0};

// 각면이 1,2,3,4,5,6 의 가상의 수가 적혀있다고 가정. 
struct Dice {
    int top = 1;
    int bottom = 6;
    int left = 4;
    int right = 3;
    int north = 2;
    int south = 5;
    int value[7] = {0, 0, 0, 0, 0, 0, 0};
};

int main()
{
    int n, m, x, y, k, oper;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    Dice dice;
    for(int i = 0; i < k; i++)
    {
        cin >> oper;
        int nLeft = dice.left, nTop = dice.top, nRight = dice.right, nBottom = dice.bottom, nNorth = dice.north, nSouth = dice.south;

        // -> 동쪽굴리기
        if(oper == 1)
        {
            // 범위 벗어나면 컷
            if(y + 1 == m) continue;
            y++;
            nLeft = dice.bottom;
            nTop = dice.left;
            nRight = dice.top;
            nBottom = dice.right;
        } 
        // <- 서쪽 굴리기
        else if(oper == 2)
        {
            // 범위 벗어나면 컷
            if(y == 0) continue;
            y--;
            nLeft = dice.top;
            nTop = dice.right;
            nRight = dice.bottom;
            nBottom = dice.left;
        }
        // 북쪽 굴리기
        else if(oper == 3)
        {
            // 범위 벗어나면 컷
            if(x == 0) continue;
            x--;
            nNorth = dice.top;
            nTop = dice.south;
            nSouth = dice.bottom;
            nBottom = dice.north;
        }
        // 남쪽 굴리기
        else 
        {
            // 범위 벗어나면 컷
            if(x + 1== n) continue;
            x++;
            nNorth = dice.bottom;
            nTop = dice.north;
            nSouth = dice.top;
            nBottom = dice.south;
        }

        // 주사위 방향 갱신
        dice.top = nTop;
        dice.bottom = nBottom;
        dice.left = nLeft;
        dice.right = nRight;
        dice.north = nNorth;
        dice.south = nSouth;

        // 상황별 복사
        if(arr[x][y] == 0)
        {
            arr[x][y] = dice.value[dice.bottom];
        } else 
        {
            dice.value[dice.bottom] = arr[x][y];
            arr[x][y] = 0;
        }
        cout << dice.value[dice.top] << '\n';
    }

    return 0;
}