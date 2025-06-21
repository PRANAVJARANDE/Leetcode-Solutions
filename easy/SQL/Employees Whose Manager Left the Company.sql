SELECT e.employee_id
FROM Employees as e
WHERE e.salary<30000 AND (e.manager_id IS NOT NULL) AND (SELECT COUNT(employee_id) from Employees WHERE employee_id=e.manager_id)=0
order by e.employee_id
