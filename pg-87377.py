'''
ax + by + c = 0 가 입력으로 주어짐. 

ax + by + e= 0
cx + dy + f = 0 의 유일한 교점
x = (bf - ed) / (ad - bc)
y = (ec - af) / (ad - bc)
ad - bc == 0 인 경우 평행 or 일치


입력 최대 1000개 
O(n ^ 2)에 찾아야 하는데 충분쓰.
일단 전체 교점들 찾고, 그중에 최대 최소값 구한다음에 string 만들고 
전체 순회하면서 갱신해주면 될 것 같음!
'''

def solution(line):
    meet = [] # 교점들 모아놓은 곳
    for idx1 in range(len(line)):
        for idx2 in range(1, len(line)):
            line1 = line[idx1]
            line2 = line[idx2]
            a, b, e = line1
            c, d, f = line2
            if(a * d - b * c != 0):
                x = (b * f - e * d) / (a * d - b * c)
                y = (e * c - a * f) / (a * d - b * c)
                if(x == int(x) and y == int(y)):
                    meet.append([int(x), int(y)])
    x_cord = [p[0] for p in meet]
    y_cord = [p[1] for p in meet]
    x_min = min(x_cord)
    x_max = max(x_cord)
    y_min = min(y_cord)
    y_max = max(y_cord)
    answer = [['.'] * (x_max - x_min + 1) for i in range(y_max - y_min + 1)]
    for x, y in meet:
        answer[y_max - y][x - x_min] = '*'
    answer = [''.join(line) for line in answer]
    return answer