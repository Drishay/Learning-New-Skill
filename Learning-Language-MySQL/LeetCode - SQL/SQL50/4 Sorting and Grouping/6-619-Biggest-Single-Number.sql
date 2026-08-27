# Write your MySQL query statement below
-- SELECT num, COUNT(num)
-- FROM MyNumbers
-- GROUP BY num;
/*
| num | COUNT(num) |
| --- | ---------- |
| 8   | 2          |
| 3   | 2          |
| 1   | 1          |
| 4   | 1          |
| 5   | 1          |
| 6   | 1          |
*/

-- SELECT num
-- FROM MyNumbers
-- GROUP BY num
-- HAVING COUNT(num) = 1;
/*
| num |
| --- |
| 1   |
| 4   |
| 5   |
| 6   |
*/

SELECT max(num) as num
FROM (SELECT num
FROM MyNumbers
GROUP BY num
HAVING COUNT(num) = 1) as max_num;

/*
| num |
| --- |
| 6   |
*/