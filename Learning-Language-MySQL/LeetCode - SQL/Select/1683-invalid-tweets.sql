/*
============================================================
SQL NOTES
Problem: LeetCode 1683 — Invalid Tweets
Difficulty: Easy
SQL Pattern: String Length Filtering
============================================================

------------------------------------------------------------
1. Problem Summary
------------------------------------------------------------

We are given a table called "Tweets".

Each row represents a tweet written by a user.

The task is to find tweets that are considered invalid.

A tweet is invalid if the number of characters
in the tweet content is greater than 15.

We must return the tweet_id of such tweets.


------------------------------------------------------------
2. Table Structure
------------------------------------------------------------

Table: Tweets

+-----------+---------+
| tweet_id  | content |
+-----------+---------+
| INT       | VARCHAR |
+-----------+---------+

Column Description:

tweet_id → Unique identifier for each tweet
content  → Text content of the tweet


------------------------------------------------------------
3. Keys & Constraints
------------------------------------------------------------

Primary Key:
tweet_id

Meaning:
Each tweet appears only once in the table.

content is a text field containing the tweet message.


------------------------------------------------------------
4. Problem Logic
------------------------------------------------------------

We must identify tweets where the content length
is greater than 15 characters.

This requires measuring the length of the string
in the content column.

Condition:

LENGTH(content) > 15

If the condition is TRUE, the tweet is invalid
and its tweet_id should appear in the result.


------------------------------------------------------------
5. My Original Query
------------------------------------------------------------

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;


------------------------------------------------------------
6. Correct Query
------------------------------------------------------------

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;


------------------------------------------------------------
7. Query Explanation (Logical Steps)
------------------------------------------------------------

Step 1 — Load the table

FROM Tweets

The database reads all rows from the Tweets table.


Step 2 — Calculate string length

LENGTH(content)

This function returns the number of characters
in the tweet content.


Example:

Original Table

+-----------+----------------------+
| tweet_id  | content              |
+-----------+----------------------+
| 1         | Let us code          |
| 2         | More than fifteen... |
+-----------+----------------------+

Length calculation:

"Let us code" → 11 characters
"More than fifteen..." → > 15 characters


Step 3 — Apply filtering condition

WHERE LENGTH(content) > 15

Rows with content longer than 15 characters
are selected.


Step 4 — Return tweet_id

SELECT tweet_id

Final Output Example

+----------+
| tweet_id |
+----------+
| 2        |
+----------+


------------------------------------------------------------
8. SQL Execution Order (Database Engine Insight)
------------------------------------------------------------

Actual SQL execution order:

1) FROM
2) WHERE
3) SELECT


Execution Flow:

Step 1: FROM
The database loads the Tweets table.

Step 2: WHERE
For each row, the database evaluates:

LENGTH(content) > 15

Rows satisfying the condition are kept.

Step 3: SELECT
The tweet_id column is returned for the
remaining rows.


------------------------------------------------------------
9. SQL Concepts Used
------------------------------------------------------------

1) SELECT
Specifies the column returned in the result.

2) FROM
Specifies the source table.

3) WHERE
Filters rows based on a condition.

4) String Function: LENGTH()
Returns the number of characters in a string.


------------------------------------------------------------
10. Performance Considerations
------------------------------------------------------------

For large datasets:

The database must compute LENGTH(content)
for each row.

This typically results in a full table scan.

Indexes generally cannot be used efficiently
with functions like LENGTH(content).

However, since this is a simple query,
performance impact is minimal for typical datasets.


------------------------------------------------------------
11. Edge Cases
------------------------------------------------------------

Case 1: Content length exactly 15

Example:

"abcdefghijklmno" → length = 15

Result:
Not returned (because condition is > 15).


Case 2: Content length greater than 15

Example:

"abcdefghijklmnoq"

Result:
Returned as invalid.


Case 3: Empty content

Length = 0

Result:
Not returned.


Case 4: Very long tweets

Still correctly detected because
LENGTH(content) > 15.


------------------------------------------------------------
12. Interview Insights
------------------------------------------------------------

This question tests:

1) Basic filtering using WHERE
2) String functions in SQL
3) Understanding problem constraints


Common mistakes candidates make:

1) Using >= instead of >

Wrong example:

WHERE LENGTH(content) >= 15

This incorrectly includes tweets with exactly
15 characters.


2) Forgetting the LENGTH() function

Trying to compare the string directly.


------------------------------------------------------------
13. SQL Pattern Recognition
------------------------------------------------------------

Pattern Type:

STRING LENGTH FILTERING


General Pattern:

SELECT column_list
FROM table_name
WHERE LENGTH(string_column) operator value


Examples of real-world use cases:

- Detect long messages
- Validate username length
- Filter text-based inputs
- Enforce content size limits


------------------------------------------------------------
14. Key Learning Points
------------------------------------------------------------

1) LENGTH() is used to measure the number
   of characters in a string.

2) String functions can be used inside
   WHERE conditions.

3) Pay attention to strict vs inclusive
   conditions (> vs >=).

4) Text validation queries are common in
   real-world applications.

5) Simple queries often test understanding
   of built-in SQL functions.

============================================================
END OF NOTES
============================================================
*/