-- 코드를 입력하세요
SELECT title, s1.board_id, reply_id, s2.writer_id, s2.contents, date_format(s2.created_date, '%Y-%m-%d')
from used_goods_board s1 join used_goods_reply s2 on s1.board_id = s2.board_id
where date_format(s1.created_date, '%Y-%m') = '2022-10'
order by s2.created_date, title
