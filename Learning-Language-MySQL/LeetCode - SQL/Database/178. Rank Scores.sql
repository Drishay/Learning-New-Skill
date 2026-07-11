# Write your MySQL query statement below
-- SELECT score
-- FROM Scores
-- ORDER by score desc;

-- after that i have to use Dense_Rank - window function for this.


-- Approach 1: Correlated Subquery (Recommended)
/* 
SELECT 
    s1.score,
    (
        SELECT COUNT(DISTINCT s2.score) 
        FROM Scores s2 
        WHERE s2.score >= s1.score
    ) AS `rank`
FROM Scores s1
ORDER BY s1.score DESC;
*/

-- Approach 2: Self-Join with GROUP BY
/*
SELECT 
    s1.score, 
    COUNT(DISTINCT s2.score) AS `rank`
FROM Scores s1
INNER JOIN Scores s2 ON s2.score >= s1.score
GROUP BY s1.id, s1.score
ORDER BY s1.score DESC;


*/

