WITH 
first_scores AS (
    SELECT student_id, subject, MIN(exam_date) AS first_exam_date
    FROM Scores 
    GROUP BY student_id, subject
),
first_score_values AS (
    SELECT s.student_id, s.subject, s.score AS first_score, s.exam_date
    FROM Scores s
    JOIN first_scores f 
      ON s.student_id = f.student_id 
     AND s.subject = f.subject 
     AND s.exam_date = f.first_exam_date
),
latest_scores AS (
    SELECT student_id, subject, MAX(exam_date) AS latest_exam_date
    FROM Scores 
    GROUP BY student_id, subject
),
latest_score_values AS (
    SELECT s.student_id, s.subject, s.score AS latest_score, s.exam_date
    FROM Scores s
    JOIN latest_scores l 
      ON s.student_id = l.student_id 
     AND s.subject = l.subject 
     AND s.exam_date = l.latest_exam_date
)
SELECT 
    f.student_id,
    f.subject,
    f.first_score,
    l.latest_score
FROM first_score_values f
JOIN latest_score_values l 
  ON f.student_id = l.student_id 
 AND f.subject = l.subject
WHERE f.exam_date <> l.exam_date  
  AND l.latest_score > f.first_score
ORDER BY f.student_id, f.subject;
