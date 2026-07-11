/*
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT
      IF(N>(SELECT COUNT(*) FROM Employee), null, (SELECT salary FROM Employee order by salary DESC LIMIT 1 OFFSET N)) as getNthHighestSalary 
      FROM Employee
  );
END
*/
-- many syntax errors.

/*
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;

    RETURN (
        SELECT IF(
            N >= (SELECT COUNT(DISTINCT Salary) FROM Employee),
            NULL,
            (
                SELECT DISTINCT Salary
                FROM Employee
                ORDER BY Salary DESC
                LIMIT 1 OFFSET N
            )
        )
    );
END
*/
-- gpt, helped, to correct my query

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;

    RETURN (
        SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET N
    );
END