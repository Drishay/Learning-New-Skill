# Write your MySQL query statement below
WITH table1 as
(
    SELECT 
        id, 
        client_id, 
        driver_id, 
        city_id, 
        status, 
        request_at
    FROM Trips
    -- NO need for JOIN
    -- LEFT JOIN Users
    -- ON Trips.client_id = Users.users_id OR Trips.driver_id = Users.users_id
    -- WHERE Users.banned = "No";
    WHERE 
        (client_id IN (SELECT users_id FROM Users WHERE banned = "No" AND role = "client")) 
        AND
        (driver_id IN (SELECT users_id FROM Users WHERE banned = "No" AND role = "driver"))
        AND request_at BETWEEN '2013-10-01' and '2013-10-03'
)
/*
| id | client_id | driver_id | city_id | status              | request_at |
| -- | --------- | --------- | ------- | ------------------- | ---------- |
| 1  | 1         | 10        | 1       | completed           | 2013-10-01 |
| 3  | 3         | 12        | 6       | completed           | 2013-10-01 |
| 4  | 4         | 13        | 6       | cancelled_by_client | 2013-10-01 |
| 5  | 1         | 10        | 1       | completed           | 2013-10-02 |
| 7  | 3         | 12        | 6       | completed           | 2013-10-02 |
| 9  | 3         | 10        | 12      | completed           | 2013-10-03 |
| 10 | 4         | 13        | 12      | cancelled_by_driver | 2013-10-03 |
*/
SELECT request_at AS Day,
    ROUND(Sum(IF(status != "completed",1,0))/COUNT(status),2) AS 'Cancellation Rate'
FROM table1
GROUP BY request_at;

/* using sub queries
SELECT request_at AS Day,
    ROUND(Sum(IF(status != "completed",1,0))/COUNT(status),2) AS 'Cancellation Rate'
FROM 
(
    SELECT 
        id, 
        client_id, 
        driver_id, 
        city_id, 
        status, 
        request_at
    FROM Trips
    -- NO need for JOIN
    -- LEFT JOIN Users
    -- ON Trips.client_id = Users.users_id OR Trips.driver_id = Users.users_id
    -- WHERE Users.banned = "No";
    WHERE 
        (client_id IN (SELECT users_id FROM Users WHERE banned = "No" AND role = "client")) 
        AND
        (driver_id IN (SELECT users_id FROM Users WHERE banned = "No" AND role = "driver"))
        AND request_at BETWEEN '2013-10-01' and '2013-10-03'
) as a
GROUP BY request_at;
*/

/* other users solution
SELECT 
    t.request_at AS Day,
    CAST(
        ROUND(
            AVG(
                CASE 
                    WHEN t.status IN ('cancelled_by_driver', 'cancelled_by_client') 
                    THEN 1 
                    ELSE 0 
                END
            ),
            2
        ) AS DECIMAL(10, 2)
    ) AS `Cancellation Rate`
FROM Trips t
INNER JOIN Users u1 
    ON t.client_id = u1.users_id AND u1.banned = 'No'
INNER JOIN Users u2 
    ON t.driver_id = u2.users_id AND u2.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at
ORDER BY t.request_at;
*/