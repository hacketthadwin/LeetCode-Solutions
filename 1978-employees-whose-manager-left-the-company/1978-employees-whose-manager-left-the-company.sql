# Write your MySQL query statement below
select employee_id
from Employees
where not manager_id in (
    select employee_id from Employees
) and salary<30000 
order by employee_id