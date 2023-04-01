-- 코드를 입력하세요
SELECT year(sales_date) as YEAR, month(sales_date) as MONTH, gender, count(distinct user_id) as USERS
from user_info natural join online_sale
where gender is not NULL
group by year(sales_date), month(sales_date), gender
order by YEAR, MONTH, gender