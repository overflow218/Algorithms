class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        idx, cnt = 0, 0
        diff = [gas[i] - cost[i] for i in range(len(gas))]
        while(cnt < len(gas)):
            if(diff[idx] < 0):
                idx += 1
                cnt += 1
            else:
                tmp_cost = 0
                is_possible = True
                for i in range(len(diff)):
                    tmp_cost += diff[(idx + i) % len(diff)]
                    if(tmp_cost < 0):
                        cnt += i
                        idx = (idx + i) % len(diff)
                        is_possible = False
                        break
                if(is_possible):
                    return idx
        return -1