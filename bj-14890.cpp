#include <iostream>
#include <cstring>
using namespace std;

int arr[100][100];
bool isRadder[100];
int n, l;

// vertical 이 참이면 세로 방향
// 거짓이면 -> 가로 방향
int check(int row, int col, bool vertical)
{
    // 세로 방향
    if(vertical)
    {
        // 끝칸이면 종료
        if(row == n - 1) return 1;
        // 옆칸이랑 높이 같으면 한칸 옆으로 이동
        if(arr[row][col] == arr[row + 1][col]) return check(row + 1, col, vertical);
        // 올라가야 하는 경우
        if(arr[row][col] < arr[row + 1][col])
        {
            // 1칸 넘게 차이나면 경사로가 힘을 못씀
            if(arr[row + 1][col] - arr[row][col] > 1) return 0;
            // 경사로를 올릴 수 있는지 체크!
            for(int i = 0; i < l; i++)
            {
                // 범위 벗어나는 경우
                if(row - i < 0) return 0;
                // 높이가 안맞으면 사다리 불가능!
                if(arr[row - i][col] != arr[row][col]) return 0;
                // 이미 사다리를 놓았어도 불가능!
                if(isRadder[row - i]) return 0;
                isRadder[row - i] = true;
            }
            // 올라갈 수 있는 경우임 -> 한칸 이동
            return check(row + 1, col, vertical);
        }
        // 내려가야 하는 경우
        if(arr[row][col] > arr[row + 1][col])
        {
            // 1칸 넘게 차이나면 경사로가 힘을 못씀
            if(arr[row][col] - arr[row + 1][col] > 1) return 0;
            // 경사로를 내릴 수 있는지 체크!
            for(int i = 1; i <= l; i++)
            {
                // 범위 벗어나는 경우
                if(row + i >= n) return 0;
                // 높이가 안맞으면 사다리 불가능!
                if(arr[row + i][col] != arr[row + 1][col]) return 0;
                isRadder[row + i] = true;
            }
            // 내려갈 수 있는 경우 -> 여기서는 경사로 길이 l 만큼 이동해야함!
            return check(row + l, col, vertical);
        } 
    }

    // -> 가로방향
    if(!vertical)
    {
        // 끝칸이면 종료
        if(col == n - 1) return 1;
        // 옆칸이랑 높이 같으면 한칸 옆으로 이동
        if(arr[row][col] == arr[row][col + 1]) return check(row, col + 1, vertical);
        // 올라가야 하는 경우
        if(arr[row][col] < arr[row][col + 1])
        {
            // 1칸 넘게 차이나면 경사로가 힘을 못씀
            if(arr[row][col + 1] - arr[row][col] > 1) return 0;
            // 경사로를 올릴 수 있는지 체크!
            for(int i = 0; i < l; i++)
            {
                // 범위 벗어나는 경우
                if(col - i < 0) return 0;
                // 높이가 안맞으면 사다리 불가능!
                if(arr[row][col - i] != arr[row][col]) return 0;
                // 이미 사다리를 놓았어도 불가능!
                if(isRadder[col - i]) return 0;
                isRadder[col - i] = true;
            }
            // 올라갈 수 있는 경우임
            return check(row, col + 1, vertical);
        }
        // 내려가야 하는 경우
        if(arr[row][col] > arr[row][col + 1])
        {
            // 1칸 넘게 차이나면 경사로가 힘을 못씀
            if(arr[row][col] - arr[row][col + 1] > 1) return 0;
            // 경사로를 내릴 수 있는지 체크!
            for(int i = 1; i <= l; i++)
            {
                // 범위 벗어나는 경우
                if(col + i >= n) return 0;
                // 높이가 안맞으면 사다리 불가능!
                if(arr[row][col + i] != arr[row][col + 1]) return 0;
                isRadder[col + i] = true;
            }
            // 내려갈 수 있는 경우 -> 여기서는 경사로 길이 l 만큼 이동해야함!
            return check(row, col + l, vertical);
        } 
    }
    return 0;
}

int main()
{
    cin >> n >> l;
    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        memset(isRadder, false, sizeof(isRadder));
        ans += check(0, i, true);
        memset(isRadder, false, sizeof(isRadder));
        ans += check(i, 0, false);
    }

    cout << ans << '\n';
    return 0;
}