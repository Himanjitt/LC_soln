CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
    ifNULL((SELECT DISTINCT salary 
    FROM employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET N),NULL)
  );
END