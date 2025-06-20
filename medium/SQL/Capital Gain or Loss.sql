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
