-- 코드를 입력하세요
SELECT s1.animal_id, s1.name
from animal_ins s1 join animal_outs s2 on s1.animal_id = s2.animal_id
order by s2.datetime - s1.datetime desc
limit 2