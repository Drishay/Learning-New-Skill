# Write your MySQL query statement below

-- my try
/*
with table1 as 
(
    SELECT us.product_id, us.purchase_date, (us.units * p.price ) as total_cost
    FROM UnitsSold as us
    LEFT JOIN Prices as p
    ON ((us.product_id = p.product_id) and (us.purchase_date BETWEEN p.start_date and p.end_date))
),

table2 as 
(
    SELECT product_id, units, total_cost
    FROM table1
    GROUP BY product_id
)

select product_id, (total_cost/units) as average_price
FROM table2;
*/

-- fixing my logic
/*
WITH table1 AS
(
    SELECT
        us.product_id,
        us.units,
        us.units * p.price AS total_cost
    FROM UnitsSold us
    LEFT JOIN Prices p
        ON us.product_id = p.product_id
       AND us.purchase_date BETWEEN p.start_date AND p.end_date
),

table2 AS
(
    SELECT
        product_id,
        SUM(units) AS total_units,
        SUM(total_cost) AS total_revenue
    FROM table1
    GROUP BY product_id
)

SELECT
    product_id,
    ROUND(total_revenue / total_units, 2) AS average_price
FROM table2;
*/

-- but logic fails, as 
/*
The problem says:

If a product does not have any sold units, average_price = 0.

Your query starts from UnitsSold, so products that never sold anything will disappear completely.

That's why most accepted solutions start from Prices and use a LEFT JOIN to UnitsSold:
*/

-- start with price due to a edge case

WITH table1 AS
(
    SELECT
        p.product_id,
        u.units,
        p.price * u.units AS total_cost
    FROM Prices p
    LEFT JOIN UnitsSold u
        ON p.product_id = u.product_id
       AND u.purchase_date BETWEEN p.start_date
                               AND p.end_date
),

table2 AS
(
    SELECT
        product_id,
        COALESCE(SUM(units), 0) AS total_units,
        COALESCE(SUM(total_cost), 0) AS total_revenue
    FROM table1
    GROUP BY product_id
)

SELECT
    product_id,
    ROUND(
        IFNULL(total_revenue / NULLIF(total_units, 0), 0),
        2
    ) AS average_price
FROM table2;



-- gpt
/*
SELECT
    p.product_id,
    ROUND(
        COALESCE(SUM(p.price * u.units) / SUM(u.units), 0),
        2
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
   AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
*/