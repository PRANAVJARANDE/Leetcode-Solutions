SELECT c.user_id as user_id, ROUND((SELECT COUNT(time_stamp) FROM Confirmations WHERE user_id=c.user_id AND action="confirmed") /COUNT(c.time_stamp),2) AS confirmation_rate 
FROM Confirmations as c
GROUP BY c.user_id
UNION 
SELECT s.user_id as user_id, 0.00 as confirmation_rate
FROM Signups AS s
WHERE (SELECT COUNT(time_stamp) FROM Confirmations where user_id=s.user_id)=0
