SELECT u.unique_id ,e.name
FROM Employees as e
LEFT JOIN EmployeeUNI AS u ON e.id=u.id
