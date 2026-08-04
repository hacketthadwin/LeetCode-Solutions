# Write your MySQL query statement below
select friend_id as id,count(*) as num
from 
(select requester_id as friend_id
from RequestAccepted
union all
select accepter_id as friend_id
from RequestAccepted) tabl
group by tabl.friend_id
order by count(*) desc
limit 1