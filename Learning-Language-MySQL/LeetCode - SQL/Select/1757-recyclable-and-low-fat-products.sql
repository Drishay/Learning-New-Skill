/*
============================================================
SQL NOTES
Problem: LeetCode 1757 — Recyclable and Low Fat Products
Difficulty: Easy
SQL Pattern: Basic Row Filtering
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given a table called "Products".

Each row represents a product and contains information about:
- Whether the product is low fat
- Whether the product is recyclable

The task is to return the product_id of products that satisfy
both conditions:

1) The product must be low fat
2) The product must be recyclable

So we need to filter rows where:

low_fats = 'Y'
AND recyclable = 'Y'

The final result should only contain the product_id column.


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: Products

+-------------+----------+-------------+
| product_id  | low_fats | recyclable  |
+-------------+----------+-------------+
| INT         | CHAR(1)  | CHAR(1)     |
+-------------+----------+-------------+

Column Description:

product_id  → Unique identifier for each product
low_fats    → 'Y' if the product is low fat, 'N' otherwise
recyclable  → 'Y' if the product is recyclable, 'N' otherwise


------------------------------------------------------------
3. Keys & Constraints
------------------------------------------------------------

Primary Key:
product_id

Meaning:
- Each product_id is unique
- No duplicate rows for the same product

Value Constraints:

low_fats    ∈ {'Y','N'}
recyclable  ∈ {'Y','N'}

NULL values are not expected in this problem.

No relationships with other tables.


------------------------------------------------------------
4. My Original Query
------------------------------------------------------------

SELECT product_id
FROM Products
WHERE low_Fats = 'Y'
AND recyclable = 'Y';


------------------------------------------------------------
5. Correct Query
------------------------------------------------------------

SELECT product_id
FROM Products
WHERE low_fats = 'Y'
AND recyclable = 'Y';


------------------------------------------------------------
6. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load the base table

FROM Products

The database engine reads all rows from the Products table.


Step 2 — Apply filtering conditions

WHERE low_fats = 'Y'
AND recyclable = 'Y'

Only rows satisfying BOTH conditions are kept.


Example:

Original Table

+-------------+----------+-------------+
| product_id  | low_fats | recyclable  |
+-------------+----------+-------------+
| 0           | Y        | N           |
| 1           | Y        | Y           |
| 2           | N        | Y           |
| 3           | Y        | Y           |
+-------------+----------+-------------+


After WHERE filtering

+-------------+----------+-------------+
| product_id  | low_fats | recyclable  |
+-------------+----------+-------------+
| 1           | Y        | Y           |
| 3           | Y        | Y           |
+-------------+----------+-------------+


Step 3 — Select required column

SELECT product_id

Final output:

+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+


------------------------------------------------------------
7. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual SQL execution order:

1) FROM
2) WHERE
3) SELECT

Detailed Flow:

Step 1: FROM
The database loads the Products table.

Step 2: WHERE
Filtering happens before returning columns.

The engine checks each row:
- Is low_fats = 'Y'?
- Is recyclable = 'Y'?

Rows not satisfying the condition are removed.

Step 3: SELECT
After filtering, only the required column
(product_id) is returned.


------------------------------------------------------------
8. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Used to choose which columns should appear
in the final output.

2) FROM
Specifies the table being queried.

3) WHERE
Filters rows based on logical conditions.

4) Logical Operator: AND
Ensures both conditions must be true.


------------------------------------------------------------
9. Performance Considerations
------------------------------------------------------------

For small datasets, the query performs very fast.

For very large datasets (millions of rows):

The database may perform a:

FULL TABLE SCAN

This means every row is checked.


Possible Optimization:

Create a composite index:

INDEX(low_fats, recyclable)

This allows the database to quickly locate rows
where both conditions are satisfied.

However, for such a simple table, indexing is
often unnecessary.


------------------------------------------------------------
10. Edge Cases
------------------------------------------------------------

1) No matching rows

If no product satisfies both conditions,
the result will be an empty table.


2) All rows match

If every product is low fat and recyclable,
all product_id values will be returned.


3) NULL values (not expected here)

If columns allowed NULL values, then:

low_fats = 'Y'

would exclude rows where low_fats is NULL
because NULL comparisons return UNKNOWN.


------------------------------------------------------------
11. Interview Insights
------------------------------------------------------------

This problem tests:

- Basic SQL syntax
- Understanding of WHERE filtering
- Logical operators (AND / OR)
- Ability to avoid overcomplicating queries


Common mistakes candidates make:

1) Using GROUP BY unnecessarily
2) Using DISTINCT when not needed
3) Writing subqueries for simple filters
4) Using CASE statements unnecessarily


A good SQL engineer writes the simplest
query that satisfies the requirement.


------------------------------------------------------------
12. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:

BASIC ROW FILTERING

General Pattern:

SELECT column_list
FROM table_name
WHERE condition


Examples of similar problems:

- Filtering active users
- Selecting orders above a price threshold
- Getting employees in a specific department
- Finding products with certain attributes


------------------------------------------------------------
13. Key Learning Points
------------------------------------------------------------

1) Always understand the filtering condition first.

2) Use WHERE when filtering rows.

3) Use AND when multiple conditions must be true.

4) Avoid unnecessary SQL operations.

5) Simple problems should have simple queries.

Clean SQL is a sign of strong database thinking.

============================================================
END OF NOTES
============================================================
*/