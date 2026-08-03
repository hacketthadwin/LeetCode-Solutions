# Write your MySQL query statement below
select e1.employee_id,e1.name,count(*) as reports_count, round(avg(e2.age)) as average_age
from Employees e1
left join Employees e2
on e1.employee_id=e2.reports_to
-- on e1.employee_id=e2.employee_id
where e2.reports_to is not null
group by e1.employee_id
order by e1.employee_id

-- | employee_id | name    | reports_to | age | employee_id | name    | reports_to | age  |
-- | ----------- | ------- | ---------- | --- | ----------- | ------- | ---------- | ---- |
-- | 1           | Michael | null       | 45  | 3           | Bob     | 1          | 42   |
-- | 1           | Michael | null       | 45  | 2           | Alice   | 1          | 38   |
-- | 2           | Alice   | 1          | 38  | 5           | David   | 2          | 40   |
-- | 2           | Alice   | 1          | 38  | 4           | Charlie | 2          | 34   |
-- | 3           | Bob     | 1          | 42  | 6           | Eve     | 3          | 37   |
-- | 4           | Charlie | 2          | 34  | null        | null    | null       | null |
-- | 5           | David   | 2          | 40  | null        | null    | null       | null |
-- | 6           | Eve     | 3          | 37  | null        | null    | null       | null |
-- | 7           | Frank   | null       | 50  | null        | null    | null       | null |
-- | 8           | Grace   | null       | 48  | null        | null    | null       | null |