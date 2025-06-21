WITH temp1 as (
    SELECT 
    CASE
        WHEN 3<=MONTH(s.sale_date) AND MONTH(s.sale_date)<=5 THEN "Spring"
        WHEN 6<=MONTH(s.sale_date) AND MONTH(s.sale_date)<=8 THEN "Summer"
        WHEN 9<=MONTH(s.sale_date) AND MONTH(s.sale_date)<=11 THEN "Fall"
        ELSE "Winter"
    END AS season,
    p.category ,
    sum(s.quantity) as total_quantity ,
    sum(s.quantity*s.price) as total_revenue
    FROM sales as s
    JOIN products as p ON p.product_id=s.product_id
    GROUP BY season,category
)

(SELECT * 
FROM temp1 
WHERE season="Fall"
ORDER BY total_quantity DESC, total_revenue DESC
LIMIT 1)
UNION
(SELECT * 
FROM temp1 
WHERE season="Winter"
ORDER BY total_quantity DESC, total_revenue DESC
LIMIT 1)
UNION
(SELECT * 
FROM temp1 
WHERE season="Summer"
ORDER BY total_quantity DESC, total_revenue DESC
LIMIT 1)
UNION
(SELECT * 
FROM temp1 
WHERE season="Spring"
ORDER BY total_quantity DESC, total_revenue DESC
LIMIT 1)
ORDER BY season
