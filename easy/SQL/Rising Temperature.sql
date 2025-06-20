SELECT w.id as id
FROM Weather as w
WHERE w.temperature> (SELECT MAX(temperature) FROM Weather WHERE recordDate=DATE_SUB(w.recordDate, INTERVAL 1 DAY))
