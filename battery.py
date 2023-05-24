import re

counter = [0] * 100
counter[0] = 1
with open('tmp.txt') as file:
    with open('output_005.txt', 'a') as result:
        parsed_lines = file.readlines()
        result.writelines(str(len(parsed_lines) - 1) + '\n')
        # print(len(parsed_lines) - 1)
        for line in parsed_lines[1:]:
            numbers = re.findall(r'\d+', line)
            numbers = [int(number) for number in numbers]
            # print(numbers)
            if(len(numbers) == 3):
                idx, left, val = numbers[0], numbers[1], numbers[2]
                counter[idx] = val
                # print(f"{counter[left]} {counter[left]}")
                result.write(f"{counter[left]} {counter[left]}\n")
            if(len(numbers) == 4):
                idx, left, right, val = numbers[0], numbers[1], numbers[2], numbers[3]
                counter[idx] = val
                # print(f"{counter[left]} {counter[right]}")    
                result.write(f"{counter[left]} {counter[right]}\n")