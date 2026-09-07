# Write your MySQL query statement below
WITH table1 AS
(
    SELECT emp1.employee_id, emp1.name, emp1.manager_id, emp1.salary, emp2.name as manager_name
    FROM Employees as emp1
    LEFT JOIN Employees as emp2
    ON emp1.manager_id = emp2.employee_id
)

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

-- SELECT employee_id 
-- FROM table1
-- WHERE (salary < 30000 AND manager_name IS NULL)
-- ORDER BY employee_id;

-- Wrong Answer 4 / 13 testcases passed
/*
Input
Employees =
| employee_id | name   | manager_id | salary |
| ----------- | ------ | ---------- | ------ |
| 18          | Drew   | null       | 41568  |
| 20          | Ronan  | 3          | 65209  |
| 10          | Jaxton | 15         | 96667  |
| 13          | Louie  | 16         | 6801   |
| 17          | Mylah  | 20         | 26540  |
| 21          | Kenia  | 15         | 98690  |
| 7           | Hadley | 6          | 23590  |
| 9           | Hayden | 4          | 90798  |
| 2           | Nixon  | null       | 25560  |
| 8           | Arthur | 11         | 67027  |
| 11          | Brycen | null       | 42570  |
| 3           | Noemi  | null       | 87321  |
| 14          | Hayden | null       | 4123   |
| 19          | Astrid | 20         | 37680  |
View less

Use Testcase
Output
| employee_id |
| ----------- |
| 2           |
| 7           |
| 13          |
| 14          |
Expected
| employee_id |
| ----------- |
| 7           |
| 13          |

*/

SELECT employee_id 
FROM table1
WHERE (salary < 30000 AND manager_id IS NOT NULL AND manager_name IS NULL)
ORDER BY employee_id;

/* other user solution
SELECT sub.employee_id
FROM Employees sub
LEFT JOIN Employees sup
  ON sub.manager_id = sup.employee_id
WHERE sub.salary < 30000
  AND (sup.employee_id IS NULL)
  AND sub.manager_id IS NOT NULL
ORDER BY sub.employee_id
*/