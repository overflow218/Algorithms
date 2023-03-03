#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;
char tmp[110];
int main()
{
    int r, c, n, k;
    cin >> r >> c;
    string newLine = "";
    for(int i = 0; i < c; i++)
    {
        newLine += ".";
    }
    for(int i = 0; i < r; i++)
    {
        scanf("%s", tmp);
        string x = tmp;
        arr.push_back(x);
    }

    reverse(arr.begin(), arr.end());

    cin >> n;
    for(int it = 0; it < n ; it++)
    {
        cin >> k;
        k--;

        // 이번에 삭제되었는지 확인
        bool isRemoved = false;

        // -> 왼쪽에서 오른쪽
        if(it % 2 == 0)
        {
            for(int i = 0; i < c; i++)
            {
                if(arr[k][i] == 'x')
                {
                    arr[k][i] = '.';
                    isRemoved = true;
                    break;
                }
            }
        } 
        // <- 오른쪽에서 왼쪽
        else 
        {
            for(int i = c - 1; i >= 0; i--)
            {
                if(arr[k][i] == 'x')
                {
                    arr[k][i] = '.';
                    isRemoved = true;
                    break;
                }
            }
        }

        // 만약에 하나 없앴고, 그래서 그줄이 다 비었으면 한칸 내려주는게 맞음
       
        if(isRemoved && arr[k] == newLine)
        {
            arr.erase(arr.begin() + k);
            arr.push_back(newLine);
        }

    }
    printf("-------\n");
    for(int i = 0; i < r; i++)
    {
        cout << arr[r - 1 - i] << '\n';
    }
    return 0;
}