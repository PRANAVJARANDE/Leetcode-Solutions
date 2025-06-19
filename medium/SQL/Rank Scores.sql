SELECT s.score, (SELECT COUNT(DISTINCT e.score) + 1  FROM Scores AS e WHERE e.score > s.score) AS `rank`
FROM Scores AS s
ORDER BY `rank` ASC;
