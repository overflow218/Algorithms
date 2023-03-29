-- 코드를 입력하세요
SELECT category, sum(sales) as total_sales
from book natural join book_sales
where sales_date like "2022-01%"
group by category
order by category