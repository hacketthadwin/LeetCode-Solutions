

SELECT tabl.product_id, COALESCE(ROUND(tabl.curr_avg/tabl.total_units,2),0) AS average_price
FROM
(SELECT p.product_id, SUM(p.price*u.units) AS curr_avg ,SUM(u.units) AS total_units
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id=u.product_id AND u.purchase_date >=p.start_date AND u.purchase_date<=p.end_date
GROUP BY p.product_id) tabl

