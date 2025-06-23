WITH temp1 as (
    SELECT visited_on,SUM(amount) as amount
    FROM Customer 
    GROUP BY visited_on
)
SELECT visited_on,(
    SELECT SUM(amount) 
    FROM temp1 
    WHERE DATE_SUB(c.visited_on,INTERVAL 6 DAY)<=visited_on and visited_on<=c.visited_on
)  AS amount,(
    SELECT ROUND(AVG(amount),2) 
    FROM temp1 
    WHERE DATE_SUB(c.visited_on,INTERVAL 6 DAY)<=visited_on and visited_on<=c.visited_on
) as average_amount
FROM temp1 as c
WHERE (
    SELECT COUNT(visited_on) 
    FROM temp1 
    WHERE DATE_SUB(c.visited_on,INTERVAL 6 DAY)<=visited_on and visited_on<=c.visited_on
)=7
