# Write your MySQL query statement below
select class
from Courses
group by class
HAVING count(distinct student)>=5