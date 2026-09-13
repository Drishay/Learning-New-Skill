# Write your MySQL query statement below
SELECT Sales.product_id, Product.product_name
FROM Sales
LEFT JOIN Product
ON Sales.product_id = Product.product_id
WHERE (Sales.sale_date BETWEEN '2019-01-01' AND '2019-03-31')
    AND Sales.product_id NOT IN (
      SELECT product_id 
      FROM Sales 
      WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31')
GROUP BY Sales.product_id, Product.product_name;

/* Method 1: Using MIN() and MAX() (Recommended)
SELECT p.product_id, p.product_name 
FROM Product p
JOIN Sales s ON p.product_id = s.product_id
GROUP BY p.product_id, p.product_name
HAVING MIN(s.sale_date) >= '2019-01-01' 
   AND MAX(s.sale_date) <= '2019-03-31';

*/

/* Method 2: Using NOT IN
SELECT DISTINCT p.product_id, p.product_name
FROM Product p
JOIN Sales s ON p.product_id = s.product_id
WHERE p.product_id NOT IN (
    SELECT product_id 
    FROM Sales 
    WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31'
);
*/