SELECT s.id ,
CASE
    WHEN s.id%2=1 AND (SELECT count(id) from Seat Where id=s.id+1)=0 THEN s.student
    WHEN s.id%2=1 THEN (SELECT MIN(student) from seat where id=s.id+1)
    ELSE (SELECT MIN(student) from seat where id=s.id-1)
END AS student 
FROM Seat as s
