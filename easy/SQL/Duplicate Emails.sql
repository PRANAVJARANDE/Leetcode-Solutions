SELECT DISTINCT p.email as Email 
FROM Person as p
WHERE (SELECT COUNT(*) FROM PERSON as t WHERE t.email=p.email)>=2
