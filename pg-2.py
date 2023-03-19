def solution(cap, n, deliveries, pickups):
    answer = 0
    while(len(deliveries) > 0 and deliveries[-1] == 0):
        deliveries.pop()
    while(len(pickups) > 0 and pickups[-1] == 0):
        pickups.pop()
    while(len(deliveries) > 0 or len(pickups) > 0):
        answer += 2 * max(len(deliveries), len(pickups))
        tmp = cap
        while(tmp >= 0 and len(deliveries) > 0):
            if(tmp >= deliveries[-1]):
                tmp -= deliveries[-1]
                deliveries.pop()
            else:
                deliveries[-1] -= tmp
                break
                
        tmp = cap
        while(tmp >= 0 and len(pickups) > 0):
            if(tmp >= pickups[-1]):
                tmp -= pickups[-1]
                pickups.pop()
            else:
                pickups[-1] -= tmp
                break
    return answer