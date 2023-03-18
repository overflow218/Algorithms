from collections import deque

edge = [[] for i in range(15)]
edge[0] = [1]
edge[1] = [2, 10]
edge[2] = [3]
edge[3] = [4, 7]
edge[4] = [5, 6]
edge[5] = [7]
edge[6] = [3]
edge[7] = [8, 9]
edge[8] = [9]
edge[9] = [1]
edge[10] = [11]
edge[11] = [12, 14]
edge[12] = [13]
edge[13] = [11]

q = deque([[i] for i in range(15)])
stage = 0
candidate = []
while(len(q) > 0):
    # print(f'stage -> {stage}')
    stage += 1
    limit = len(q)
    for _ in range(limit):
        tmp = q.popleft()
        # print(tmp)
        # 종료점 이거나 루프면 이제 종료
        if(tmp[-1] == 14 or (len(tmp) > 1 and tmp[0] == tmp[-1])):
            candidate.append(tmp)
            continue

        for next in edge[tmp[-1]]:
            if(next not in tmp or (next in tmp and next == tmp[0])):
                q.append(tmp[::] + [next])
            
# print(candidate)
candidate.sort(key = lambda x: len(x))
for i in candidate:
    print(i)

prime_path = []

for i in range(len(candidate)):
    isGood = True
    for j in range(i + 1, len(candidate)):
        if(candidate[i][0] not in candidate[j]):
            continue
        idx = candidate[j].index(candidate[i][0])
        if(candidate[j][idx:] == candidate[i]):
            isGood = False
            break
    if(isGood):
        prime_path.append(candidate[i])
print(f"총 {len(candidate)}개의 후보가 있음")
print(f"진짜 primePath는 {len(prime_path)}")
for p in prime_path:
    print(p)