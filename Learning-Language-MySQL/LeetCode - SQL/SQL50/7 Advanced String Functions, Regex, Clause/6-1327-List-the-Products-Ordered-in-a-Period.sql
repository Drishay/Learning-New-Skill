# Write your MySQL query statement below
-- SELECT product_id, SUM(unit)
-- FROM Orders
-- WHERE SUM(unit) >=100 AND order_date BETWEEN '2020-02-01' AND '2020-02-29' 
-- GROUP BY product_id;


-- You cannot use aggregate functions like SUM() directly inside a WHERE clause in SQL
/*
Why the Error OccursWHERE vs HAVING: The WHERE clause filters individual rows before any grouping occurs. It does 
not know what SUM(unit) is because aggregation hasn't happened yet. Aggregate filters must go in a HAVING clause 
after GROUP BY.
*/
WITH table1 AS
(
    SELECT product_id, SUM(unit) AS unit
    FROM Orders
    WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29' 
    GROUP BY product_id
    HAVING SUM(unit) >= 100
)

/*
| product_id | unit |
| ---------- | ---- |
| 1          | 130  |
| 5          | 100  |
*/

SELECT product_name, unit
FROM table1 
LEFT JOIN Products
ON table1.product_id = Products.product_id;


/*
# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit FROM Products p
JOIN Orders o
ON p.product_id = o.product_id
WHERE YEAR(order_date) = 2020 AND MONTH(order_date) = 2
GROUP BY o.product_id
HAVING SUM(unit) >=100
*/