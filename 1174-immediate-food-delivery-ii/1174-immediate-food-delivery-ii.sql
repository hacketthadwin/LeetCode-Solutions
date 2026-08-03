# Write your MySQL query statement below
select round(sum(order_date=customer_pref_delivery_date)/(select count(distinct customer_id) from Delivery)*100,2) as immediate_percentage 
from Delivery
where (customer_id,order_date) in (select customer_id,min(order_date) as first
from Delivery
group by customer_id)
-- where argument me jitna rhega...utna hi andar wale select statement se pass krega
