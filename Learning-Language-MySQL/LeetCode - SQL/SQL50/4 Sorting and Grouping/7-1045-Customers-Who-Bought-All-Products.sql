# Write your MySQL query statement below

-- Option 1: You want a unique list of which customer bought which product
-- SELECT DISTINCT customer_id, product_key 
-- FROM Customer 
-- ORDER BY customer_id ASC;
/*
| customer_id | product_key |
| ----------- | ----------- |
| 1           | 5           |
| 1           | 6           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
*/

-- Option 2: You want to count how many unique products each customer bought
-- SELECT customer_id, COUNT(DISTINCT product_key) AS unique_products_count
-- FROM Customer 
-- GROUP BY customer_id 
-- ORDER BY customer_id ASC;
/*
| customer_id | unique_products_count |
| ----------- | --------------------- |
| 1           | 2                     |
| 2           | 1                     |
| 3           | 2                     |
*/

-- Option 3: You want to group by both columns
-- SELECT customer_id, product_key 
-- FROM Customer 
-- GROUP BY customer_id, product_key 
-- ORDER BY customer_id ASC;
/*
| customer_id | product_key |
| ----------- | ----------- |
| 1           | 5           |
| 1           | 6           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
*/

-- WITH Table1 AS
-- (
--     SELECT customer_id, SUM(DISTINCT product_key) AS unique_products_sum
--     FROM Customer 
--     GROUP BY customer_id 
--     ORDER BY customer_id ASC
-- )
/*
| customer_id | unique_products_sum |
| ----------- | ------------------- |
| 1           | 11                  |
| 2           | 6                   |
| 3           | 11                  |
*/
-- SELECT customer_id
-- FROM Table1
-- WHERE unique_products_sum = (SELECT SUM(product_key) FROM Product);

/* Wrong Answer: 8 / 9 testcases passed
Input
Customer =
| customer_id | product_key |
| ----------- | ----------- |
| 1           | 5           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
| 1           | 6           |
Product =
| product_key |
| ----------- |
| 5           |
| 6           |
| 0           |

Use Testcase
Output
| customer_id |
| ----------- |
| 1           |
| 3           |
Expected
| customer_id |
| ----------- |

*/

# solution 1 worked
# we should count, not sum
-- WITH Table1 AS
-- (
--     SELECT customer_id, COUNT(DISTINCT product_key) AS unique_products_count
--     FROM Customer 
--     GROUP BY customer_id 
--     ORDER BY customer_id ASC
-- )
/*
| customer_id | unique_products_count |
| ----------- | --------------------- |
| 1           | 2                     |
| 2           | 1                     |
| 3           | 2                     |
*/

-- SELECT customer_id
-- FROM Table1
-- WHERE unique_products_count = (SELECT COUNT(product_key) FROM Product);


#better way of writing
SELECT
    customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*)
    FROM Product
);