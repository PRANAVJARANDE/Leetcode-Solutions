WITH temp1 as (
    SELECT t1.user_id,t2.category
    from ProductPurchases as t1
    JOIN ProductInfo AS t2 ON t1.product_id=t2.product_id 
)
SELECT c1.category as category1,c2.category as category2,count(distinct c1.user_id) as customer_count 
FROM temp1 AS c1
JOIN temp1 as c2 ON c1.category<c2.category 
WHERE c1.user_id=c2.user_id
GROUP BY category1,category2
having count(distinct c1.user_id)>=3
order by customer_count DESC, category1,category2
