# Write your MySQL query statement below
-- SELECT
--     id,
--     SUM(IF(month = "Jan", revenue, 0)) as Jan_Revenue,
--     SUM(IF(month = "Feb", revenue, 0)) as Feb_Revenue,
--     SUM(IF(month = "Dec", revenue, 0)) as Dec_Revenue
-- FROM Department
-- GROUP BY id;
/*
| id | Jan_Revenue | Feb_Revenue | Dec_Revenue |
| -- | ----------- | ----------- | ----------- |
| 1  | 8000        | 7000        | 0           |
| 2  | 9000        | 0           | 0           |
| 3  | 0           | 10000       | 0           |
*/

/*
The opposite of IFNULL in MySQL is the NULLIF(expression1, expression2) function.
NULLIF compares two arguments and returns NULL if they are equal. 
If they are not equal, it returns the first argument.

Syntax and Example - SELECT NULLIF(your_column, 0) FROM your_table;

How it works:
If your_column is 0, it matches the second argument (0) and returns NULL.
If your_column is 5, they do not match, so it returns the first argument, 5.
*/

-- SELECT
--     id,
--     NULLIF(SUM(IF(month = "Jan", revenue, 0)),0) as Jan_Revenue,
--     NULLIF(SUM(IF(month = "Feb", revenue, 0)),0) as Feb_Revenue,
--     NULLIF(SUM(IF(month = "Dec", revenue, 0)),0) as Dec_Revenue
-- FROM Department
-- GROUP BY id;

/*
| id | Jan_Revenue | Feb_Revenue | Dec_Revenue |
| -- | ----------- | ----------- | ----------- |
| 1  | 8000        | 7000        | null        |
| 2  | 9000        | null        | null        |
| 3  | null        | 10000       | null        |
*/

-- logic works, completeing the solution
-- SELECT
--     id,
--     NULLIF(SUM(IF(month = "Jan", revenue, 0)),0) as Jan_Revenue,
--     NULLIF(SUM(IF(month = "Feb", revenue, 0)),0) as Feb_Revenue,
--     NULLIF(SUM(IF(month = "Mar", revenue, 0)),0) as Mar_Revenue,
--     NULLIF(SUM(IF(month = "Apr", revenue, 0)),0) as Apr_Revenue,
--     NULLIF(SUM(IF(month = "May", revenue, 0)),0) as May_Revenue,
--     NULLIF(SUM(IF(month = "Jun", revenue, 0)),0) as Jun_Revenue,
--     NULLIF(SUM(IF(month = "Jul", revenue, 0)),0) as Jul_Revenue,
--     NULLIF(SUM(IF(month = "Aug", revenue, 0)),0) as Aug_Revenue,
--     NULLIF(SUM(IF(month = "Sep", revenue, 0)),0) as Sep_Revenue,
--     NULLIF(SUM(IF(month = "Oct", revenue, 0)),0) as Oct_Revenue,
--     NULLIF(SUM(IF(month = "Nov", revenue, 0)),0) as Nov_Revenue,
--     NULLIF(SUM(IF(month = "Dec", revenue, 0)),0) as Dec_Revenue
-- FROM Department
-- GROUP BY id;

/*
Wrong Answer
16 / 17 testcases passed

Editorial
Input
Department =
| id | revenue | month |
| -- | ------- | ----- |
| 1  | 0       | Jan   |

Use Testcase
Output
| id | Jan_Revenue | Feb_Revenue | Mar_Revenue | Apr_Revenue | May_Revenue | Jun_Revenue | Jul_Revenue | Aug_Revenue | Sep_Revenue | Oct_Revenue | Nov_Revenue | Dec_Revenue |
| -- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| 1  | null        | null        | null        | null        | null        | null        | null        | null        | null        | null        | null        | null        |
Expected
| id | Jan_Revenue | Feb_Revenue | Mar_Revenue | Apr_Revenue | May_Revenue | Jun_Revenue | Jul_Revenue | Aug_Revenue | Sep_Revenue | Oct_Revenue | Nov_Revenue | Dec_Revenue |
| -- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| 1  | 0           | null        | null        | null        | null        | null        | null        | null        | null        | null        | null        | null        |
*/

-- because
-- The actual requirement
-- You need to distinguish between:
-- Month doesn't exist for this department → NULL
-- Month exists but revenue is 0 → 0
-- Your current approach cannot distinguish these because both eventually become 0.

-- Better approach: CASE
-- Use SUM(CASE...) together with a check for whether the month exists:
SELECT
    id,
    CASE WHEN COUNT(CASE WHEN month = 'Jan' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Jan' THEN revenue ELSE 0 END)
    END AS Jan_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Feb' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Feb' THEN revenue ELSE 0 END)
    END AS Feb_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Mar' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Mar' THEN revenue ELSE 0 END)
    END AS Mar_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Apr' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Apr' THEN revenue ELSE 0 END)
    END AS Apr_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'May' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'May' THEN revenue ELSE 0 END)
    END AS May_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Jun' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Jun' THEN revenue ELSE 0 END)
    END AS Jun_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Jul' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Jul' THEN revenue ELSE 0 END)
    END AS Jul_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Aug' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Aug' THEN revenue ELSE 0 END)
    END AS Aug_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Sep' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Sep' THEN revenue ELSE 0 END)
    END AS Sep_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Oct' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Oct' THEN revenue ELSE 0 END)
    END AS Oct_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Nov' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Nov' THEN revenue ELSE 0 END)
    END AS Nov_Revenue,

    CASE WHEN COUNT(CASE WHEN month = 'Dec' THEN 1 END) > 0
         THEN SUM(CASE WHEN month = 'Dec' THEN revenue ELSE 0 END)
    END AS Dec_Revenue

FROM Department
GROUP BY id;


/* other solution
SELECT
    id,
    MAX(CASE WHEN month = 'Jan' THEN revenue END) AS Jan_Revenue,
    MAX(CASE WHEN month = 'Feb' THEN revenue END) AS Feb_Revenue,
    MAX(CASE WHEN month = 'Mar' THEN revenue END) AS Mar_Revenue,
    MAX(CASE WHEN month = 'Apr' THEN revenue END) AS Apr_Revenue,
    MAX(CASE WHEN month = 'May' THEN revenue END) AS May_Revenue,
    MAX(CASE WHEN month = 'Jun' THEN revenue END) AS Jun_Revenue,
    MAX(CASE WHEN month = 'Jul' THEN revenue END) AS Jul_Revenue,
    MAX(CASE WHEN month = 'Aug' THEN revenue END) AS Aug_Revenue,
    MAX(CASE WHEN month = 'Sep' THEN revenue END) AS Sep_Revenue,
    MAX(CASE WHEN month = 'Oct' THEN revenue END) AS Oct_Revenue,
    MAX(CASE WHEN month = 'Nov' THEN revenue END) AS Nov_Revenue,
    MAX(CASE WHEN month = 'Dec' THEN revenue END) AS Dec_Revenue
FROM Department
GROUP BY id;
*/