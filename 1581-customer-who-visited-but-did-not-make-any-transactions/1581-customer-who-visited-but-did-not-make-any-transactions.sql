# Write your MySQL query statement below
-- so what i see here is i need to group and then find the number of transactions..so basically i will say this requires inner join but for those which don't have any visit id in transactions and then aggregate count of each values
-- this one is good for a join problem
SELECT tabl.customer_id,COUNT(tabl.customer_id) AS count_no_trans
FROM
(SELECT v.customer_id AS customer_id, t.transaction_id AS transaction_id
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id=t.visit_id) tabl
WHERE tabl.transaction_id IS NULL
GROUP BY tabl.customer_id
