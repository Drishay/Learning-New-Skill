# Write your MySQL query statement below
-- SELECT Employee.id, Employee.name, salary, Department.name as Department
-- FROM Employee
-- LEFT JOIN Department
-- ON Employee.departmentId = Department.id;
/*
| id | name  | salary | Department |
| -- | ----- | ------ | ---------- |
| 1  | Joe   | 70000  | IT         |
| 2  | Jim   | 90000  | IT         |
| 3  | Henry | 80000  | Sales      |
| 4  | Sam   | 60000  | Sales      |
| 5  | Max   | 90000  | IT         |
*/

-- now, giving ranking using DENSE_RANK
-- SELECT Employee.id, Employee.name, salary, Department.name as Department, 
-- DENSE_RANK() OVER (PARTITION BY Department.name ORDER BY salary DESC) as Salary_Rank
-- FROM Employee
-- LEFT JOIN Department
-- ON Employee.departmentId = Department.id;

/*
| id | name  | salary | Department | Salary_Rank |
| -- | ----- | ------ | ---------- | ----------- |
| 2  | Jim   | 90000  | IT         | 1           |
| 5  | Max   | 90000  | IT         | 1           |
| 1  | Joe   | 70000  | IT         | 2           |
| 3  | Henry | 80000  | Sales      | 1           |
| 4  | Sam   | 60000  | Sales      | 2           |
*/

SELECT Department, name as Employee, Salary
FROM 
(
    SELECT Employee.id, Employee.name, salary, Department.name as Department, 
    DENSE_RANK() OVER (PARTITION BY Department.name ORDER BY salary DESC) as Salary_Rank
    FROM Employee
    LEFT JOIN Department
    ON Employee.departmentId = Department.id
) AS d
WHERE Salary_Rank = 1;


/*
# Write your MySQL query statement below
with cte as 
(
    select d.name as "Name", max(e.salary) as "MaxSalary"
    from Employee e
    join Department d
    on e.departmentId = d.id
    group by d.name
)

select d.name as "Department", e.name as "Employee", e.salary
from Employee e
join Department d
on e.departmentId = d.id
where e.salary = (select cte.MaxSalary from cte where d.name = cte.Name)
*/