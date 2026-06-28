-- Write your PostgreSQL query statement below
SELECT e.name
FROM 
Employee e
JOIN
(SELECT managerId, COUNT(managerId) AS cnt
FROM
Employee
GROUP BY managerId
) tabl1
ON e.id=tabl1.managerId
WHERE tabl1.managerId=e.id AND tabl1.cnt>=5
