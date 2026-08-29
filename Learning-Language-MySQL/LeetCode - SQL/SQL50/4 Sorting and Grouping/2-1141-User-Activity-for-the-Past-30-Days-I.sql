# Write your MySQL query statement below

-- the question statement make zero sense? Very poorly worded / wrong description.
-- How do you define an active user????????

-- using generative AI, to find the correct meaning for the quesition

/* Reframe the questions
Look at the Activity table and consider only the 30 days from June 28, 2019 to July 27, 2019.
WHY? 28 JUNE 2019 TO 27 JULY 2019?
IMP:
The question says to count the activity for a **30-day period ending on July 27, 2019, inclusively**.
This means **July 27, 2019 is the last day**, and when we count backward for 30 days, the period starts on **June 28, 2019**.
So, the 30-day period is **from June 28, 2019 through July 27, 2019, including both dates**.

For each day in that period, find how many different users did at least one activity on that day.
Return one row for each day where at least one user was active.
*/

SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date;