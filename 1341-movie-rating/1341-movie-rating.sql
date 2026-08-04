# Write your MySQL query statement below
select *
from
(select name as results
from
(select user_id,count(*) as cnt
from MovieRating m
group by user_id)tabl
left join
Users u
on u.user_id=tabl.user_id
order by tabl.cnt desc,name asc
limit 1)tabl1

union all

select *
from
(select title as results
from
(select movie_id,AVG(rating) as avg_rate
from MovieRating m
where '2020-02-01'<=created_at and '2020-02-29'>=created_at
group by movie_id)tabl
left join
Movies m
on m.movie_id=tabl.movie_id
order by tabl.avg_rate desc,title asc
limit 1)tabl2
