-- 코드를 입력하세요
select s1.category, max_price, product_name
from food_product s1, (SELECT category, max(price) as max_price
from food_product
where category in ('과자', '국', '김치', '식용유')
group by category) s2
where s1.category = s2.category and s1.price = max_price
order by max_price desc
