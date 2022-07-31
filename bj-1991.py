n = int(input())
dic = {}
for i in range(n):
    lis = input().split()
    dic[lis[0]] = [lis[1], lis[2]]

def front(x):
    global dic
    if(x == '.'): return
    print(x, end = "")
    if(x in dic):
        sons = dic[x]
        front(sons[0])
        front(sons[1])

def rear(x):
    global dic
    if(x == '.'): return
    if(x in dic):
        sons = dic[x]
        rear(sons[0])
        rear(sons[1])
    print(x, end = "")

def middle(x):
    global dic
    if(x == '.'): return
    if(x in dic):
        sons = dic[x]
        middle(sons[0])
        print(x, end = "")
        middle(sons[1])
    else:
        print(x, end = "")

front('A')
print()
middle('A')
print()
rear('A')
print()