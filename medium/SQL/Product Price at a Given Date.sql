WITH 
last_update_date AS (
    SELECT product_id,MAX(change_date) as last_update
    FROM Products 
    WHERE change_date<="2019-08-16"
    group by product_id
),
unq_prod AS (
    SELECT DISTINCT product_id
    FROM Products
)
SELECT u.product_id ,
    COALESCE(p.new_price, 10) AS price
FROM unq_prod AS u
LEFT JOIN last_update_date AS l ON l.product_id=u.product_id 
LEFT JOIN Products as p ON p.product_id=u.product_id AND l.last_update=p.change_date
