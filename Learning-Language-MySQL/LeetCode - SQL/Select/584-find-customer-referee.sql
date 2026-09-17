/*
============================================================
SQL NOTES
Problem: LeetCode 584 — Find Customer Referee
Difficulty: Easy
SQL Pattern: NULL-Safe Filtering
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given a table called "Customer".

Each row represents a customer. Some customers were referred
by another customer.

The column "referee_id" stores the ID of the customer who
referred them.

The task is to return the names of customers who were NOT
referred by the customer with id = 2.

Important detail:
Customers with NULL referee_id must also be included because
they were not referred by anyone.


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: Customer

+------------+---------+-------------+
| id         | name    | referee_id  |
+------------+---------+-------------+
| INT        | VARCHAR | INT         |
+------------+---------+-------------+

Column Description:

id          → Unique customer identifier
name        → Name of the customer
referee_id  → ID of the customer who referred them


------------------------------------------------------------
3. Keys & Relationships
------------------------------------------------------------

Primary Key:
id

Self-referencing relationship:

Customer.referee_id → Customer.id

This means a customer can refer another customer.

Example:

+----+-------+------------+
| id | name  | referee_id |
+----+-------+------------+
| 1  | Will  | NULL       |
| 2  | Jane  | NULL       |
| 3  | Alex  | 2          |
| 4  | Bill  | NULL       |
| 5  | Zack  | 1          |
+----+-------+------------+

Here:
Alex was referred by Jane because referee_id = 2.


------------------------------------------------------------
4. Important SQL Constraint (NULL Logic)
------------------------------------------------------------

referee_id can contain NULL values.

NULL means:
The customer was not referred by anyone.

In SQL:

NULL != 2

does NOT return TRUE.

Instead it returns UNKNOWN.

Rows with UNKNOWN conditions are filtered out
unless explicitly handled.


------------------------------------------------------------
5. My Original Query
------------------------------------------------------------

SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL;


------------------------------------------------------------
6. Correct Query
------------------------------------------------------------

SELECT name
FROM Customer
WHERE referee_id != 2
OR referee_id IS NULL;


------------------------------------------------------------
7. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load the base table

FROM Customer

The database reads all rows from the Customer table.


Step 2 — Apply filtering condition

WHERE referee_id != 2
OR referee_id IS NULL

This keeps rows where:

1) referee_id is NOT equal to 2
OR
2) referee_id is NULL


Example:

Original Table

+----+-------+------------+
| id | name  | referee_id |
+----+-------+------------+
| 1  | Will  | NULL       |
| 2  | Jane  | NULL       |
| 3  | Alex  | 2          |
| 4  | Bill  | NULL       |
| 5  | Zack  | 1          |
+----+-------+------------+


Filtering condition removes:

referee_id = 2


After filtering

+----+-------+------------+
| id | name  | referee_id |
+----+-------+------------+
| 1  | Will  | NULL       |
| 2  | Jane  | NULL       |
| 4  | Bill  | NULL       |
| 5  | Zack  | 1          |
+----+-------+------------+


Step 3 — Select required column

SELECT name

Final Output

+-------+
| name  |
+-------+
| Will  |
| Jane  |
| Bill  |
| Zack  |
+-------+


------------------------------------------------------------
8. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual SQL execution order:

1) FROM
2) WHERE
3) SELECT


Detailed Flow:

Step 1: FROM
The database loads the Customer table.

Step 2: WHERE
The database evaluates:

referee_id != 2 OR referee_id IS NULL

Each row is checked against the condition.

Rows failing the condition are removed.

Step 3: SELECT
The name column is returned for remaining rows.


------------------------------------------------------------
9. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Used to specify which columns appear in the result.

2) FROM
Specifies the source table.

3) WHERE
Filters rows based on conditions.

4) Logical Operator: OR
Used to combine multiple conditions.

5) NULL Handling
Explicitly checking NULL using:

IS NULL


------------------------------------------------------------
10. Performance Considerations
------------------------------------------------------------

For large datasets (millions of rows):

The database may perform a full table scan.

Possible optimization:

Create an index:

INDEX(referee_id)

This allows the database to quickly locate rows
where referee_id = 2 and exclude them efficiently.

However, since this is a simple filter query,
performance impact is minimal.


------------------------------------------------------------
11. Edge Cases
------------------------------------------------------------

Case 1: referee_id = NULL

Customers not referred by anyone must be included.

Handled by:

referee_id IS NULL


Case 2: All customers referred by 2

Result will be an empty table.


Case 3: No customer referred by 2

All customers will appear in the result.


Case 4: Mixed values

Only rows where referee_id = 2 will be removed.


------------------------------------------------------------
12. Interview Insights
------------------------------------------------------------

This question tests understanding of:

1) SQL filtering
2) NULL comparison behavior
3) Logical operators
4) Correct handling of nullable columns


Common mistakes candidates make:

Wrong Solution:

SELECT name
FROM Customer
WHERE referee_id != 2;

Problem:
Rows with referee_id = NULL are excluded
because NULL != 2 returns UNKNOWN.

Correct approach must explicitly handle NULL.


------------------------------------------------------------
13. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:

NULL-SAFE FILTERING


General Pattern:

SELECT column_list
FROM table_name
WHERE column != value
OR column IS NULL


This pattern appears in many real-world queries where
foreign keys or optional fields may contain NULL values.


------------------------------------------------------------
14. Key Learning Points
------------------------------------------------------------

1) NULL comparisons behave differently in SQL.

2) NULL != value does not return TRUE.

3) Use IS NULL when handling nullable columns.

4) Always check if a column can contain NULL before
writing inequality conditions.

5) Proper NULL handling is a common interview topic
and a critical SQL skill.

============================================================
END OF NOTES
============================================================
*/