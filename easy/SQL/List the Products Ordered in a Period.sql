SELECT p.product_name,SUM(o.unit) as unit
FROM Orders as o
join Products as p on p.product_id=o.product_id
WHERE MONTH(o.order_date)=2 and YEAR(o.order_date)=2020
GROUP BY o.product_id
HAVING SUM(o.unit)>=100
