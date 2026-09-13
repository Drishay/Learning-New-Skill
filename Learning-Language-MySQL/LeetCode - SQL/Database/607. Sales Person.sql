# Write your MySQL query statement below

-- SELECT order_id, order_date, com_id, name, amount
-- FROM Orders
-- LEFT JOIN SalesPerson 
-- ON Orders.sales_id = SalesPerson.sales_id;
/*
| order_id | order_date | com_id | name | amount |
| -------- | ---------- | ------ | ---- | ------ |
| 1        | 0000-00-00 | 3      | Pam  | 10000  |
| 2        | 0000-00-00 | 4      | Alex | 5000   |
| 3        | 0000-00-00 | 1      | John | 50000  |
| 4        | 0000-00-00 | 1      | Pam  | 25000  |
*/

-- I can absolutely perform multiple joins in a single SQL query

-- SELECT order_id, order_date, Company.name, SalesPerson.name, amount
-- FROM Orders
-- LEFT JOIN SalesPerson 
-- ON Orders.sales_id = SalesPerson.sales_id
-- LEFT JOIN Company
-- ON Orders.com_id = Company.com_id;

/*
| order_id | order_date | name   | name | amount |
| -------- | ---------- | ------ | ---- | ------ |
| 1        | 0000-00-00 | YELLOW | Pam  | 10000  |
| 2        | 0000-00-00 | GREEN  | Alex | 5000   |
| 3        | 0000-00-00 | RED    | John | 50000  |
| 4        | 0000-00-00 | RED    | Pam  | 25000  |
*/

-- SELECT Company.name, SalesPerson.name
-- FROM Orders
-- LEFT JOIN SalesPerson 
-- ON Orders.sales_id = SalesPerson.sales_id
-- LEFT JOIN Company
-- ON Orders.com_id = Company.com_id
-- GROUP BY SalesPerson.name
-- HAVING Company.name != "RED";
/*
| name   | name |
| ------ | ---- |
| YELLOW | Pam  |
| GREEN  | Alex |
*/


# Apporach change

-- SELECT order_id, order_date, Company.name, sales_id, amount
-- FROM Orders
-- LEFT JOIN Company
-- ON Orders.com_id = Company.com_id;

/*
| order_id | order_date | name   | sales_id | amount |
| -------- | ---------- | ------ | -------- | ------ |
| 1        | 0000-00-00 | YELLOW | 4        | 10000  |
| 2        | 0000-00-00 | GREEN  | 5        | 5000   |
| 3        | 0000-00-00 | RED    | 1        | 50000  |
| 4        | 0000-00-00 | RED    | 4        | 25000  |
*/

-- SELECT SalesPerson.name, b.name as company
-- FROM SalesPerson
-- LEFT JOIN 
-- (
    
--     SELECT Company.name, sales_id
--     FROM Orders
--     LEFT JOIN Company
--     ON Orders.com_id = Company.com_id
-- ) AS b
-- ON SalesPerson.sales_id = b.sales_id;

/*
| name | company |
| ---- | ------- |
| John | RED     |
| Amy  | null    |
| Mark | null    |
| Pam  | RED     |
| Pam  | YELLOW  |
| Alex | GREEN   |
*/

WITH table1 AS (
    SELECT 
        SalesPerson.name,
        b.name AS company
    FROM SalesPerson
    LEFT JOIN (
        SELECT 
            Company.name,
            Orders.sales_id
        FROM Orders
        LEFT JOIN Company
            ON Orders.com_id = Company.com_id
    ) AS b
        ON SalesPerson.sales_id = b.sales_id
)
SELECT name
FROM table1
GROUP BY name
HAVING SUM(
    CASE 
        WHEN company = 'RED' THEN 1
        ELSE 0
    END
) = 0;

/*
WITH table1 AS (
    SELECT 
        SalesPerson.name,
        b.name AS company
    FROM SalesPerson
    LEFT JOIN (
        SELECT 
            Company.name,
            Orders.sales_id
        FROM Orders
        LEFT JOIN Company
            ON Orders.com_id = Company.com_id
    ) AS b
        ON SalesPerson.sales_id = b.sales_id
)
SELECT DISTINCT t1.name
FROM table1 t1
WHERE NOT EXISTS (
    SELECT 1
    FROM table1 t2
    WHERE t2.name = t1.name
      AND t2.company = 'RED'
);
*/

/*
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT sales_id
    FROM Orders
    JOIN Company
        ON Orders.com_id = Company.com_id
    WHERE Company.name = 'RED'
);
*/