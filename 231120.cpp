/*
leetcode 2391번

이게 최솟값이래서 뭔가 달라질거처럼 써놨는데, 사실 보면은 각 트럭이 걸리는 시간은 독립적임. 
어차피 다른거 움직일때 다른 하나는 못움직이니까 각각 걸리는 시간 구해서 더해주면 되는둡
*/
class Solution {
public:

    int convert(char c)
    {
        if(c == 'M') return 0;
        if(c == 'P') return 1;
        return 2;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        vector<int> vec = vector<int>(3, -1);
        vector<int> pSum = {travel[0]};

        for(int i = 1; i < travel.size(); i++)
        {
            pSum.push_back(pSum.back() + travel[i]);
        }

        for(int i = 0; i < garbage.size(); i++)
        {
            ans += garbage[i].size();
            // metal, paper, glass
            bool isOn[3] = {false, false, false};
            for(char &c: garbage[i])
            {
                isOn[convert(c)] = true;;
            }
            if(isOn[0]) vec[0] = i;
            if(isOn[1]) vec[1] = i;
            if(isOn[2]) vec[2] = i;
        }

        for(int i = 0; i < 3; i++)
        {
            if(vec[i] > 0) ans += pSum[vec[i] - 1];
        }
        return ans;
    }
};
