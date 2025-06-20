WITH 
cancelled AS (
    SELECT t.request_at as divas, COUNT(t.id) as Cancellations
    FROM Trips AS t 
    JOIN Users as d ON d.users_id=t.driver_id
    JOIN Users as c ON c.users_id=t.client_id
    WHERE d.banned="No" AND c.banned="No" AND t.status!="completed" 
    GROUP BY t.request_at
),
total AS (
    SELECT t.request_at as divas, COUNT(t.id) as Total
    FROM Trips AS t 
    JOIN Users as d ON d.users_id=t.driver_id
    JOIN Users as c ON c.users_id=t.client_id
    WHERE d.banned="No" AND c.banned="No"
    GROUP BY t.request_at
)

SELECT t.divas as `Day`,
CASE
 WHEN ROUND(c.Cancellations/t.Total,2) IS NULL THEN 0
 ELSE ROUND(c.Cancellations/t.Total,2) 
END AS `Cancellation Rate`
FROM total as t
LEFT JOIN cancelled as c ON c.divas=t.divas  
WHERE "2013-10-01"<=t.divas AND t.divas<="2013-10-03"

