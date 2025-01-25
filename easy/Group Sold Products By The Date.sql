SELECT a.sell_date as sell_date,
       COUNT(a.product) as num_sold,
       GROUP_CONCAT(DISTINCT a.product ORDER BY a.product) as products
FROM (SELECT DISTINCT sell_date,product FROM Activities) as a
GROUP BY a.sell_date;
