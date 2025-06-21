WITH 
temp1 AS (
    SELECT u.name as results ,COUNT(movie_id) AS maxi
    FROM MovieRating as m
    JOIN Users as u on u.user_id=m.user_id
    GROUP BY m.user_id
    ORDER BY maxi DESC , u.name ASC
    LIMIT 1
),
temp2 AS (
    SELECT u.title as results ,AVG(m.rating) AS maxi
    FROM MovieRating as m
    JOIN Movies as u on u.movie_id=m.movie_id
    WHERE "2020-02-01"<=m.created_at AND m.created_at<="2020-02-29"
    GROUP BY m.movie_id
    ORDER BY maxi DESC, u.title ASC
    LIMIT 1
)
SELECT results from temp1
union all
SELECT results from temp2
