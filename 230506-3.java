/*
오키. 일단 주어진 보드 크기가 50 * 50 이라서 그리 크지 않음. 
일단 8가지 방향에 대해서 지뢰 개수를 세어서 각 좌표마다 인접 지뢰를 세어줘야함. 
자기 자신이 지뢰인 경우는 따로 신경써줘야 하고 
그다음에 dfs로 하나하나 타고 들어가면서 작업해주면 될듯요
*/

class Solution {
    int w, h;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int bomb[][] = new int[52][52];
    boolean isOpend[][] = new boolean[52][52];
    char[][] tmpBoard = new char[51][52];

    public void change(int x, int y) {

        if(x < 0 || x == h || y < 0 || y == w || isOpend[x][y]) return;
        isOpend[x][y] = true;
        // 폭탄 누른 경우
        if(tmpBoard[x][y]== 'M')
        {
            tmpBoard[x][y] = 'X';
            return;
        }
        // 폭탄칸 말고 누른경우
        if(bomb[x][y] == 0)
        {
            tmpBoard[x][y] = 'B';
            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                change(nx, ny);
            }
        }
        if(bomb[x][y] > 0)
        {
            // 남아있는 경우에는 숫자표시
            tmpBoard[x][y] = Character.forDigit(bomb[x][y], 10);
        }
    }
    public String[] solution(String[] board, int y, int x) {
        w = board[0].length(); h = board.length;
        String[] answer = new String[h];
        for(int i = 0; i < h; i++)
        {
            tmpBoard[i] = board[i].toCharArray();
        }

        // 지뢰 개수 세주기
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                bomb[i][j] = 0;
                isOpend[i][j] = false;
                for(int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    // 문제조건이랑 x,y방향 반대인거 조심
                    if(nx < 0 || nx == h || ny < 0 || ny == w) continue;
                    if(tmpBoard[nx][ny] == 'M') bomb[i][j]++;
                }
            }
        }

        change(y, x);
        // 맨처음 지뢰 눌렀을때는 나머지 지뢰 보존
        // 그게 아닌경우에는 방문하지 않은 칸은 E로 변경해주어야함.
        if(tmpBoard[y][x] != 'X')
        {
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if(!isOpend[i][j]) tmpBoard[i][j] ='E';
                }
            }
        }

        for(int i = 0; i < h; i++)
        {
            answer[i] = String.valueOf(tmpBoard[i]);
        }
        return answer;
    }
}