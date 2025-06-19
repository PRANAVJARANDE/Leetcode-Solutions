SELECT e.name as Employee 
FROM Employee as e
LEFT JOIN Employee as m on m.id=e.managerId
WHERE m.salary<e.salary
