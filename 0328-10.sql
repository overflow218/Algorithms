-- 코드를 입력하세요
SELECT distinct s1.user_id, s1.product_id
from online_sale s1, online_sale s2
where s1.user_id = s2.user_id and s1.product_id = s2.product_id and s1.sales_date != s2.sales_date
order by s1.user_id, s1.product_id desc