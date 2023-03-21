def solution(commands):
    root = [i for i in range(2501)]
    cell = ['' for i in range(2501)]
    answer = []
    def convert(x, y):
        return (x - 1) * 50 + y
    
    def find(x):
        if(x == root[x]):
            return x
        root[x] = find(root[x])
        return root[x]
    
    def union(x, y):
        x = find(x)
        y = find(y)
        root[y] = x
        
    for command in commands:
        parsed = command.split()
        if(parsed[0] == 'UPDATE'):
            # UPDATE v1 v2
            if(len(parsed) == 3):
                v1, v2 = parsed[1], parsed[2]
                update_list = []
                for i in range(1, 2501):
                    if(cell[find(i)] == v1):
                        update_list.append(i)
                for i in update_list:
                    cell[i] = v2
            # UPDATE r c value
            else:
                r, c, value = int(parsed[1]), int(parsed[2]), parsed[3]
                idx = find(convert(r, c))
                cell[idx] = value
        elif(parsed[0] == 'MERGE'):
            # MERGE r1 c1 r2 c2 
            r1, c1, r2, c2 = int(parsed[1]), int(parsed[2]), int(parsed[3]), int(parsed[4])
            v = cell[find(convert(r1, c1))]
            if(len(v) == 0):
                v = cell[find(convert(r2, c2))]
            union(convert(r1, c1), convert(r2, c2))
            cell[find(convert(r1, c1))] = v
        elif(parsed[0] == 'UNMERGE'):
            # UNMBERGE r1 c1
            r1, c1 = int(parsed[1]), int(parsed[2])
            idx = find(convert(r1, c1))
            val = cell[idx]
            update_list = []
            for i in range(1, 2501):
                if(find(i) == idx):
                    update_list.append(i)
            for i in update_list:
                root[i] = i
                cell[i] = ''
            cell[convert(r1, c1)] = val
        else:
            # PRINT r c
            r1, c1 = int(parsed[1]), int(parsed[2])
            val = cell[find(convert(r1, c1))]
            if(len(val) == 0):
                val = 'EMPTY'
            answer.append(val)
    return answer