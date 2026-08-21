# Write your MySQL query statement below
WITH table1 as
(
    SELECT Project.project_id as project_id, Project.employee_id as employee_id, Employee.experience_years as experience_years
    FROM Project
    LEFT JOIN Employee
    ON Project.employee_id = Employee.employee_id
)

SELECT project_id, ROUND(AVG(experience_years),2) AS average_years
FROM table1
GROUP BY project_id;