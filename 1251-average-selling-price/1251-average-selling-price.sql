# Write your MySQL query statement below
SELECT  a.product_id,COALESCE(ROUND(sum(a.price*b.units)/sum(b.units),2),0) as average_price FROM 
Prices as a LEFT JOIN UnitsSold as b
ON a.product_id=b.product_id
AND  b.purchase_date BETWEEN a.start_date AND a.end_date
GROUP BY a.product_id 

