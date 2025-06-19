SELECT max(s.salary) as SecondHighestSalary 
FROM Employee as s
WHERE s.salary NOT IN (SELECT max(salary) FROM EMPLOYEE)
ORDER BY s.salary DESC
LIMIT 1
