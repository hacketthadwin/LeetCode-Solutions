# Write your MySQL query statement below
select class
from Courses
group by class
HAVING count(distinct student)>=5

-- in aggregate functions use having otherwise use where