/*
SQL NOTES
LeetCode 1068 — Product Sales Analysis I

------------------------------------------------------------
PROBLEM SUMMARY
------------------------------------------------------------

We are given two tables:

1. Sales
2. Product

Goal of the problem:

For every sale record, return the product name along with the
year and price of that sale.

We must combine information from both tables.

Expected Output Columns:

product_name
year
price

Each row in the output represents one sale.


------------------------------------------------------------
TABLE STRUCTURE
------------------------------------------------------------

Table: Sales

+------------+------------+-------+
| product_id | year       | price |
+------------+------------+-------+
| int        | int        | int   |
+------------+------------+-------+

Notes:
• Each row represents a sale of a product in a given year
• product_id refers to a product in the Product table


Table: Product

+------------+--------------+
| product_id | product_name |
+------------+--------------+
| int        | varchar      |
+------------+--------------+

Notes:
• product_id is the PRIMARY KEY


------------------------------------------------------------
RELATIONSHIP BETWEEN TABLES
------------------------------------------------------------

Product.product_id  →  Sales.product_id

This is a typical:

ONE product
to
MANY sales

So the relationship is:

Product (1) —— (N) Sales


------------------------------------------------------------
MY ORIGINAL QUERY
------------------------------------------------------------

SELECT product_name, year, price
FROM Sales
INNER JOIN Product
ON Sales.product_id = Product.product_id;


------------------------------------------------------------
CORRECT QUERY
------------------------------------------------------------

SELECT
    p.product_name,
    s.year,
    s.price
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id;


------------------------------------------------------------
QUERY EXPLANATION
------------------------------------------------------------

Step 1 — Load base table

FROM Sales

The database first reads the Sales table.

Example intermediate table:

product_id | year | price
1          | 2019 | 100
2          | 2020 | 200


Step 2 — Join Product table

JOIN Product
ON Sales.product_id = Product.product_id

The database matches rows where product_id is equal.

Intermediate result:

product_id | year | price | product_name
1          | 2019 | 100   | Nokia
2          | 2020 | 200   | Apple


Step 3 — Select required columns

SELECT product_name, year, price

Final output:

product_name | year | price
Nokia        | 2019 | 100
Apple        | 2020 | 200


------------------------------------------------------------
SQL EXECUTION FLOW (DATABASE ENGINE)
------------------------------------------------------------

Actual execution order inside the database engine:

1. FROM Sales
2. JOIN Product
3. ON condition evaluation
4. Create joined intermediate table
5. SELECT product_name, year, price

Logical SQL order:

FROM
→ JOIN
→ ON
→ SELECT

Since there is no filtering or aggregation,
the execution is very straightforward.


------------------------------------------------------------
SQL CONCEPTS USED
------------------------------------------------------------

• INNER JOIN
• Foreign key relationship
• Table column selection


------------------------------------------------------------
EDGE CASES
------------------------------------------------------------

1. Product without sales

If a product exists in Product but not in Sales,
it will NOT appear in the result.

Reason:
INNER JOIN only returns matching rows.


2. Invalid product_id in Sales

If Sales contains a product_id not present in Product,
that row will be removed by the INNER JOIN.


3. Duplicate sales rows

If multiple sales exist for the same product,
multiple rows will appear in the output.


------------------------------------------------------------
PERFORMANCE CONSIDERATIONS
------------------------------------------------------------

On large datasets (millions of rows):

Join performance depends on indexes.

Important index:

Product.product_id  (Primary Key — already indexed)

Recommended index:

Sales.product_id

This allows the database to perform a fast join
using an index lookup instead of scanning the entire table.


------------------------------------------------------------
INTERVIEW INSIGHTS
------------------------------------------------------------

What interviewers test with this problem:

• Basic JOIN understanding
• Foreign key relationships
• Ability to combine tables

This is a foundational SQL question.

Common candidate mistakes:

1. Forgetting the JOIN condition
   → Causes CROSS JOIN

2. Selecting wrong columns

3. Using WHERE instead of JOIN condition incorrectly


Possible follow-up interview questions:

• What happens if we use LEFT JOIN?
• How would you include products with no sales?
• How does the database optimize joins?


------------------------------------------------------------
SQL PATTERN RECOGNITION
------------------------------------------------------------

Pattern Type:

Basic Relational Join

Pattern Description:

Combine data from two tables using a foreign key relationship.

Common problems using this pattern:

• Customer Orders
• Order Details joins
• Employee Department joins


------------------------------------------------------------
KEY LEARNING POINTS
------------------------------------------------------------

1. Understand table relationships before writing SQL.

2. Identify the join key:
   Sales.product_id = Product.product_id

3. Use INNER JOIN when only matching records are needed.

4. Always think in terms of:

Base Table
→ Join
→ Select columns

5. Most real-world analytics queries are built on joins.
*/