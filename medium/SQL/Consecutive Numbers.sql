SELECT DISTINCT l.num as ConsecutiveNums 
FROM Logs as l
WHERE l.num=(SELECT MAX(num) FROM Logs WHERE id=l.id+1) AND l.num=(SELECT MAX(num) FROM Logs WHERE id=l.id+2)   
