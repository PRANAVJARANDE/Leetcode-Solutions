WITH 
pos AS (
    SELECT patient_id, MIN(test_date) AS first_positive
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
nexneg AS (
    SELECT c.patient_id, p.first_positive, MIN(c.test_date) AS first_negative
    FROM covid_tests c
    JOIN pos p ON c.patient_id = p.patient_id
    WHERE c.result = 'Negative' AND c.test_date > p.first_positive
    GROUP BY c.patient_id, p.first_positive
)
SELECT 
    t.patient_id, 
    pt.patient_name, 
    pt.age, 
    DATEDIFF(t.first_negative, t.first_positive) AS recovery_time
FROM nexneg t
JOIN patients pt ON pt.patient_id = t.patient_id
ORDER BY recovery_time, pt.patient_name;
