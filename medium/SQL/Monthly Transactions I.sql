WITH temp1 as (
    SELECT SUBSTRING(trans_date,1,7) AS `month`,country,COUNT(id) AS trans_count,SUM(amount)  as trans_total_amount 
    FROM Transactions 
    GROUP BY `month`,country
),
temp2 as (
    SELECT SUBSTRING(trans_date,1,7) AS `month`,country,COUNT(id) AS approved_count ,SUM(amount) as approved_total_amount  
    FROM Transactions 
    WHERE state="approved"
    GROUP BY `month`,country
    
)
SELECT t1.`month`,t1.country,t1.trans_count,COALESCE(t2.approved_count,0) AS approved_count,t1.trans_total_amount,COALESCE(t2.approved_total_amount,0) AS approved_total_amount
FROM temp1 as t1
left JOIN temp2 as t2 on t1.`month`=t2.`month` and t1.country<=>t2.country
