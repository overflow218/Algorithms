-- 코드를 입력하세요
select month(start_date) as MONTH, s1.car_id as CAR_ID, count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY s1, (SELECT car_id
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(start_date) between 8 and 10
group by car_id
having count(*) >= 5) s2
where s1.car_id = s2.car_id and month(start_date) between 8 and 10
group by month(start_date), s1.car_id
order by MONTH, s1.car_id desc