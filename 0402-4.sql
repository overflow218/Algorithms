-- 코드를 입력하세요
select s1.flavor
from (select flavor, total_order from first_half) s1, (select flavor, sum(total_order) as total_order from july group by flavor) s2
where s1.flavor = s2.flavor
order by s1.total_order + s2.total_order desc
limit 3