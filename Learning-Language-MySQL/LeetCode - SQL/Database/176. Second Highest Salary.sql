# Write your MySQL query statement below
SELECT 
MAX(Salary) AS SecondHighestSalary
FROM (SELECT * FROM Employees WHERE salary<MAX(salary));

-- Every derived table must have its own alias

SELECT 
MAX(b.salary) AS SecondHighestSalary
FROM (SELECT * FROM Employee WHERE salary<MAX(salary)) AS b;

-- Invalid use of group function
-- The Problem: Your original inner query (WHERE salary < MAX(salary)) tried to filter rows using MAX(). SQL filters rows before it 
-- calculates aggregates, so it does not know what the maximum salary is at that point.

SELECT 
    MAX(b.salary) AS SecondHighestSalary
FROM (
    SELECT * 
    FROM Employee 
    WHERE salary < (SELECT MAX(salary) FROM Employee)
) AS b;

-- Your approach uses a Subquery (Derived Table) inside the FROM clause. Your query executes everything all at once in a single block 
-- of code


-- Method 1: Using a VIEW (Most Common)
CREATE VIEW LowerSalaries AS
SELECT * 
FROM Employees 
WHERE salary < (SELECT MAX(salary) FROM Employees);

SELECT MAX(salary) AS SecondHighestSalary 
FROM LowerSalaries;


-- -- Method 2: Using a Temporary Table
CREATE TEMPORARY TABLE TempLowerSalaries AS
SELECT * 
FROM Employees 
WHERE salary < (SELECT MAX(salary) FROM Employees);

SELECT MAX(salary) AS SecondHighestSalary 
FROM TempLowerSalaries;

-- Your friend's approach explicitly saves the intermediate step first, making the final SELECT look much cleaner and easier to read

 