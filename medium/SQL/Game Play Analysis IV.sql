WITH 
d0_login AS (
    SELECT player_id,MIN(event_date) as event_date
    FROM Activity 
    GROUP BY player_id
),
d1_login AS (
    SELECT a.player_id
    FROM Activity as a 
    JOIN d0_login as d0 ON d0.player_id=a.player_id
    AND a.event_date=DATE_ADD(d0.event_date,INTERVAL 1 DAY)
)

SELECT ROUND( COUNT(DISTINCT d1.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction 
FROM d1_login as d1
