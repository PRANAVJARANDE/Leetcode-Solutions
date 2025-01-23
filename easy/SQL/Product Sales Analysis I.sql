SELECT p.product_name,s.year,s.price
FROM Sales as s,Product as p
WHERE p.product_id=s.product_id
