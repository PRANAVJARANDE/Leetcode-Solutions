SELECT t.id,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Jan") AS Jan_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Feb") AS Feb_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Mar") AS Mar_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Apr") AS Apr_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="May") AS May_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Jun") AS Jun_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Jul") AS Jul_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Aug") AS Aug_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Sep") AS Sep_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Oct") AS Oct_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Nov") AS Nov_Revenue,
(SELECT SUM(revenue) FROM Department WHERE t.id=id and `month`="Dec") AS Dec_Revenue
FROM Department as t 
GROUP BY t.id
