WITH 
temp1 as (
    SELECT u.product_id,u.units,
    (
        SELECT COALESCE(MAX(price),0) 
        FROM Prices 
        WHERE product_id=u.product_id AND start_date<=purchase_date AND purchase_date<=end_date
    ) AS price
    FROM UnitsSold as u
)
SELECT product_id,round(SUM(units*price)/SUM(units),2) AS average_price 
FROM temp1
group by product_id
union 
SELECT p.product_id , 0 AS average_price
FROM Prices  as p 
WHERE (SELECT count(product_id) FROM UnitsSold WHERE p.product_id=product_id)=0
