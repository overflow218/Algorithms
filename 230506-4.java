/*
MST를 구하는 문제네 
1. 일단 network 주어진걸로 시작상황에서 연결되어있는걸 표현해야함
2. 그다음에 repair에 있는거 활용해서 연결해주면 되겠네 
이거 편하게 하려면 union & find 구현해두면 편하게 쓸거같긴함.
*/
import java.util.Arrays;
import java.util.Comparator;

public class CustomSortComparator implements Comparator<int[]>{
    @Override
    public int compare(int[] arr1, int[] arr2)
    {
        return arr1[2] - arr2[2];
    }
}

class Solution {
    int[] root = new int[100001];
    int[] size = new int[100001];

    int find(int x)
    {
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void union(int x, int y)
    {
        x = find(x);
        y = find(y);
        // 경로 압축만 해도 충분할것같긴 한데 혹시 모르니 크기도 고려해주기
        // root[y] = x;
        if(x != y)
        {
            int s1 = size[x];
            int s2 = size[y];
            if(s1 < s2)
            {
                size[y] += s1;
                root[x] = y;
            }
            if(s1 >= s2)
            {
                size[x] += s2;
                root[y] = x;
            }
        }
    }

    public int solution(int n, int[][] network, int[][] repair) {
        int answer = 0;
        for(int i = 1; i <= n; i++)
        {
            root[i] = i;
            size[i] = 1;
        }
        for(int i = 0; i < network.length; i++)
        {
            int a = network[i][0], b = network[i][1];
            union(a, b);
        }
        // cost 기준 오름차순 정렬
        Arrays.sort(repair, new CustomSort());
        for(int i = 0; i < repair.length; i++)
        {
            int a = repair[i][0], b = repair[i][1], cost = repair[i][2];
            if(find(a) != find(b))
            {
                union(a, b);
                answer += cost;
            }
        }

        // 모두 연결이 가능한지 체크
        for(int i = 1; i <= n; i++)
        {
            if(find(1) != find(i)) return -1;
        }
        return answer;
    }
}