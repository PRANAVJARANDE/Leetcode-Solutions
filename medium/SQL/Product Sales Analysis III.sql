WITH 
temp as
(
    SELECT product_id, MIN(`year`) as `year` 
    FROM Sales 
    GROUP BY product_id
)
SELECT s.product_id, s.`year` as first_year,s.quantity,s.price
FROM temp as t
JOIN Sales as s ON s.product_id=t.product_id AND t.`year`=s.`year`
