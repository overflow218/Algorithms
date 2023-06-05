/*
dy1 / dx1 = dy2 / dx2 인거니까 
dx1 * dy2 = dy1 * dx2 인거 하면 됨.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];

        for(int i = 1; i < coordinates.size(); i++)
        {
            int tx = coordinates[i][0] - coordinates[0][0];
            int ty = coordinates[i][1] - coordinates[0][1];
            if(tx * dy != ty * dx) return false;
        }
        return true;
    }
};