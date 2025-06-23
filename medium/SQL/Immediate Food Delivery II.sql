WITH temp1 as (
    SELECT customer_id,MIN(order_date) as order_date
    FROM Delivery 
    GROUP BY customer_id
),
temp2 as (
    SELECT t1.customer_id,t1.order_date,d.customer_pref_delivery_date 
    from temp1 as t1
    JOIN Delivery as d ON t1.customer_id=d.customer_id and d.order_date=t1.order_date
    WHERE t1.order_date=d.customer_pref_delivery_date 
)

SELECT round(((SELECT count(customer_id) FROM temp2)/(SELECT count(customer_id) FROM temp1))*100,2) as immediate_percentage 
