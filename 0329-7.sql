-- 코드를 입력하세요
SELECT s1.food_type, rest_id, rest_name, s1.favorites
from rest_info s1, (select food_type, max(favorites) as fav from rest_info group by food_type) s2
where s1.food_type = s2.food_type and s1.favorites = s2.fav
order by s1.food_type desc