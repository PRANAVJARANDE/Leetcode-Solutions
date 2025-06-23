WITH 
r31 as (
    SELECT employee_id,MAX(review_date) as d3
    FROM performance_reviews
    GROUP BY employee_id
),
r3 as (
    SELECT e1.employee_id,e1.d3,e2.rating
    FROM r31 as e1
    JOIN performance_reviews as e2 on e1.d3=e2.review_date and e1.employee_id=e2.employee_id
),
r21 as (
    SELECT t1.employee_id,MAX(t1.review_date) as d2
    FROM performance_reviews as t1
    JOIN r3 as t2 ON t2.employee_id=t1.employee_id
    WHERE t1.review_date<t2.d3 
    GROUP BY employee_id
),
r2 as (
    select e1.employee_id,e1.d2,e2.rating
    FROM r21 as e1
    JOIN performance_reviews as e2 on e1.d2=e2.review_date and e1.employee_id=e2.employee_id
),
r11 as (
    SELECT t1.employee_id,MAX(t1.review_date) as d1
    FROM performance_reviews as t1
    JOIN r2 as t2 ON t2.employee_id=t1.employee_id
    WHERE t1.review_date<t2.d2
    GROUP BY employee_id
),
r1 as (
    select e1.employee_id,e1.d1,e2.rating
    FROM r11 as e1
    JOIN performance_reviews as e2 on e1.d1=e2.review_date and e1.employee_id=e2.employee_id
)

select t3.employee_id,e.name,ABS(t1.rating-t3.rating) as improvement_score
FROM r1 as t3
JOIN employees as e on e.employee_id=t3.employee_id
JOIN r2 as t2 on t3.employee_id=t2.employee_id
join r3 as t1 on t3.employee_id=t1.employee_id
WHERE t1.rating>t2.rating and t2.rating>t3.rating
ORDER BY improvement_score DESC,e.name
