import sys
n = int(input())
s = set()
for i in range(n):
    cmd = sys.stdin.readline().split()
    if(cmd[0] == 'check'):
        tmp = '1' if cmd[1] in s else '0'
        print(tmp)
    elif(cmd[0] == 'add'):
        s.add(cmd[1])
    elif(cmd[0] == 'remove'):
        s.discard(cmd[1])
    elif(cmd[0] == 'toggle'):
        if(cmd[1] in s):
            s.discard(cmd[1])
        else:
            s.add(cmd[1])
    elif(cmd[0] == 'all'):
        s = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20'}
    else:
        s = {}