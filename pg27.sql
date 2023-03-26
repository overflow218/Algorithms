-- 코드를 입력하세요
SELECT history_id, car_id, date_format(start_date, '%Y-%m-%d') as START_DATE, date_format(end_date, '%Y-%m-%d') as END_DATE, case 
    when TIMESTAMPDIFF(DAY, start_date, end_date) >= 29
    then '장기 대여'
    else '단기 대여' end as RENT_TYPE
from car_rental_company_rental_history
where date_format(start_date, '%Y-%m') = '2022-09'
order by history_id desc