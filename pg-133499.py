def check(word):
    possible_word = ["aya", "ye", "woo", "ma"]
    while(len(word) > 0):
        isDone = True
        for possible in possible_word:
            if(word.startswith(possible)):
                if(word[len(possible):].startswith(possible)):
                    return False
                isDone = False
                word = word[len(possible):]
                break
        if(isDone): return False
    return True
        

def solution(babbling):
    return len(list(filter(check, babbling)))