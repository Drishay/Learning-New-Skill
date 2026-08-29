# Write your MySQL query statement below

-- SELECT fir.employee_id, fir.name as employee_name, fir.reports_to, sec.name as manger_name, fir.age
-- FROM Employees AS fir
-- LEFT JOIN Employees AS sec
-- ON fir.reports_to = sec.employee_id;
/*
| employee_id | employee_name | reports_to | manger_name | age |
| ----------- | ------------- | ---------- | ----------- | --- |
| 9           | Hercy         | null       | null        | 43  |
| 6           | Alice         | 9          | Hercy       | 41  |
| 4           | Bob           | 9          | Hercy       | 36  |
| 2           | Winston       | null       | null        | 37  |
*/

/*
SELECT fir.reports_to as employee_id, sec.name as name, COUNT(fir.reports_to) as reports_count, ROUND(AVG(fir.age)) AS average_age
FROM Employees AS fir
LEFT JOIN Employees AS sec
ON fir.reports_to = sec.employee_id
GROUP BY name
HAVING employee_id IS NOT null
ORDER BY employee_id;

Test cases ran but failed in submition
*/

-- Wrong Answer: 9 / 24 testcases passed
/*
Input
Employees =
| employee_id | name    | reports_to | age |
| ----------- | ------- | ---------- | --- |
| 5           | Eliyahu | null       | 42  |
| 3           | Michael | 1          | 27  |
| 7           | Tamar   | 1          | 34  |
| 9           | Freida  | 7          | 44  |
| 10          | Tamar   | 8          | 29  |
| 1           | Yehudit | 7          | 47  |
| 4           | Zahava  | null       | 58  |
| 8           | Yaakov  | 10         | 48  |
| 2           | Freida  | null       | 56  |
| 6           | Miriam  | 9          | 39  |

Use Testcase
Output
| employee_id | name    | reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1           | Yehudit | 2             | 31          |
| 7           | Tamar   | 3             | 46          |
| 8           | Yaakov  | 1             | 29          |
| 9           | Freida  | 1             | 39          |

Expected
| employee_id | name    | reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1           | Yehudit | 2             | 31          |
| 7           | Tamar   | 2             | 46          |
| 8           | Yaakov  | 1             | 29          |
| 9           | Freida  | 1             | 39          |
| 10          | Tamar   | 1             | 48          |
*/

-- You were grouping by the manager's name, but names are not guaranteed to be unique.

SELECT fir.reports_to as employee_id, sec.name as name, COUNT(fir.reports_to) as reports_count, ROUND(AVG(fir.age)) AS average_age
FROM Employees AS fir
LEFT JOIN Employees AS sec
ON fir.reports_to = sec.employee_id
GROUP BY fir.reports_to
HAVING fir.reports_to IS NOT null
ORDER BY fir.reports_to;