-- 코드를 입력하세요
SELECT s2.animal_id, s2.name
from animal_ins s1 right outer join animal_outs s2 on s1.animal_id = s2.animal_id
where s1.animal_id is NULL
order by s2.animal_id