parent = [i for i in range(2501)]
cell = [None for _ in range(2501)]

def find(a):
    if(a == parent[a]): return a
    parent[a] = find(parent[a])
    return parent[a]

# 기본이랑은 좀 다르게 얘는 무조건 a거 기준으로 합쳐줄거임. 
def union(a, b):
    a = find(a)
    b = find(b)
    parent[b] = a
    
def solution(commands):
    answer = []
    for command in commands:
        parsing = command.split(' ')
        if(parsing[0] == 'UPDATE'):
            if(len(parsing) == 3): # UPDATE value1 value2
                old_value, new_value = parsing[1], parsing[2]
                for i in range(1, 2501):
                    if(cell[i] == old_value):
                        cell[i] = new_value
            else: # UPDATE r c value1
                r, c, value = int(parsing[1]), int(parsing[2]), parsing[3]
                root = find((r - 1) * 50 + c)
                cell[root] = value
        elif(parsing[0] == 'MERGE'): # MERGE r1 c1 r2 c2
            r1, c1, r2, c2 = map(int, parsing[1:])
            if(r1 != r2 or c1 != c2):
                root1 = find((r1 - 1) * 50 + c1)
                root2 = find((r2 - 1) * 50 + c2)
                if(cell[root1] != None):
                    union(root1, root2)
                else:
                    union(root2, root1)

        elif(parsing[0] == 'UNMERGE'):
            r, c = int(parsing[1]), int(parsing[2])
            root = find((r - 1) * 50 + c)
            val = cell[root]
            candidate = []
            for i in range(1, 2501):
                if(find(i) == root):
                    candidate.append(i)

            for i in candidate:
                parent[i] = i
                cell[i] = None

            cell[(r - 1) * 50 + c] = val
        elif(parsing[0] == 'PRINT'):
            r, c = int(parsing[1]), int(parsing[2])
            root = find((r - 1) * 50 + c)
            val = cell[root]
            answer.append(val if val else "EMPTY")

    return answer