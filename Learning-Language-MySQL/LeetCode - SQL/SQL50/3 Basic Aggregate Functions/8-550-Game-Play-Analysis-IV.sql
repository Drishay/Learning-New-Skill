# Write your MySQL query statement below
-- SELECT player_id, min(event_date)
-- FROM Activity
-- GROUP BY player_id;

/*
| player_id | min(event_date) |
| --------- | --------------- |
| 1         | 2016-03-01      |
| 2         | 2017-06-25      |
| 3         | 2016-03-02      |
*/

--  I have this table, i need to increase the date by +1, is there any way?
/*
Option 1: Using the DATE_ADD() Function (Recommended)Add an underscore to the function name and pass the INTERVAL keyword:
SELECT player_id, DATE_ADD(MIN(event_date), INTERVAL 1 DAY) AS next_date
FROM Activity
GROUP BY player_id;

Option 2: Using Simple Addition (+ INTERVAL)MySQL also allows you to directly add intervals with a plus sign:
SELECT player_id, MIN(event_date) + INTERVAL 1 DAY AS next_date
FROM Activity
GROUP BY player_id;

Option 3: Using ADDDATE()MySQL has a built-in shorthand called ADDDATE() that accepts just the number of days:
SELECT player_id, ADDDATE(MIN(event_date), 1) AS next_date
FROM Activity
GROUP BY player_id;

*/


WITH Table1 as 
(
    SELECT player_id, ADDDATE(MIN(event_date), 1) AS next_event_date
    FROM Activity
    GROUP BY player_id
),
/*
| player_id | next_event_date  |
| --------- | ---------------- |
| 1         | 2016-03-02       |
| 2         | 2017-06-26       |
| 3         | 2016-03-03       |
*/

Table2 AS
(
    SELECT next.player_id, next.next_event_date, old.event_date
    FROM Table1 AS next
    LEFT JOIN Activity AS old
    ON next.player_id = old.player_id AND next.next_event_date = old.event_date
)
/*
| player_id | next_event_date | event_date |
| --------- | --------------- | ---------- |
| 1         | 2016-03-02      | 2016-03-02 |
| 2         | 2017-06-26      | null       |
| 3         | 2016-03-03      | null       |
*/

SELECT ROUND(SUM(IF(event_date IS NOT NULL, 1, 0)) / COUNT(player_id),2) AS fraction
FROM Table2;

/*
| fraction |
| -------- |
| 0.33     |
*/