with recursive hours as (
    select 0 as HOUR
    union all
    select HOUR + 1 from hours
    where HOUR < 23
)
select s1.HOUR, coalesce(COUNT, 0) as COUNT
from hours s1 left outer join (SELECT hour(datetime) as HOUR, count(*) as COUNT
from animal_outs group by hour(datetime)) s2 on s1.HOUR = s2.HOUR