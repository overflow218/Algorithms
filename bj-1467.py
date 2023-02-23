a = input()
b = input()

arr = [int(i) for i in a]
toDelete = [0 for i in range(10)]

for n in b:
    toDelete[int(n)] += 1

for target in range(9, -1, -1):
    if(toDelete[target] == 0): 
        continue
    while(toDelete[target] > 0):
        print(f"target {target} 남은거 {toDelete[target]}")
        print("시작", arr)
        lastIdx = -1
        removeLast = True # 맨 마지막꺼 삭제해야하는지 체크

        #뒤에 target보다 큰게 올 수 있는경우를 체크 
        for i in range(len(arr)):
            if(arr[i] != target):
                continue
            lastIdx = i
            needed = [0 for i in range(10)]
            needed[target] = 1
            FROM, TO = i, i
            for j in range(i + 1, len(arr), 1):
                if(arr[j] > target):
                    # needed를 모두 제거할 수 있는지 체크
                    isGood = True
                    for k in range(10):
                        if(needed[k] > toDelete[k]):
                            isGood = False
                    if(isGood):
                        TO = j
                    break
                else:
                    needed[arr[j]] += 1
            # FROM ~ TO - 1 까지를 날려버릴거임.
            if(FROM != TO):
                for j in range(10):
                    toDelete[j] -= needed[j]
                print("이거를 없앰", arr[FROM:TO])
                arr = arr[:FROM] + arr[TO:]
                removeLast = False
                break
        
        # # 이미 하나 줄였으면 다시 처음부터
        # if(not removeLast):
        #     continue
        # # 뒤에 큰게 올수 없다면 동순위가 오는 경우가 있는지 체크
        # for i in range(len(arr)):
        #     if(arr[i] != target):
        #         continue
        #     lastIdx = i
        #     needed = [0 for i in range(10)]
        #     needed[target] = 1
        #     FROM, TO = i, i
        #     for j in range(i + 1, len(arr), 1):
        #         if(arr[j] == target):
        #             # needed를 모두 제거할 수 있는지 체크
        #             isGood = True
        #             for k in range(10):
        #                 if(needed[k] > toDelete[k]):
        #                     isGood = False
        #             if(isGood):
        #                 TO = j
        #             break
        #         else:
        #             needed[arr[j]] += 1
        #     # FROM ~ TO - 1 까지를 날려버릴거임.
        #     if(FROM != TO):
        #         cnt = TO - FROM
        #         a = arr[:FROM] + arr[TO:]
        #         a2 = ''.join([str(n) for n in a])
        #         b = arr[:TO] + arr[TO + cnt:]
        #         b2 = ''.join([str(n) for n in b])
        #         if(a2 < b2):
        #             for j in range(10):
        #                 toDelete[j] -= needed[j]
        #             print("동순위인데 이거 날림", arr[FROM:TO])
        #             arr = arr[:FROM] + arr[TO:]
        #             removeLast = False
        #             break

        if(removeLast):
            arr = arr[:lastIdx] + arr[lastIdx + 1:]
            toDelete[target] -= 1
        print("동작후", arr)

print(''.join([str(n) for n in arr]))