def solution(numbers):
    answer = []
    ho = [1, 3, 7, 15, 31, 63, 100]
    def check(s):
        if(len(s) == 1):
            return True
        mid = len(s) // 2
        if(s[mid] == '1'):
            return check(s[:mid]) and check(s[mid + 1:])
        return s == '0'* len(s)
    
    for num in numbers:
        binary = bin(num)[2:]
        if(len(binary) % 2 == 0):
            binary = '0' + binary
        for i in range(len(ho)):
            if(ho[i] < len(binary)): continue
            needed = ho[i] - len(binary)
            binary = '0' * needed + binary
            if(binary[len(binary) // 2] == '0'):
                answer.append(0)
                break
            answer.append(1 if check(binary) else 0)
            # print(f"num: {num} -> bin: {binary} {len(binary)}")
            break
    return answer