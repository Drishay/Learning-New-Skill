# Write your MySQL query statement below
-- SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) as rank
-- FROM Scores;
/*
You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'rank
FROM Scores' at line 2

-- The syntax error occurs because RANK is a reserved keyword in MySQL

The Solution
To fix this, you must wrap the alias in backticks (`) or single quotes (') so MySQL treats it as an identifier rather than a keyword.
*/
SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) as `rank`
FROM Scores;