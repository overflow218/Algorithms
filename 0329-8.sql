-- 코드를 입력하세요
SELECT s1.user_id, nickname, amount
from used_goods_user s1, (select writer_id as id, sum(price) as amount
from used_goods_board
where status = 'DONE'
group by writer_id
having sum(price) >= 700000) as rich
where s1.user_id = rich.id
order by amount

