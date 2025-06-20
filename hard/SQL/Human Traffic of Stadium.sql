WITH 
temp AS (
    SELECT * 
    FROM Stadium 
    WHERE people>=100
)

SELECT DISTINCT s.id,s.visit_date,s.people
FROM temp as s
WHERE 
((SELECT COUNT(id) FROM temp WHERE id=s.id+1 OR id=s.id+2)=2) 
OR
((SELECT COUNT(id) FROM temp WHERE id=s.id+1 OR id=s.id-1)=2)
OR
((SELECT COUNT(id) FROM temp WHERE id=s.id-1 OR id=s.id-2)=2)
ORDER BY visit_date 
