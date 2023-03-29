-- 코드를 입력하세요
SELECT order_id, product_id, date_format(out_date, "%Y-%m-%d"), case
    when out_date is NULL then "출고미정"
    when month(out_date) < 5 then "출고완료"
    when month(out_date) = 5 and day(out_date) = 1 then "출고완료"
    else "출고대기" end as '출고여부'
from food_order
order by order_id