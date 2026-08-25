# Write your MySQL query statement below
-- SELECT "YYYY-MM", country
-- FROM Transactions
-- GROUP BY "YYYY-MM" and country;

/*
Q How to extract year and month from date?
A: Option 1
DATE_FORMAT() ex: DATE_FORMAT(trans_date, '%Y-%m')

Option 2 — Extract separately
YEAR(trans_date)
MONTH(trans_date)

for this problem - DATE_FORMAT(date, 'how I want the date to look')
*/

/*
SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') as month,
    country,
    COUNT(*) as trans_count,
    -- (IF(state = "approved", 1, 0)) as approved_count
    SUM(IF(state = "approved", 1, 0)) as approved_count,
    SUM(amount) as trans_total_amount
    
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;

| month   | country | trans_count | approved_count | trans_total_amount |
| ------- | ------- | ----------- | -------------- | ------------------ |
| 2018-12 | US      | 2           | 1              | 3000               |
| 2019-01 | US      | 1           | 1              | 2000               |
| 2019-01 | DE      | 1           | 1              | 2000               |

*/

SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') as month,
    country,
    COUNT(*) as trans_count,
    -- (IF(state = "approved", 1, 0)) as approved_count
    SUM(IF(state = "approved", 1, 0)) as approved_count,
    SUM(amount) as trans_total_amount,
    -- SUM(amount, IF(state = "approved", 1, 0)) as approved_total_amount
    -- ROUND(SUM(amount) FILTER (WHERE state = "approved"), 2) as approved_total_amount
    SUM(IF(state = "approved", amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;

/* different way of using it
-- Count approved transactions
SUM(IF(state = 'approved', 1, 0))

-- Sum approved transaction amounts
SUM(IF(state = 'approved', amount, 0))

*/