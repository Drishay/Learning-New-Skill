# Write your MySQL query statement below
SELECT Products.product_name, SUM(unit) as unit
FROM Orders
LEFT JOIN Products
ON Orders.product_id = Products.product_id
WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY Orders.product_id
HAVING SUM(unit) >=100;