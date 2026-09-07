# Write your MySQL query statement below
-- I can do group by sell_date, and then count(product) for num_sold
-- how or what to do ? for Basketball,Headphone,T-shirt {aggregate multiple rows into a single comma-separated value 
-- while using GROUP BY.}
/* We can do
FOR MySQL
Use GROUP_CONCAT() - GROUP_CONCAT(product_name ORDER BY product_name SEPARATOR ',') AS products
FROM products

For SQL Server
Use STRING_AGG() - STRING_AGG(product_name, ',') AS products

*/

-- SELECT
--     sell_date,
--     COUNT(product) as num_sold,
--     GROUP_CONCAT(product ORDER BY product SEPARATOR ',') AS products
-- FROM Activities
-- GROUP BY sell_date;

-- there could be same products name for same sell date, thus USE DISTINCT and "Return the result table ordered by sell_date."

SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;

/* other user solution
# Write your MySQL query statement below
select
sell_date,
count(distinct product) as num_sold,
group_concat(distinct product ) as products 
from Activities
group by sell_date
*/