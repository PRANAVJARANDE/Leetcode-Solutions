SELECT person_name 
FROM Queue
WHERE turn=(
    SELECT MAX(q.turn)
    FROM Queue as q
    WHERE (SELECT SUM(weight) FROM Queue WHERE turn<=q.turn)<=1000
)
