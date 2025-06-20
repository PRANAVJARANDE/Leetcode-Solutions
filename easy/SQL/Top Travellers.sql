SELECT u.name as name ,
CASE 
    WHEN SUM(r.distance) IS NULL THEN 0
    ELSE SUM(r.distance) 
END as travelled_distance 
FROM Rides as r 
RIGHT JOIN Users as u on u.id=r.user_id
GROUP BY r.user_id
ORDER BY travelled_distance DESC , u.name ASC
