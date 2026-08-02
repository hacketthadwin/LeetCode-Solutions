# Write your MySQL query statement below
select r.contest_id,COALESCE(round(count(*) * 100/(select count(user_id) from Users ),2),0.00) as percentage 
from Users u
left join Register r
on u.user_id=r.user_id
where r.contest_id is not null
group by r.contest_id
order by percentage desc, contest_id asc
