-- # Write your MySQL query statement below
-- select * 
-- from
-- (select tabl.managerId,tabl.name
-- from
-- (select e1.managerId,e1.name,e1.id, count(e1.managerId) as cnt
-- from Employee e1
-- group by e1.managerId) tabl
-- where tabl.cnt>=5) tabl2
-- inner join Employee e2
-- on e2.managerId=tabl2.managerId

select e1.name
from Employee e1
inner join Employee e2
on e1.id=e2.managerId
group by e2.managerId
having count(e2.managerId)>=5