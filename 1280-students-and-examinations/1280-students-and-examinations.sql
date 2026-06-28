-- Write your PostgreSQL query statement below
-- this will use coalase too..as for null values..we will fill it with 0
-- so first i will have to do is for each student...make a table for each subject...then for each student id i will need to count its occurence for each subject...then will need to join it..and for null values...i will replace null values with 0..this is my approach for this
-- NOW I JUST NEED TO FIND COUNT FOR EACH, so i will do group by
SELECT tabl1.student_id,tabl1.student_name,tabl1.subject_name,COALESCE(tabl2.attended_exams, 0) AS attended_exams
FROM
(SELECT * 
FROM Students st
CROSS JOIN
Subjects sb
ORDER BY st.student_id) tabl1
LEFT JOIN
(
SELECT *, COUNT(e.student_id) AS attended_exams 
FROM Examinations e
GROUP BY e.subject_name,e.student_id
ORDER BY e.subject_name
) tabl2
ON tabl1.student_id=tabl2.student_id
AND tabl1.subject_name=tabl2.subject_name
ORDER BY tabl1.student_id,tabl1.subject_name ASC
