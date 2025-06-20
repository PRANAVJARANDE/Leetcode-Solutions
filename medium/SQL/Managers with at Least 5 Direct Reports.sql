SELECT e.name as name 
FROM Employee as e
WHERE  ( 
    SELECT COUNT(id)
    FROM Employee 
    WHERE managerId=e.id
)>=5

