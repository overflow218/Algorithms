# # -- 코드를 입력하세요
select author_id, author_name, category, sum(total_sales) as TOTAL_SALES
from (select book_id, author_id, category, author_name
from book natural join author) s1, (SELECT book.book_id, sum(sales * price) as total_sales from book_sales, book where sales_date like "2022-01%" and book_sales.book_id = book.book_id group by (book.book_id)) s2
where s1.book_id = s2.book_id
group by author_id, category
order by author_id, category desc