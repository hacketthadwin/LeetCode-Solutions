# Write your MySQL query statement below
-- select *,(select count(distinct player_id) from Activity),count(*), round(count(*)/(select count(distinct player_id) from Activity),2) as fraction 
-- from
-- (select a1.player_id
-- from Activity a1
-- left join Activity a2
-- on a1.player_id =a2.player_id 
-- where datediff(a2.event_date,a1.event_date)=1
-- group by a1.player_id) tabl
select round(count(*)/(select count(distinct player_id) from Activity),2) as fraction 
from Activity
where (player_id,DATE_SUB(event_date, INTERVAL 1 DAY)) in (select player_id,min(event_date)
from Activity
group by player_id)