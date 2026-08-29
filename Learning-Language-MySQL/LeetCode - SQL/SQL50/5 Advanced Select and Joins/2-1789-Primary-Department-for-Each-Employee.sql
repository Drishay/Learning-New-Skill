# Write your MySQL query statement below
-- SELECT employee_id, department_id
-- FROM Employee
-- GROUP BY employee_id
-- HAVING count(department_id) = 1;
/*
| employee_id | department_id |
| ----------- | ------------- |
| 1           | 1             |
| 3           | 3             |
*/

-- SELECT employee_id, department_id
-- FROM Employee
-- WHERE primary_flag = 'Y';

/*
| employee_id | department_id |
| ----------- | ------------- |
| 2           | 1             |
| 4           | 3             |
*/

# HERE, I to merge these two tables, using union
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING count(department_id) = 1

UNION

SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'

ORDER BY employee_id;

/*
NOTES:

1. WHERE filters individual rows BEFORE GROUP BY.
Example:
WHERE primary_flag = 'Y'

2. GROUP BY groups rows based on one or more columns.
Example:
GROUP BY employee_id

3. HAVING filters groups AFTER GROUP BY.
Example:
HAVING COUNT(department_id) = 1

4. HAVING is mainly used with aggregate functions
such as COUNT(), SUM(), AVG(), MAX(), MIN().

5. ENUM columns can be compared normally:
WHERE primary_flag = 'Y'

6. UNION combines the results of two SELECT queries.
Both SELECTs must return the same number of columns
with compatible data types.

7. ORDER BY after UNION sorts the FINAL combined result.
Example:
ORDER BY employee_id

8. General SQL execution idea:
FROM → WHERE → GROUP BY → HAVING → SELECT → UNION → ORDER BY

*/

/* less time, solution
select a.employee_id, a.department_id
from 
(SELECT 
  *, 
  COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount 
FROM 
  Employee) a
  where a.EmployeeCount = 1 OR a.primary_flag = "Y";

*/