# Write your MySQL query statement below
-- SELECT Employee.id, Employee.name, salary, Department.name AS department
-- FROM Employee
-- LEFT JOIN Department
-- ON Employee.departmentId = Department.id
-- ORDER BY department ASC, salary DESC;

/*
| id | name  | salary | department |
| -- | ----- | ------ | ---------- |
| 4  | Max   | 90000  | IT         |
| 1  | Joe   | 85000  | IT         |
| 6  | Randy | 85000  | IT         |
| 7  | Will  | 70000  | IT         |
| 5  | Janet | 69000  | IT         |
| 2  | Henry | 80000  | Sales      |
| 3  | Sam   | 60000  | Sales      |
*/

-- Now, Find the top 3 distinct salaries in each department, including all employees who share those salaries.
-- Get the top 3 unique salaries per department, including ties.

-- FOR the solution - USE DENSE_RANK() : DENSE_RANK() is a SQL window function that assigns a rank to each row 
-- based on a value, without skipping rank numbers when there are ties.

-- The key idea
-- Same salary → same rank.
-- Next different salary → next rank.



-- SELECT 
--     Employee.id, 
--     Employee.name,
--     salary, 
--     Department.name AS department, 
--     DENSE_RANK() OVER (PARTITION BY Department.name ORDER BY salary DESC) AS salary_rank
-- FROM Employee
-- LEFT JOIN Department
-- ON Employee.departmentId = Department.id
-- ORDER BY department ASC, salary DESC;

/*
| id | name  | salary | department | salary_rank |
| -- | ----- | ------ | ---------- | ----------- |
| 4  | Max   | 90000  | IT         | 1           |
| 1  | Joe   | 85000  | IT         | 2           |
| 6  | Randy | 85000  | IT         | 2           |
| 7  | Will  | 70000  | IT         | 3           |
| 5  | Janet | 69000  | IT         | 4           |
| 2  | Henry | 80000  | Sales      | 1           |
| 3  | Sam   | 60000  | Sales      | 2           |
*/


-- Not using CTE, feeling like to use SUBQUERIES

SELECT department, name as Employee, salary
FROM 
(
    SELECT 
    Employee.id, 
    Employee.name,
    salary, 
    Department.name AS department, 
    DENSE_RANK() OVER (PARTITION BY Department.name ORDER BY salary DESC) AS salary_rank
    FROM Employee
    LEFT JOIN Department
    ON Employee.departmentId = Department.id
    ORDER BY department ASC, salary DESC
) as d
WHERE salary_rank <=3;