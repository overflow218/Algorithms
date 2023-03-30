-- 코드를 입력하세요
select distinct s1.car_id, if(s2.car_id is NULL, "대여 가능", "대여중") as AVAILABILTY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY s1 left outer join (select car_id
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where "2022-10-16" between start_date and end_date)s2 on s1.car_id = s2.car_id
order by car_id desc