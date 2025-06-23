WITH temp1 as (
    SELECT num 
    FROM MyNumbers 
    GROUP BY num
    HAVING COUNT(num)=1
)
select max(num) as num 
FROM temp1
