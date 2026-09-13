# Write your MySQL query statement below
-- SELECT a.employee_id, a.name, a.manager_id, a.salary, b.name as manager_name
-- FROM Employees as a
-- LEFT JOIN Employees as b
-- ON a.manager_id = b.employee_id;

/*
| employee_id | name      | manager_id | salary | manager_name |
| ----------- | --------- | ---------- | ------ | ------------ |
| 3           | Mila      | 9          | 60301  | Mikaela      |
| 12          | Antonella | null       | 31000  | null         |
| 13          | Emery     | null       | 67084  | null         |
| 1           | Kalel     | 11         | 21241  | Joziah       |
| 9           | Mikaela   | null       | 50937  | null         |
| 11          | Joziah    | 6          | 28485  | null         |
*/

SELECT a.employee_id
FROM Employees as a
LEFT JOIN Employees as b
ON a.manager_id = b.employee_id
WHERE a.salary < 30000 AND a.manager_id IS NOT NULL AND b.name IS NULL
ORDER BY employee_id ;