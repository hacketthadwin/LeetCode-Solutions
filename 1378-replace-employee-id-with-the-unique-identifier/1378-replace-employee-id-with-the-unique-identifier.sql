# Write your MySQL query statement below
-- this will use left join since there is every value of left table but not right
SELECT e.name,eid.unique_id
FROM Employees e
LEFT JOIN
EmployeeUNI eid
ON e.id=eid.id