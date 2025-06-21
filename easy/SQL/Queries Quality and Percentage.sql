SELECT q.query_name,
    ROUND(AVG(q.rating/q.`position`),2) as quality,
    ROUND(((SELECT COUNT(*) FROM Queries WHERE query_name=q.query_name and rating<3)/(SELECT COUNT(*) FROM Queries WHERE query_name=q.query_name)*100),2) AS poor_query_percentage 
FROM Queries as q
group by q.query_name
