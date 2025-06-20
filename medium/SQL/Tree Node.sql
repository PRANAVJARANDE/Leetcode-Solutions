SELECT t.id as id ,
CASE
    WHEN t.p_id IS NULL THEN "Root"
    WHEN (SELECT count(id) FROM Tree WHERE p_id=t.id)=0 THEN "Leaf"
    ELSE "Inner"
END AS Type
FROM Tree as t
