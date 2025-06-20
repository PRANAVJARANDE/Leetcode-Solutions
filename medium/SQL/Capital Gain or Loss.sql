--OPTION 1
SELECT s.stock_name as stock_name,( 
    SELECT SUM(price)
    FROM Stocks
    WHERE s.stock_name=stock_name AND operation="Sell"   
) -( 
    SELECT SUM(price)
    FROM Stocks
    WHERE s.stock_name=stock_name AND operation="Buy" 
) as capital_gain_loss
FROM Stocks as s 
GROUP BY s.stock_name


--OPTION 2
WITH 
selling as (
    SELECT stock_name , SUM(price) as sell_price
    FROM Stocks 
    WHERE operation="Sell"
    GROUP BY stock_name    
),
buying as (
    SELECT stock_name  , SUM(price) as buy_price
    FROM Stocks 
    WHERE operation="Buy"
    GROUP BY stock_name 
)
SELECT s.stock_name , (s.sell_price -  b.buy_price) as capital_gain_loss 
FROM selling as  s
JOIN buying as b on s.stock_name=b.stock_name 
