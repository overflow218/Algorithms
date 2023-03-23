def solution(n, k):
    answer = -1
    
    # 소수인지 체크
    def isPrime(n):
        limit = int(n ** 0.5)
        if(n == 1): return False
        if(n == 2): return True
        for i in range(2, limit + 1):
            if(n % i == 0):
                return False
        return True
    # n을 k진수로 변환하기
    def convert(n, k):
        ho = ''
        while(n != 0):
            ho = str(n % k) + ho
            n //= k
        return ho
    parsed = convert(n, k)
    parsed = parsed.split('0')
    ho = [int(x) for x in parsed if x != '']
    ho = list(filter(isPrime, ho))
    return len(ho)