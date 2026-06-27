# Write your MySQL query statement below
SELECT tabl.name, tabl.bonus FROM
(SELECT e.empId,b.bonus,e.name FROM Employee e
LEFT JOIN Bonus b
ON e.empId=b.empId) tabl
WHERE tabl.bonus<1000  OR tabl.bonus IS NULL 