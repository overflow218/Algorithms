#include <algorithm>
using namespace std;

/*
이게 스냅샷을 찍는건 찍는건데 변한게 없는데도 따로 저장하는건 
용량을 너무 많이 잡아먹는 일이될거임. 그래서 최대한 변화 없는동안에는 유지할 수 있도록 하면 좋을 것 같거든?
이게 달라져야하는건 1. 새롭게 값을 set해줄때와 2. 스냅샷을 새로 찍어줄때임. 
이게 마지막으로 확인한 스냅샷 아이디와 현재 스냅샷 아이디를 둘다 가지고 있어야하는거 아님?
예를 들어 sanp() set(0, 1), set(0, 2), set(0, 3) snap() 이렇게 된다면 
1, 2, 3을 모두 저장할 필요 없이 마지막 3번것만 저장하면 되는건데
*/
class SnapshotArray {
public:
    vector<vector<pair<int, int>>> vec;
    int snapId = -1;
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++)
        {
            vector<pair<int, int>> tmp = {make_pair(-1, 0)};
            vec.push_back(tmp);
        }
    }
    
    void set(int index, int val) {
        // 마지막 스냅샷 이후로 새롭게 추가된 값이 있는 경우 갱신해준다
        if(vec[index].back().first == snapId + 1) vec[index].back().second = val;
        // 마지막 스냅샷 이후로 새롭게 추가된 값이 없는경우 -> 새롭게 추가해준다.
        if(vec[index].back().first < snapId + 1) vec[index].push_back(make_pair(snapId + 1, val));
    }
    
    int snap() {
        return ++snapId;
    }
    
    int get(int index, int snap_id) {
        int idx = lower_bound(vec[index].begin(), vec[index].end(), make_pair(snap_id, -1)) - vec[index].begin();
        if(idx >= vec[index].size()) return vec[index].back().second;
        if(vec[index][idx].first == snap_id) return vec[index][idx].second;
        return vec[index][idx - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */