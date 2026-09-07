# Write your MySQL query statement below
WITH table1 AS
(
    SELECT product_id, MAX(change_date) as closest_change_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
),

/*
| product_id | closest_change_date |
| ---------- | ------------------- |
| 1          | 2019-08-16          |
| 2          | 2019-08-14          |
*/

-- SELECT first.product_id, table1.closest_change_date
-- FROM Products as first
-- GROUP BY product_id
-- LEFT JOIN table1
-- ON first.product_id = table1.product_id;

Table2 AS
(
    SELECT 
    first.product_id, 
    table1.closest_change_date 
    FROM Products AS first 
    LEFT JOIN table1 ON first.product_id = table1.product_id
    GROUP BY first.product_id, table1.closest_change_date
)
/*
| product_id | closest_change_date |
| ---------- | ------------------- |
| 1          | 2019-08-16          |
| 2          | 2019-08-14          |
| 3          | null                |
*/

SELECT table2.product_id, IF(closest_change_date IS NOT null, new_price, 10) as price
FROM table2
LEFT JOIN Products
ON (table2.product_id = Products.product_id AND table2.closest_change_date = Products.change_date);

/*
| product_id | price |
| ---------- | ----- |
| 1          | 35    |
| 2          | 50    |
| 3          | 10    |
*/
