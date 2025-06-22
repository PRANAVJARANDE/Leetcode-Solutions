WITH temp1 as (
    SELECT user_id,Avg(activity_duration) as free_avg
    FROM UserActivity
    WHERE activity_type="free_trial" 
    GROUP BY user_id
),
temp2 as (
    SELECT user_id,Avg(activity_duration) as paid_avg
    FROM UserActivity 
    WHERE activity_type="paid"
    GROUP BY user_id
)
SELECT t2.user_id,ROUND(t1.free_avg,2) as trial_avg_duration,ROUND(t2.paid_avg,2) as paid_avg_duration 
FROM temp2 as t2
JOIN temp1 as t1 ON t1.user_id=t2.user_id
