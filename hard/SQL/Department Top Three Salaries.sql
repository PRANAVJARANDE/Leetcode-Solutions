SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary 
FROM Employee AS e
JOIN Department AS d ON e.departmentId = d.id
WHERE e.salary >= (
    SELECT MIN(salary)
    FROM (
        SELECT DISTINCT salary 
        FROM Employee 
        WHERE departmentId = e.departmentId 
        ORDER BY salary DESC 
        LIMIT 3
    ) AS top3
);
