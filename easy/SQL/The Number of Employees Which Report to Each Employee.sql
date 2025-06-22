SELECT e.reports_to as employee_id , t1.name , COUNT(e.employee_id) as reports_count , round(avg(e.age),0) as average_age 
FROM Employees as e
JOIN Employees as t1 ON t1.employee_id=e.reports_to 
GROUP BY e.reports_to 
order by e.reports_to
