-- 코드를 입력하세요
select car_id, ROUND(avg(TIMESTAMPDIFF(DAY, start_date, end_date) + 1), 1) as average_duration
from car_rental_company_rental_history
group by car_id
having ROUND(avg(TIMESTAMPDIFF(DAY, start_date, end_date) + 1), 1) >= 7
order by ROUND(avg(TIMESTAMPDIFF(DAY, start_date, end_date) + 1), 1) desc, car_id desc