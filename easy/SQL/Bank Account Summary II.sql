SELECT u.name,SUM(t.amount) as balance
FROM Transactions as t
join Users as u 
ON u.account=t.account
GROUP BY t.account 
having SUM(t.amount)>10000
