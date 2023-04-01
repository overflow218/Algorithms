# -- 코드를 입력하세요
select apnt_no, pt_name, s1.pt_no, s2.mcdp_cd, dr_name, apnt_ymd
from patient s1, doctor s2, (select * from appointment where mcdp_cd = 'CS' and apnt_ymd like "2022-04-13%" and apnt_cncl_yn = 'N') s3
where s1.pt_no = s3.pt_no and s2.dr_id = s3.mddr_id
order by apnt_ymd
