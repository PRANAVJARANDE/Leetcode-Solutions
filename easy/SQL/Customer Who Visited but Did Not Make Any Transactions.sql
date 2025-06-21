SELECT v.customer_id ,COUNT(v.visit_id) as count_no_trans
FROM Visits as v
WHERE (SELECT COUNT(transaction_id) from Transactions WHERE visit_id=v.visit_id)=0
GROUP BY v.customer_id
