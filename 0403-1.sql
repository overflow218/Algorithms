select member_name, review_text, date_format(review_date, "%Y-%m-%d") as REVIEW_DATE
from rest_review natural join member_profile
where member_id in (select member_id
from rest_review
group by member_id
having count(review_id) >= all (SELECT count(review_id) from rest_review group by member_id)
)
order by review_date, review_text