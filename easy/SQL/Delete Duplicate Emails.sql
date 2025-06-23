DELETE p from Person as p
JOIN Person as p2 ON p2.email=p.email 
WHERE p2.id<p.id
