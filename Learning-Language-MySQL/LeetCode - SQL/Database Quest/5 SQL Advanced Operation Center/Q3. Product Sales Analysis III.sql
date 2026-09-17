# Write your MySQL query statement below
WITH table1 AS
(
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
)

SELECT table1.product_id, table1.first_year, Sales.quantity, Sales.price
FROM table1
LEFT JOIN Sales
ON table1.product_id = Sales.product_id AND table1.first_year = Sales.year;


/* had less running time
# Write your MySQL query statement below
SELECT product_id, year as first_year, quantity, price
FROM (
    SELECT *,
    DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year) AS rnk
    FROM Sales

) as t
WHERE rnk = 1;
*/