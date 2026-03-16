/*
============================================================
SQL NOTES
Problem: LeetCode 1378 — Replace Employee ID With The Unique Identifier
Difficulty: Easy
SQL Pattern: LEFT JOIN Lookup
Concepts: Joins, Set Theory Interpretation
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given two tables:

1) Employees
2) EmployeeUNI

The Employees table stores employee IDs and names.

The EmployeeUNI table stores a mapping between
employee IDs and their unique identifiers.

Not every employee has a unique identifier.

The task is to return a table containing:

unique_id
name

If an employee does not have a unique_id,
the result should show NULL for that column.


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: Employees

+------+--------+
| id   | name   |
+------+--------+
| INT  | VARCHAR|
+------+--------+

Column Description:

id   → Employee identifier
name → Employee name


Table: EmployeeUNI

+------+-----------+
| id   | unique_id |
+------+-----------+
| INT  | INT       |
+------+-----------+

Column Description:

id        → Employee identifier
unique_id → Unique identifier assigned to employee


------------------------------------------------------------
3. Keys & Constraints
------------------------------------------------------------

Primary Keys:

Employees.id
EmployeeUNI.id

Relationship:

Employees.id → EmployeeUNI.id

Meaning:

EmployeeUNI references employees using the same id.

Important Constraint:

Not every employee exists in EmployeeUNI.

Therefore some employees will not have a unique_id.


------------------------------------------------------------
4. Problem Logic
------------------------------------------------------------

We must return every employee's name
along with their unique_id if it exists.

Logical Steps:

Step 1
Start with the Employees table because
every employee must appear in the result.

Step 2
Match rows from EmployeeUNI where:

Employees.id = EmployeeUNI.id

Step 3
If a match exists → return the unique_id.

Step 4
If no match exists → unique_id becomes NULL.

This behavior requires a LEFT JOIN.


------------------------------------------------------------
5. My Understanding Before Learning Joins
------------------------------------------------------------

Initially, the approach may not be clear because
the problem involves combining data from two tables.

The correct approach requires understanding
how SQL joins tables using a matching column.


------------------------------------------------------------
6. Correct Query
------------------------------------------------------------

SELECT unique_id, name
FROM Employees
LEFT JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id;


------------------------------------------------------------
7. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load Employees table

FROM Employees

The database begins with the Employees table.


Step 2 — Join EmployeeUNI

LEFT JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id

The database attempts to match rows
based on the employee id.


Example:

Employees

+----+---------+
| id | name    |
+----+---------+
| 1  | Alice   |
| 7  | Bob     |
| 11 | Alex    |
| 90 | Winston |
+----+---------+

EmployeeUNI

+----+-----------+
| id | unique_id |
+----+-----------+
| 11 | 2         |
| 90 | 3         |
+----+-----------+


Intermediate Result After JOIN

+----+---------+----+-----------+
| id | name    | id | unique_id |
+----+---------+----+-----------+
| 1  | Alice   |NULL| NULL      |
| 7  | Bob     |NULL| NULL      |
|11  | Alex    |11  | 2         |
|90  | Winston |90  | 3         |
+----+---------+----+-----------+


Step 3 — Select required columns

SELECT unique_id, name


Final Output

+-----------+---------+
| unique_id | name    |
+-----------+---------+
| NULL      | Alice   |
| NULL      | Bob     |
| 2         | Alex    |
| 3         | Winston |
+-----------+---------+


------------------------------------------------------------
8. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual execution order inside the database:

1) FROM
2) JOIN
3) ON
4) SELECT


Execution Flow:

Step 1
Load Employees table.

Step 2
Join EmployeeUNI based on id.

Step 3
Create combined rows.

Step 4
Return selected columns.


------------------------------------------------------------
9. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Specifies the columns returned in the result.

2) FROM
Defines the base table.

3) LEFT JOIN
Combines rows from two tables while
keeping all rows from the left table.

4) ON
Defines the join condition between tables.


------------------------------------------------------------
10. Understanding Joins Using Set Theory
------------------------------------------------------------

Tables can be thought of as mathematical sets.

Employees = Set A
EmployeeUNI = Set B

JOIN operations behave like set operations.


INNER JOIN

Returns only rows that exist in both sets.

Set representation:

A ∩ B

Example:

Employees ∩ EmployeeUNI


LEFT JOIN

Returns:

All rows from A
plus matching rows from B.

Set representation:

A + (A ∩ B)


RIGHT JOIN

Returns:

All rows from B
plus matching rows from A.

Set representation:

B + (A ∩ B)


FULL JOIN

Returns all rows from both tables.

Set representation:

A ∪ B


For this problem:

We use LEFT JOIN because we must
keep every employee even if they
do not have a unique_id.


------------------------------------------------------------
11. Performance Considerations
------------------------------------------------------------

For large datasets:

The join condition is evaluated repeatedly:

Employees.id = EmployeeUNI.id

To optimize performance,
an index on EmployeeUNI.id is beneficial.

Without indexes, the database may
perform full table scans.

However, for small datasets this
query executes very quickly.


------------------------------------------------------------
12. Edge Cases
------------------------------------------------------------

Case 1: Employee without unique_id

Example:

Employee exists in Employees
but not in EmployeeUNI.

Result:

unique_id = NULL


Case 2: All employees have unique_id

LEFT JOIN behaves like INNER JOIN
because every row has a match.


Case 3: Empty EmployeeUNI table

All employees will appear with:

unique_id = NULL


------------------------------------------------------------
13. Interview Insights
------------------------------------------------------------

This problem tests:

1) Understanding relationships between tables
2) Correct usage of LEFT JOIN
3) Ability to preserve rows from one table
4) Knowledge of NULL results from joins


Common mistakes candidates make:

1) Using INNER JOIN instead of LEFT JOIN

This removes employees without unique_id.


2) Forgetting the ON condition

This creates a Cartesian product.


3) Selecting incorrect columns.


------------------------------------------------------------
14. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:

LEFT JOIN Lookup


General Pattern:

SELECT columns
FROM primary_table
LEFT JOIN lookup_table
ON primary_table.key = lookup_table.key


Common real-world use cases:

- Employees → Departments
- Orders → Customers
- Users → Profiles
- Products → Categories


------------------------------------------------------------
15. Key Learning Points
------------------------------------------------------------

1) Joins combine rows from multiple tables.

2) LEFT JOIN keeps all rows from the left table.

3) Missing matches produce NULL values.

4) Join conditions define relationships
   between tables.

5) SQL joins can be understood using
   set theory concepts.

6) LEFT JOIN is one of the most common
   operations in analytics and data engineering.

============================================================
END OF NOTES
============================================================
*/