-- 코드를 입력하세요
SELECT rest_id, rest_name, food_type, favorites, address, round(avg(review_score), 2) as SCORE
from rest_info natural join rest_review
where address like "서울%"
group by rest_id
order by round(avg(review_score), 3) desc, favorites desc