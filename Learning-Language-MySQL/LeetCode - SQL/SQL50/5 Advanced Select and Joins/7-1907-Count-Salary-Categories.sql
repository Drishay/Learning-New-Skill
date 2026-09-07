# Write your MySQL query statement below
-- no of account with low, AVG, high salary



# Solution is UNION ALL

-- SELECT COUNT(account_id) AS Low_Salary FROM Accounts WHERE income < 20000

-- UNION ALL

-- SELECT COUNT(account_id) AS Average_Salary FROM Accounts WHERE income >= 20000 and income <= 50000

-- UNION ALL

-- SELECT COUNT(account_id) AS High_Salary FROM Accounts WHERE income > 50000;


# Solution to consider
SELECT 'Low Salary' AS category,
       COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION ALL

SELECT 'Average Salary' AS category,
       COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income >= 20000 AND income <= 50000

UNION ALL

SELECT 'High Salary' AS category,
       COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income > 50000;

/*
UNION ALL
Combines the results of multiple SELECT queries vertically.
Keeps all rows, including duplicates.
Each SELECT should return the same number of columns.
Column names come from the first SELECT.

category
category is simply a column alias/name that represents what each row means.
*/


# Other user solution

-- WITH salary_counts AS (
--     SELECT
--         SUM(income < 20000 ) AS low_count,
--         SUM(income BETWEEN 20000 AND 50000 ) AS average_count,
--         SUM(income > 50000 ) AS high_count
--     FROM Accounts
-- )

-- SELECT 'Low Salary' AS category, low_count AS accounts_count
-- FROM salary_counts

-- UNION ALL

-- SELECT 'Average Salary', average_count
-- FROM salary_counts

-- UNION ALL

-- SELECT 'High Salary', high_count
-- FROM salary_counts;