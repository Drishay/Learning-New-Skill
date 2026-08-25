# Write your MySQL query statement below

-- SELECT query_name, (rating/position) as Quality_ratio, rating
-- FROM Queries;

-- | query_name | Quality_ratio | rating |
-- | ---------- | ------------- | ------ |
-- | Dog        | 5             | 5      |
-- | Dog        | 2.5           | 5      |
-- | Dog        | 0.005         | 1      |
-- | Cat        | 0.4           | 2      |
-- | Cat        | 1             | 3      |
-- | Cat        | 0.5714        | 4      |

-- SELECT query_name, Round(AVG(rating/position),2) as quality, Count(rating)
-- FROM Queries
-- GROUP BY query_name;

-- | query_name | Quality_ratio | Count(rating) |
-- | ---------- | ------------- | ------------- |
-- | Dog        | 2.5           | 3             |
-- | Cat        | 0.66          | 3             |



-- SELECT query_name, Round(AVG(rating/position),2) as quality, Round((COUNT(rating<3)/COUNT(rating) * 100),2) as poor_query_percentage
-- FROM Queries
-- GROUP BY query_name;

/*
To count only the ratings less than 3, you cannot put the condition rating < 3
 directly inside a standard COUNT() function

Method 1: Use SUM with a CASE statement (Most Compatible)
-- ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2)

Method 2: Use FILTER (PostgreSQL and SQLite)
-- ROUND(COUNT(*) FILTER (WHERE rating < 3) / COUNT(*) * 100, 2)

Method 3: Use IF (MySQL Only)
-- ROUND(SUM(IF(rating < 3, 1, 0)) / COUNT(*) * 100, 2)
*/

SELECT query_name, Round(AVG(rating/position),2) as quality, ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2) as poor_query_percentage
FROM Queries
GROUP BY query_name;