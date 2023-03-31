-- 코드를 입력하세요
SELECT product_id, product_name, sum(price * amount) as TOTAL_SALES
from food_product s1 natural join food_order s2
where produce_date like "2022-05%"
group by product_id
order by sum(price * amount) desc, product_id