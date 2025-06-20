SELECT ROUND(SUM(p.tiv_2016),2) as tiv_2016 
FROM Insurance AS p
WHERE (

    SELECT COUNT(pid) 
    FROM Insurance
    WHERE tiv_2015=p.tiv_2015 
    
)>=2 AND (

    SELECT COUNT(pid) 
    FROM Insurance
    WHERE lat=p.lat AND lon=p.lon
)=1
