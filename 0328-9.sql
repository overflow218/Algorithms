-- 코드를 입력하세요
select truncate(price, -4) as PRICE_GROUP, count(*) as PRODUCTS
from product
group by truncate(price, -4)
order by truncate(price, -4)