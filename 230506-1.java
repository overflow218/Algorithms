/*
정렬 해주고 10만원 이하의 최대 나올때 그냥 매번 컷해주면 될듯
음 오버 플로우 발생할 일은 없을지 신경써주면 좋을것 같긴하네 
아 오버플로우 날일이 없네. 한번에 최대 10만원씩 늘어나는거니까
100일 내내 10만원씩 늘어날 방법이 있다고 해도 
처음 시작꺼 맥스가 1백만이니까 첫날 1백만, 100번째날 1천1백만. 절대 안넘음
*/
import java.util.Arrays;
class Solution {
    public int solution(int[] boxes, int m, int k) {
        Arrays.sort(boxes);
        int idx = boxes.length - 1;
        for(int t = 0; t < k; t++)
        {
            int nIdx = idx;
            for(int i = nIdx; i >= 0; i--)
            {
                int tmp = m / 10000;
                int plus = tmp * boxes[i];
                if(plus <= 100000)
                {
                    idx = i;
                    m += plus;
                    break;
                }
            }
        }
        return m;
    }
}