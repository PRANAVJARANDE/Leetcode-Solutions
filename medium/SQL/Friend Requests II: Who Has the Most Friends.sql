WITH 
temp1 AS (
    SELECT requester_id AS id, COUNT(*) AS cnt1
    FROM RequestAccepted
    GROUP BY requester_id
),
temp2 AS (
    SELECT accepter_id AS id, COUNT(*) AS cnt2
    FROM RequestAccepted
    GROUP BY accepter_id
),
friends AS ( 
    SELECT a.id AS id, COALESCE(a.cnt1, 0) + COALESCE(b.cnt2, 0) AS num
    FROM temp1 AS a
    LEFT JOIN temp2 AS b ON a.id = b.id

    UNION

    SELECT b.id AS id, COALESCE(a.cnt1, 0) + COALESCE(b.cnt2, 0) AS num
    FROM temp2 AS b
    LEFT JOIN temp1 AS a ON a.id = b.id
),
maxi AS (
    SELECT MAX(num) AS max_num
    FROM friends
)

SELECT f.id, f.num
FROM friends AS f, maxi
WHERE f.num = maxi.max_num;
