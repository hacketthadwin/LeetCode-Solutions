# Write your MySQL query statement below

#remember, null is not represented as referee_id=null, instead we use IS NULL for finding null values
SELECT name FROM Customer WHERE referee_id IS NULL OR referee_id!=2;