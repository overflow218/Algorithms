class Solution {
public:
    void visit(vector<vector<int>>& rooms, vector<bool> &isVisited, int idx)
    {
        if(isVisited[idx]) return;
        isVisited[idx] = true;
        for(int i = 0; i < rooms[idx].size(); i++)
        {
            visit(rooms, isVisited, rooms[idx][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> isVisited (rooms.size(), false);
        visit(rooms, isVisited, 0);
        for(int i = 0; i < isVisited.size(); i++)
        {
            if(!isVisited[i]) return false;
        }
        return true;
    }
};