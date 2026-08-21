-- 1

# Write your MySQL query statement below
-- SELECT emp.name as Employee
-- FROM Employees as emp
-- LEFT JOIN Employes as man
--     ON emp.managerId = man.id
-- WHERE emp.salary > man.salary;

SELECT emp.name AS Employee
FROM Employee AS emp
JOIN Employee AS man
    ON emp.managerId = man.id
WHERE emp.salary > man.salary;


-- 2
# Write your MySQL query statement below
SELECT emp.name as Employee
FROM Employee as emp
LEFT JOIN Employee as man
    ON emp.managerId = man.id
WHERE emp.salary > man.salary;

-- SELECT emp.name AS Employee
-- FROM Employee AS emp
-- JOIN Employee AS man
--     ON emp.managerId = man.id
-- WHERE emp.salary > man.salary;