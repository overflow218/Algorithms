def solution(cap, n, deliveries, pickups):
    answer = 0
    delivery_idx, pickup_idx = n - 1, n - 1
    while(delivery_idx >= 0):
        if(deliveries[delivery_idx] == 0):
            delivery_idx -=1
        else:
            break
    while(pickup_idx >= 0):
        if(pickups[pickup_idx] == 0):
            pickup_idx -=1
        else:
            break
    while(delivery_idx >= 0 or pickup_idx >= 0):
        print(f'탐색 del {delivery_idx + 1}, pick {pickup_idx + 1}')
        # 맨처음에 시작하는거 아니고 맨 뒤칸이 비어있는 상황에서 불필요하게 방문하게 되어버리네 ㄷㄷ...
        answer += max(delivery_idx, pickup_idx) + 1
        del_cap, pick_cap = cap, cap
        while(del_cap >= 0 and delivery_idx >= 0):
            if(deliveries[delivery_idx] <= del_cap):
                del_cap -= deliveries[delivery_idx]
                deliveries[delivery_idx] = 0
                delivery_idx -= 1
            else:
                if(deliveries[delivery_idx] == 0):
                    delivery_idx -= 1
                    continue
                deliveries[delivery_idx] -= del_cap
                del_cap = 0
                break

        while(pick_cap >= 0 and pickup_idx >= 0):
            if(pickups[pickup_idx] <= pick_cap):
                pick_cap -= pickups[pickup_idx]
                pickups[pickup_idx] = 0
                pickup_idx -= 1
            else:
                if(pickups[pickup_idx] == 0): 
                    pickup_idx -= 1
                    continue
                pickups[pickup_idx] -= pick_cap
                pick_cap = 0
                break

    return answer * 2