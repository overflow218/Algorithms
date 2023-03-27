-- 코드를 입력하세요
SELECT HOUR(datetime) as HOUR, count(*) as COUNT
from animal_outs
where HOUR(datetime) >= 9 and HOUR(datetime) <= 19
group by HOUR(datetime)
order by HOUR(datetime)