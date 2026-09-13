# Write your MySQL query statement below
WITH table1 AS
(
    SELECT 
        id, 
        num, 
        LAG(num, 1) OVER (ORDER BY id) AS cons1, 
        LAG(num, 2) OVER (ORDER BY id) AS cons2
    FROM Logs
)
-- SELECT num as ConsecutiveNums
-- FROM Table1
-- WHERE (num = cons1 AND num = cons2);
/*
Wrong Answer
19 / 23 testcases passed

Editorial
Input
Logs =
| id | num |
| -- | --- |
| 1  | 3   |
| 2  | 3   |
| 3  | 3   |
| 4  | 3   |

Use Testcase
Output
| ConsecutiveNums |
| --------------- |
| 3               |
| 3               |
Expected
| ConsecutiveNums |
| --------------- |
| 3               |
*/ 
-- thus, USING DISTINICT
SELECT DISTINCT num as ConsecutiveNums
FROM Table1
WHERE (num = cons1 AND num = cons2);