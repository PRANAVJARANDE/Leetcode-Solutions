SELECT DISTINCT s.name 
FROM SalesPerson as s
WHERE s.sales_id NOT IN(
    SELECT o.sales_id 
    FROM Orders as o
    JOIN Company as c
    ON c.com_id=o.com_id
    WHERE c.name='RED'
)
