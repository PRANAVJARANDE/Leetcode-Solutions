SELECT "Low Salary" as category , COALESCE(COUNT(account_id),0) as accounts_count 
FROM Accounts 
WHERE income<20000
UNION
SELECT "High Salary" as category ,  COALESCE(COUNT(account_id),0) as accounts_count 
FROM Accounts 
WHERE income>50000
UNION
SELECT "Average Salary" as category ,  COALESCE(COUNT(account_id),0) as accounts_count 
FROM Accounts 
WHERE 20000<=income AND income<=50000
