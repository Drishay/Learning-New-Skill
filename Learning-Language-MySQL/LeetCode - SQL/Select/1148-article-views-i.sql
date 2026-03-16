/*
============================================================
SQL NOTES
Problem: LeetCode 1148 — Article Views I
Difficulty: Easy
SQL Pattern: Self-Condition Filtering + Deduplication
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given a table called "Views".

Each row represents a view of an article.

The table stores:
- The author of the article
- The viewer who viewed the article
- The article id
- The date the view happened

The task is to find authors who viewed their own articles.

This means we need rows where:

author_id = viewer_id

However, the same author might view their own article
multiple times, so we must return each author only once.

Therefore, we must remove duplicates.

The output should contain only:

id (author_id)


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: Views

+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| INT        | INT       | INT       | DATE       |
+------------+-----------+-----------+------------+

Column Description:

article_id  → Unique identifier for the article
author_id   → Author of the article
viewer_id   → User who viewed the article
view_date   → Date when the article was viewed


------------------------------------------------------------
3. Keys & Constraints
------------------------------------------------------------

There is no primary key in this problem.

Multiple rows may exist for the same author because:

- An article can be viewed many times
- An author may view their own article multiple times

Therefore duplicates are possible.

We must ensure the final result contains
each author only once.


------------------------------------------------------------
4. Problem Logic
------------------------------------------------------------

We must identify rows where:

author_id = viewer_id

This means the author viewed their own article.

However, the same author may appear multiple times,
so we must remove duplicates.

Finally, we must rename the output column to "id"
and sort the results.


------------------------------------------------------------
5. My Original Query
------------------------------------------------------------

SELECT DISTINCT author_id
AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;


------------------------------------------------------------
6. Correct Query
------------------------------------------------------------

SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;


------------------------------------------------------------
7. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load the table

FROM Views

The database reads all rows from the Views table.


Step 2 — Apply filtering condition

WHERE author_id = viewer_id

This keeps rows where the author viewed their own article.


Example:

Original Table

+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2020-01-01 |
| 1          | 3         | 3         | 2020-01-02 |
| 2          | 4         | 4         | 2020-01-03 |
| 2          | 4         | 5         | 2020-01-04 |
+------------+-----------+-----------+------------+

Rows where author viewed their own article:

+------------+-----------+-----------+
| article_id | author_id | viewer_id |
+------------+-----------+-----------+
| 1          | 3         | 3         |
| 2          | 4         | 4         |
+------------+-----------+-----------+


Step 3 — Remove duplicates

SELECT DISTINCT author_id

If an author viewed their own article multiple times,
DISTINCT ensures they appear only once.


Step 4 — Rename column

AS id

This renames author_id to id in the final output.


Step 5 — Sort the result

ORDER BY id

Ensures the output appears in ascending order.


Final Output Example

+----+
| id |
+----+
| 3  |
| 4  |
+----+


------------------------------------------------------------
8. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual SQL execution order:

1) FROM
2) WHERE
3) SELECT
4) DISTINCT
5) ORDER BY


Detailed Flow:

Step 1: FROM
Load the Views table.

Step 2: WHERE
Filter rows where:

author_id = viewer_id

Step 3: SELECT
Extract the author_id column.

Step 4: DISTINCT
Remove duplicate author ids.

Step 5: ORDER BY
Sort the results by id.


------------------------------------------------------------
9. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Specifies the columns returned.

2) WHERE
Filters rows based on conditions.

3) DISTINCT
Removes duplicate rows from the result.

4) Column Alias (AS)
Renames a column in the output.

5) ORDER BY
Sorts the result set.


------------------------------------------------------------
10. Performance Considerations
------------------------------------------------------------

For large datasets:

The database may perform:

1) Table scan
2) Filtering operation
3) Deduplication (DISTINCT)

Possible optimization:

Index on:

(author_id, viewer_id)

This allows the database to quickly filter rows
where author_id = viewer_id.


------------------------------------------------------------
11. Edge Cases
------------------------------------------------------------

Case 1: Author never views their own article

No rows returned.


Case 2: Author views their own article multiple times

DISTINCT ensures only one record appears.


Example:

author_id = 3
viewer_id = 3 (multiple rows)

Final output still shows:

3


Case 3: Multiple authors view their own articles

Each author appears once in the output.


------------------------------------------------------------
12. Interview Insights
------------------------------------------------------------

This problem tests:

1) Equality filtering
2) Understanding duplicate rows
3) Using DISTINCT
4) Column aliasing


Common mistakes candidates make:

1) Forgetting DISTINCT

This causes duplicate author ids.


2) Returning author_id instead of alias id

Problem expects column name "id".


3) Forgetting ORDER BY when required


------------------------------------------------------------
13. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:

SELF-CONDITION FILTERING + DEDUPLICATION


General Pattern:

SELECT DISTINCT column
FROM table
WHERE column1 = column2


Common real-world scenarios:

- Users interacting with their own content
- Self-referential activity tracking
- Detecting self-actions in logs
- Identifying creators consuming their own content


------------------------------------------------------------
14. Key Learning Points
------------------------------------------------------------

1) DISTINCT removes duplicate rows.

2) Equality comparisons are common filtering patterns.

3) Column aliases improve output readability.

4) Always consider duplicate rows when querying logs
or event tables.

5) Simple problems often combine multiple basic SQL
concepts together.

============================================================
END OF NOTES
============================================================
*/