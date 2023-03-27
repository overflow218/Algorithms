def solution(s):
    answer = ''
    
    while(s != ''):
        if(s[0].isdigit()):
            answer += s[0]
            s = s[1:]
        else:
            if(s[0] == 'z'):
                answer += '0'
                s = s[4:]
                continue
            if(s[0] == 'o'):
                answer += '1'
                s = s[3:]
                continue
            if(s[0] == 'e'):
                answer += '8'
                s = s[5:]
                continue
            if(s[0] == 'n'):
                answer += '9'
                s = s[4:]
                continue
            if(s[0] == 't'):
                if(s[1] == 'w'):
                    answer += '2'
                    s = s[3:]
                else:
                    answer += '3'
                    s = s[5:]
                continue
            if(s[0] == 'f'):
                if(s[1] == 'o'):
                    answer += '4'
                    s = s[4:]
                else:
                    answer += '5'
                    s = s[4:]
                continue
            if(s[0] == 's'):
                if(s[1] == 'i'):
                    answer += '6'
                    s = s[3:]
                else:
                    answer += '7'
                    s = s[5:]
                continue    
    return int(answer)