# Write your MySQL query statement below
select product_id,year as first_year,quantity,price
from Sales
where (product_id,year) in (select product_id,min(year)
from Sales
group by product_id)

-- The year in (product_id, year) belongs to the outer query or the inner query?
--  Answer: It belongs to the outer query.
-- and we cannot use first_year instead of year inside the argument because of order of execution