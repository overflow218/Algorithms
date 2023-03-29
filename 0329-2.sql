select s1.animal_id, s1.name
from animal_ins s1 join animal_outs s2 on s1.animal_id = s2.animal_id
where s1.datetime > s2.datetime
order by s1.datetime