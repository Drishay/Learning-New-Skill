# Write your MySQL query statement below
-- SELECT order_id, order_date, a.item_id, b.item_brand, buyer_id, seller_id
-- FROM Orders as a
-- LEFT JOIN Items as b
-- ON a.item_id = b.item_id;
/*
| order_id | order_date | item_id | item_brand | buyer_id | seller_id |
| -------- | ---------- | ------- | ---------- | -------- | --------- |
| 1        | 2019-08-01 | 4       | HP         | 1        | 2         |
| 2        | 2018-08-02 | 2       | Lenovo     | 1        | 3         |
| 3        | 2019-08-03 | 3       | LG         | 2        | 3         |
| 4        | 2018-08-04 | 1       | Samsung    | 4        | 2         |
| 5        | 2018-08-04 | 1       | Samsung    | 3        | 4         |
| 6        | 2019-08-05 | 2       | Lenovo     | 2        | 4         |
*/

-- SELECT buyer_id, count(*) as orders_in_2019
-- FROM Orders as a 
-- LEFT JOIN Items as b
-- ON a.item_id = b.item_id
-- WHERE YEAR(order_date) = 2019
-- GROUP BY buyer_id;
/*
| buyer_id | orders_in_2019 |
| -------- | -------------- |
| 1        | 1              |
| 2        | 2              |
*/

-- Even better - Since you don't use anything from Items, you don't need the join:

-- SELECT buyer_id, COUNT(*) AS orders_in_2019
-- FROM Orders
-- WHERE YEAR(order_date) = 2019
-- GROUP BY buyer_id;
/*
| buyer_id | orders_in_2019 |
| -------- | -------------- |
| 1        | 1              |
| 2        | 2              |
*/

-- using join and sub query
-- SELECT a.user_id as buyer_id, a.join_date, orders_in_2019
-- FROM Users a
-- LEFT JOIN
-- (
--     SELECT buyer_id, COUNT(*) AS orders_in_2019
--     FROM Orders
--     WHERE YEAR(order_date) = 2019
--     GROUP BY buyer_id
-- ) AS b
-- ON a.user_id = b.buyer_id;
/*
| buyer_id | join_date  | orders_in_2019 |
| -------- | ---------- | -------------- |
| 1        | 2018-01-01 | 1              |
| 2        | 2018-02-09 | 2              |
| 3        | 2018-01-19 | null           |
| 4        | 2018-05-21 | null           |
*/
-- JOIN query is logically correct, but LEFT JOIN gives you NULL when there is no matching row in Orders.
-- You just need to convert that NULL to 0 using IFNULL() or COALESCE().

/*
IFNULL(a, b)
→ MySQL-specific
→ Exactly 2 arguments
→ If a is NULL, return b

COALESCE(a, b, c, ...)
→ Standard SQL
→ Multiple arguments
→ Returns the first non-NULL value
*/

SELECT 
    a.user_id as buyer_id, 
    a.join_date, 
    -- IFNULL(b.orders_in_2019, 0) AS orders_in_2019
    COALESCE(b.orders_in_2019, 0) AS orders_in_2019
FROM Users a
LEFT JOIN
(
    SELECT buyer_id, COUNT(*) AS orders_in_2019
    FROM Orders
    WHERE YEAR(order_date) = 2019
    GROUP BY buyer_id
) AS b
ON a.user_id = b.buyer_id;


# Now, solving using WITH
-- WITH no_orders AS
-- (
--     SELECT buyer_id, COUNT(*) AS orders_in_2019
--     FROM Orders
--     WHERE YEAR(order_date) = 2019
--     GROUP BY buyer_id
-- )
-- SELECT user_id as buyer_id, join_date, IF(user_id IN (SELECT buyer_id from no_orders), (SELECT orders_in_2019 FROM no_orders WHERE buyer_id = user_id), 0) as orders_in_2019
-- FROM Users;



# other user solution
# Write your MySQL query statement below
-- SELECT user_id AS buyer_id, join_date, SUM(CASE WHEN YEAR(order_date) = '2019' THEN 1 ELSE 0 END) AS orders_in_2019
-- FROM Users u
-- LEFT JOIN Orders o
--     ON u.user_id = o.buyer_id
-- GROUP BY user_id