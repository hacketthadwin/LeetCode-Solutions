# Write your MySQL query statement below
-- this may use the lag thing..i can build a table with lag thing...then i will check if current temperature is higher than last day
SELECT tabl.id
FROM
(SELECT id,temperature,LAG(temperature) OVER(ORDER BY recordDate) AS prev_temp,recordDate, LAG(recordDate) OVER(ORDER BY recordDate) AS prev_date
FROM Weather
) tabl
WHERE DATEDIFF(tabl.recordDate,tabl.prev_date)=1 AND  tabl.temperature>tabl.prev_temp