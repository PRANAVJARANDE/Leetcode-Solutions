SELECT c.name as Customers 
FROM Customers as c
WHERE c.id NOT IN 
(
    SELECT DISTINCT o.customerId 
    from Orders as o
)
