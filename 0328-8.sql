-- 코드를 입력하세요
SELECT ingredient_type, sum(total_order)
from first_half natural join icecream_info
group by ingredient_type
order by sum(total_order)