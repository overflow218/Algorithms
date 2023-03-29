-- 코드를 입력하세요
SELECT s1.car_id
from car_rental_company_car s1, (select distinct car_id
from car_rental_company_rental_history
where month(start_date) = 10) s2
where s1.car_id = s2.car_id and s1.car_type = '세단'
order by car_id desc
