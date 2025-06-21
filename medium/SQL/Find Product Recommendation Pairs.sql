SELECT 
t1.product_id AS product1_id,
t2.product_id AS product2_id,
t1.category AS product1_category,
t2.category AS product2_category,
COUNT(DISTINCT pp1.user_id) AS customer_count
FROM ProductInfo AS t1
JOIN ProductInfo AS t2 ON t1.product_id < t2.product_id
JOIN ProductPurchases AS pp1 ON pp1.product_id = t1.product_id
JOIN ProductPurchases AS pp2 ON pp2.product_id = t2.product_id AND pp1.user_id = pp2.user_id
GROUP BY t1.product_id, t2.product_id, t1.category, t2.category
HAVING COUNT(DISTINCT pp1.user_id) >= 3
ORDER BY customer_count DESC, product1_id, product2_id;
