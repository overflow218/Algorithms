#hh:mm 형식을 분단위로 리턴
def convertToNumber(time):
    return int(time[:2]) * 60 + int(time[3:])

def solution(m, musicinfos):
    answer = ''
    answer_length = 0
    aTon = {'C': 'a', 'C#': 'b', 'D': 'c', 'D#': 'd', 'E': 'e', 'F': 'f', 'F#': 'g', 'G': 'h', 'G#': 'i', 'A': 'j', 'A#': 'k', 'B': 'l'}

    input_melody = []
    for c in m:
        if(c == '#'):
            input_melody[-1] = input_melody[-1] + c
        else:
            input_melody.append(c)
    parsed_input = ''.join([aTon[i] for i in input_melody if i in aTon])

    for info in musicinfos:
        start, end, title, value = info.split(',')
        length = convertToNumber(end) - convertToNumber(start)
        melody = []
        for c in value:
            if(c == '#' and len(melody) > 0):
                melody[-1] = melody[-1] + c
            else:
                melody.append(c)
        parsed_melody = [aTon[i] for i in melody if i in aTon]
        # song_length = len(melody)
        song_length = len(parsed_melody)
        current_melody = ''
        if(len(parsed_melody) < song_length):
            return 0
        for i in range(length):
            current_melody += parsed_melody[i % song_length]
        if(parsed_input in current_melody):
            if(answer_length < length):
                answer_length = length
                answer = title
    return answer if answer_length > 0 else '(None)'