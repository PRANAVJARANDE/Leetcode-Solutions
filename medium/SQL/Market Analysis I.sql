select u.user_id as buyer_id,u.join_date, (
        SELECT COUNT(order_id)
        FROM Orders
        WHERE "2019-01-01"<=order_date AND order_date<="2019-12-31" AND buyer_id=u.user_id
    )  as orders_in_2019
FROM Users as u
