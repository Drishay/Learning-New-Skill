/*
============================================================
SQL NOTES
Problem: LeetCode 595 — Big Countries
Difficulty: Easy
SQL Pattern: Multi-Condition Filtering
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given a table called "World" that contains information
about countries such as their population and area.

The task is to identify "big countries".

A country is considered big if:

1) Its area is greater than or equal to 3,000,000
OR
2) Its population is greater than or equal to 25,000,000

We must return the following columns for such countries:

- name
- population
- area


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: World

+------------+-----------+---------+------------+-------+
| name       | continent | area    | population | gdp   |
+------------+-----------+---------+------------+-------+
| VARCHAR    | VARCHAR   | INT     | INT        | BIGINT|
+------------+-----------+---------+------------+-------+

Column Description:

name        → Country name
continent   → Continent the country belongs to
area        → Area of the country
population  → Total population
gdp         → Gross domestic product


------------------------------------------------------------
3. Keys & Constraints
------------------------------------------------------------

Primary Key:
name

Meaning:
Each country appears only once in the table.

No joins or relationships with other tables are required
for this problem.


------------------------------------------------------------
4. Problem Logic
------------------------------------------------------------

We need to filter countries that satisfy at least one
of the following conditions:

Condition 1:
area >= 3,000,000

Condition 2:
population >= 25,000,000

If either condition is true, the country should appear
in the result.

This means we use the logical OR operator.


------------------------------------------------------------
5. My Original Query
------------------------------------------------------------

SELECT name, population, area
FROM World
WHERE area >= 3000000
OR population >= 25000000;


------------------------------------------------------------
6. Correct Query
------------------------------------------------------------

SELECT name, population, area
FROM World
WHERE area >= 3000000
OR population >= 25000000;


------------------------------------------------------------
7. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load the table

FROM World

The database reads all rows from the World table.


Step 2 — Apply filtering conditions

WHERE area >= 3000000
OR population >= 25000000

Each row is evaluated.

If either condition is TRUE, the row is kept.


Example:

Original Table

+---------+-----------+---------+------------+
| name    | continent | area    | population |
+---------+-----------+---------+------------+
| USA     | NA        | 9834000 | 331000000  |
| Iceland | Europe    | 103000  | 372000     |
| India   | Asia      | 3287000 | 1390000000 |
+---------+-----------+---------+------------+


Filtering evaluation:

USA
area >= 3000000 → TRUE
population >= 25000000 → TRUE
Result → included

Iceland
area >= 3000000 → FALSE
population >= 25000000 → FALSE
Result → excluded

India
area >= 3000000 → TRUE
population >= 25000000 → TRUE
Result → included


Step 3 — Return required columns

SELECT name, population, area


Final Output Example

+-------+-------------+---------+
| name  | population  | area    |
+-------+-------------+---------+
| USA   | 331000000   | 9834000 |
| India | 1390000000  | 3287000 |
+-------+-------------+---------+


------------------------------------------------------------
8. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual SQL execution order:

1) FROM
2) WHERE
3) SELECT


Execution Flow:

Step 1: FROM
The database loads the World table.

Step 2: WHERE
Each row is checked against the condition:

area >= 3000000
OR population >= 25000000

Rows failing both conditions are removed.

Step 3: SELECT
Only the requested columns are returned.


------------------------------------------------------------
9. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Used to specify which columns appear in the result.

2) FROM
Defines the table being queried.

3) WHERE
Filters rows based on logical conditions.

4) Logical Operator: OR
Used when at least one condition must be TRUE.


------------------------------------------------------------
10. Performance Considerations
------------------------------------------------------------

For small tables, the query runs instantly.

For large datasets (millions of rows):

The database may perform a FULL TABLE SCAN.

Possible indexes:

INDEX(area)
INDEX(population)

However, because the condition uses OR,
the optimizer may not fully utilize both indexes.

Still acceptable for most real-world cases.


------------------------------------------------------------
11. Edge Cases
------------------------------------------------------------

Case 1: Country satisfies both conditions

Example:
area = 9,000,000
population = 300,000,000

The row appears once in the result.


Case 2: Country satisfies only one condition

Example:
area = 200,000
population = 50,000,000

The country still appears in the result.


Case 3: Country satisfies none

Example:
area = 100,000
population = 500,000

The row is excluded.


Case 4: Extremely large values

Very large population or area values do not affect
query correctness.


------------------------------------------------------------
12. Interview Insights
------------------------------------------------------------

This question tests:

1) Basic SQL syntax
2) Filtering using WHERE
3) Logical operator OR
4) Correct interpretation of problem conditions


Common mistakes candidates make:

1) Using AND instead of OR

Example (Wrong):

SELECT name, population, area
FROM World
WHERE area >= 3000000
AND population >= 25000000;

This returns only countries satisfying BOTH conditions,
which is incorrect.


2) Returning extra columns

The problem requires only:
name, population, area


3) Overcomplicating the query

No joins or subqueries are required.


------------------------------------------------------------
13. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:
MULTI-CONDITION FILTERING

General Pattern:

SELECT column_list
FROM table_name
WHERE condition1
OR condition2


This pattern is common in:

- Risk detection queries
- Customer segmentation
- Fraud detection rules
- Data anomaly filtering


------------------------------------------------------------
14. Key Learning Points
------------------------------------------------------------

1) Understand the problem logic before writing SQL.

2) Use OR when at least one condition must be true.

3) Avoid unnecessary SQL operations.

4) Write the simplest query that solves the problem.

5) Simple filtering problems should remain simple.

Clean SQL is a strong signal of good database thinking.

============================================================
END OF NOTES
============================================================
*/