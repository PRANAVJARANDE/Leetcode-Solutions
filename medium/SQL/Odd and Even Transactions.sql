WITH 
temp1 AS (
    SELECT transaction_date , SUM(amount) as odd_sum
    FROM transactions 
    WHERE amount%2=1
    GROUP BY transaction_date
),
temp2 AS (
    SELECT transaction_date , SUM(amount) as even_sum
    FROM transactions 
    WHERE amount%2=0
    GROUP BY transaction_date
)
SELECT t1.transaction_date as transaction_date, COALESCE(t1.odd_sum,0) as odd_sum , COALESCE(t2.even_sum,0) as even_sum
FROM temp1 as t1
LEFT JOIN temp2 as t2 ON t1.transaction_date=t2.transaction_date
union 
SELECT t2.transaction_date as transaction_date, COALESCE(t1.odd_sum,0) as odd_sum , COALESCE(t2.even_sum,0) as even_sum
FROM temp2 as t2
LEFT JOIN temp1 as t1 ON t1.transaction_date=t2.transaction_date
order by transaction_date

