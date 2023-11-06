#include <set>
using namespace std;
// leetcode 1845번
class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
        {
            s.insert(i);
        }
    }
    
    int reserve() {
        int seat = *s.begin();
        s.erase(s.begin());
        return seat;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

#include <algorithm>
using namespace std;

// leetcode 1836번
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};
