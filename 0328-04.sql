-- 코드를 입력하세요
SELECT product_code,  sum(sales_amount) * price as SALES
from product natural join offline_sale
group by product_code
order by sum(sales_amount) * price desc,  product_code