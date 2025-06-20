SELECT a.activity_date as `day` , COUNT(DISTINCT a.user_id) as active_users 
FROM Activity as a 
WHERE DATE_SUB("2019-07-27",INTERVAL 29 DAY)<=a.activity_date AND a.activity_date<="2019-07-27"
GROUP BY a.activity_date
