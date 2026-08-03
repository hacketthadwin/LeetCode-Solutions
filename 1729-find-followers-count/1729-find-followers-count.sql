# Write your MySQL query statement below
select user_id,count(*) as followers_count
from Followers
group by user_id
order by user_id

-- number of groups -> subquery
-- number of element in each group -> count(*)