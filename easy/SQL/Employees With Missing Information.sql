SELECT e.employee_id AS employee_id
FROM Employees as e
LEFT JOIN Salaries as s ON s.employee_id=e.employee_id 
WHERE s.salary IS NULL 
UNION 
SELECT s.employee_id AS employee_id
FROM Salaries as s
LEFT JOIN Employees as e ON s.employee_id=e.employee_id
WHERE e.name IS NULL
ORDER BY employee_id
