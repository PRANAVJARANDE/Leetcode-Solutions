WITH temp as (
    SELECT book_id , COUNT(record_id) as cnt 
    FROM borrowing_records 
    WHERE return_date is NULL
    GROUP BY book_id
)
SELECT l.book_id,l.title,l.author,l.genre,l.publication_year,l.total_copies as current_borrowers 
FROM library_books AS l 
JOIN temp as t1 ON t1.book_id=l.book_id
WHERE l.total_copies=t1.cnt
ORDER BY current_borrowers DESC ,l.title   
