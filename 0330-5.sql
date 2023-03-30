# -- 코드를 입력하세요
select s1.user_id, nickname, concat(city, " ", street_address1, " ", street_address2) as 전체주소, concat(left(tlno, 3), "-", substring(tlno, 4, 4), "-", right(tlno, 4)) as TLNO
from used_goods_user s1, (SELECT user_id
from used_goods_board s1 join used_goods_user s2 on writer_id = user_id
group by user_id
having count(*) >= 3) s2
where s1.user_id = s2.user_id
order by s1.user_id desc