# Write your MySQL query statement below
-- select category,max(accounts_count) as accounts_count
-- from
-- (SELECT *
-- FROM (
--     SELECT 'Low Salary' AS category, 0 as accounts_count
--     UNION ALL
--     SELECT 'Average Salary' AS category, 0 as accounts_count
--     UNION ALL
--     SELECT 'High Salary' AS category, 0 as accounts_count
-- ) t
-- -- here we created a temporary table and learn the method of creating new table as we were confused how to add those rows which were not present in the second table
-- union

-- select tabl.category,count(*) as accounts_count 
-- from
-- (select "Low Salary" as category,account_id
-- from Accounts
-- where income < 20000
-- union
-- select "Average Salary" as category,account_id
-- from Accounts
-- where income>=20000 and income<=50000
-- union
-- select "High Salary" as category, account_id
-- from Accounts
-- where income > 50000) tabl
-- group by tabl.category
-- )tabl2
-- group by tabl2.category
select "Low Salary" as category,count(income) as accounts_count 
from Accounts
where income < 20000
union
select "Average Salary" as category,count(income) as accounts_count 
from Accounts
where income>=20000 and income<=50000
union
select "High Salary" as category, count(income) as accounts_count 
from Accounts
where income > 50000

-- when you dont use group by fxn then whole table is the group , count function consider all the rows