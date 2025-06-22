select event_day as `day`,emp_id,sum(out_time)-sum(in_time) as total_time 
FROM Employees
group by event_day,emp_id
