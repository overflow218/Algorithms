/*
이거는 일단 
(x, y)까지 가는 방법의 수 * (x - 1, y + 1)에서 (w, h)까지 가는 방법의 수
이게 각 경우마다의 가지수임. 그리고 거리는 각 경우가 무조건 같음. 
즉, 모든 경우가 최단거리란 소리임 저거 경우의 수만 구해서 곱하고 더해주면 될듯.
수가 크니까 오버플로우 조심하고 ㅇㅇ
*/

class Solution {
    public int solution(int width, int height, int[][] diagonals) {
        long answer = 0;
        final long mod = 10000019;
        // 혹시 모르니 넉넉하게 잡아두기
        long[][] choose = new long[510][510];
        for(int i = 0; i <= 505; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    choose[i][j] = 1;
                    continue;
                }
                if(j == 1 || j == i - 1)
                {
                    choose[i][j] = i;
                    continue;
                }
                choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
            }
        }

        for(int i = 0; i < diagonals.length; i++)
        {
            int x = diagonals[i][0], y = diagonals[i][1];
            long tmp1 = choose[x + y - 1][x] * choose[width - x + 1 + height - y][height - y];
            long tmp2 = choose[x + y - 1][y] * choose[width - x + height - y + 1][height - y + 1];
            long ho = (tmp1 + tmp2) % mod;
            answer = (answer + ho) % mod;
        }
        return (int)answer;
    }
}