# Write your MySQL query statement below
-- gives the name in lower characters
-- SELECT user_id, lower(name)
-- FROM Users
-- ORDER BY user_id;

-- SELECT user_id, UPPER(LEFT(lower(name), 1)) + SUBSTRING(lower(name), 2, LENGTH(name)) as name
-- FROM users
-- ORDER BY user_id;

-- The + operator for string concatenation is causing an issue because you are using MySQL or 
-- PostgreSQL (indicated by your use of LENGTH).In MySQL and PostgreSQL, the + operator tries to add
-- the strings as numbers, which results in 0. You must use the CONCAT() function or the || operator
-- instead.

SELECT user_id, CONCAT(UPPER(LEFT(name, 1)), SUBSTRING(LOWER(name), 2)) AS name
FROM users
ORDER BY user_id;