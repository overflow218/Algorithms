def solution(fees, records):    
    # t1 < t2라고 가정
    def get_time(t1, t2):
        c1 = int(t1[:2]) * 60 + int(t1[3:])
        c2 = int(t2[:2]) * 60 + int(t2[3:])
        return c2 - c1
    
    basic_time, basic_cost, unit_time, unit_cost = fees
    # 자동차별로 총 주차시간 나타냄
    check = {}
    # 주차장임. 마지막에 입차한 시간 나타냄
    parking = {}
    
    def get_cost(car):
        total_time = check[car]
        total_cost = basic_cost
        total_time -= basic_time
        if(total_time > 0):
            total_cost += ((total_time + unit_time - 1) // unit_time) * unit_cost
        return total_cost
    
    for record in records:
        t, car, oper = record.split()
        # 입차
        if(oper == 'IN'):
            if(car not in check):
                check[car] = 0
            parking[car] = t
        # 출차
        else:
            park_time = get_time(parking[car], t)
            check[car] += park_time
            del parking[car]
    
    for car in parking:
        park_time = get_time(parking[car], '23:59')
        check[car] += park_time
    
    answer = sorted(list(check.keys()))
    answer = [get_cost(car) for car in answer]
        
    return answer