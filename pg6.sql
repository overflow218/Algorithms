-- 코드를 입력하세요
SELECT product_id, product_name, product_cd, category, price
from FOOD_PRODUCT
where price >= (select max(price) from food_product)