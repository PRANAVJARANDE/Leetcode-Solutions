CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        SELECT distinct e.salary
        FROM Employee as e
        WHERE (SELECT COUNT(DISTINCT salary) FROM Employee WHERE salary>=e.salary) = N
  );
END
