SELECT user_id,MAX(time_stamp) as last_stamp 
FROM Logins 
WHERE "2020-01-01 00:00:00"<=time_stamp and time_stamp<="2020-12-31 23:59:59"
GROUP BY user_id
