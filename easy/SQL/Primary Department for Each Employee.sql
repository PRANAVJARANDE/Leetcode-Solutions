SELECT employee_id ,department_id 
FROM Employee 
WHERE primary_flag="Y"
UNION 
SELECT e.employee_id ,e.department_id 
FROM Employee as e
WHERE e.primary_flag="N" and (SELECT count(department_id) FROM Employee where e.employee_id=employee_id)=1
