# 빈병 a개 = 콜라 b개, 현재 n개 빈병
def solution(a, b, n):
    answer = 0
    while(n >= a):
        new_coke = b * (n // a) 
        answer += b * (n // a)
        n = n % a + new_coke
    return answer