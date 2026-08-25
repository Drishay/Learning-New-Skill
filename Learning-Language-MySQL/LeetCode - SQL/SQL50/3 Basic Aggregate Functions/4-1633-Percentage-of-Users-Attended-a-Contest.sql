# Write your MySQL query statement below

/*
MySQL supports two types of variables within standard queries: User-defined variable 
(prefixed with @) which don't require declaration, and Local variables (used inside
Stored Procedures/Functions without an @).

User Variable (Everyday Queries):
- Assign a value using := or SET
Example- SET @Status = 'Active';

-- Use it in a query
Example- SELECT * FROM Users WHERE AccountStatus = @Status;

Local Variable (Inside Stored Procedures)
example- DECLARE TotalSales INT DEFAULT 0;
SET TotalSales = 5000;
*/

-- SQL Server (T-SQL): SELECT @users = COUNT(user_id) FROM Users;

-- Alternative SQL Server Assignment: SET @users = (SELECT COUNT(user_id) FROM Users);

-- MySQL:SELECT COUNT(user_id) INTO @users FROM Users;

/* this cannot work, as the in leetcode, we can not run multiple sql queries.
SET @users = (SELECT COUNT(user_id) FROM Users);

SELECT contest_id, COUNT(user_id)
FROM Register
GROUP BY contest_id;
*/


/* Solution 1: Using a Session Variable 
-- Step 1: Assign total count to a session variable
SET @users = (SELECT COUNT(user_id) FROM Users);

-- Step 2: Use the variable in your query
SELECT 
    contest_id, 
    COUNT(user_id) AS registered_users,
    ROUND((COUNT(user_id) / @users) * 100, 2) AS attendance_percentage
FROM Register
GROUP BY contest_id;
*/

/* Solution 2: Inline Subquery 
SELECT 
    contest_id, 
    COUNT(user_id) AS registered_users,
    ROUND((COUNT(user_id) * 100.0) / (SELECT COUNT(user_id) FROM Users), 2) AS attendance_percentage
FROM Register
GROUP BY contest_id;


*/


-- SELECT contest_id, ROUND((COUNT(user_id)/(Select Count(user_id) FROM Users)*100),2) AS percentage
-- FROM Register
-- GROUP BY contest_id
-- ORDER BY percentage DESC;

/*
| contest_id | percentage |
| ---------- | ---------- |
| 209        | 100        |
| 208        | 100        |
| 210        | 100        |
| 215        | 66.67      |
| 207        | 33.33      |
*/

-- Solution 1
SELECT contest_id, ROUND((COUNT(user_id)/(Select Count(user_id) FROM Users)*100),2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;
/*
How It Works
* **`GROUP BY contest_id`**: Combines the rows for each specific contest so you can 
compute the individual user counts and percentages.
* **`ORDER BY percentage DESC, contest_id ASC`**: Sorts the highest percentages first. 
When percentages match (like 100% for `208`, `209`, and `210`), it breaks the tie by 
sorting the `contest_id` numerically from lowest to highest.
*/