# Write your MySQL query statement below
select person_name
from
(select *, SUM(weight) OVER (ORDER BY turn) as cumulative_sum
from Queue)tabl
where tabl.cumulative_sum<=1000 
order by tabl.cumulative_sum desc
limit 1

-- when you require row wise cumulative sum, use SUM(weight) OVER (ORDER BY turn)