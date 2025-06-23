with temp1 as (
    SELECT machine_id,process_id, ABS(MAX(`timestamp`)-MIN(`timestamp`)) as`tm`
    FROM Activity 
    GROUP BY machine_id,process_id
)
SELECT machine_id, ROUND(AVG(tm),3) as processing_time
FROM temp1
GROUP BY machine_id
