SELECT d.name as Department , e.name as Employee , e.salary as Salary 
FROM Employee as e
JOIN Department as d ON d.id=e.departmentId
WHERE e.salary=(SELECT MAX(salary) FROM Employee WHERE departmentId=e.departmentId)
