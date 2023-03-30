-- 코드를 입력하세요
select id, name, s1.host_id
from places s1, (SELECT HOST_ID
from places
group by host_id
having count(*) > 1) s2
where s1.host_id = s2.host_id
order by id