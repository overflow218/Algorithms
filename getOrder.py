import heapq
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        new_tasks = sorted([ (tasks[i][0], tasks[i][1],i )for i in range(len(tasks))])
        time, idx = 1, 0
        heap = []
        ans = []
        while(len(ans) < len(new_tasks)):
            while(idx < len(new_tasks) and new_tasks[idx][0] <= time):
                heapq.heappush(heap, (new_tasks[idx][1], new_tasks[idx][2]))
                idx += 1
            if(heap):
                tmp = heapq.heappop(heap)
                ans.append(tmp[1])
                time += tmp[0]
            else:
                if(idx < len(new_tasks)):
                    time = new_tasks[idx][0]
        return ans