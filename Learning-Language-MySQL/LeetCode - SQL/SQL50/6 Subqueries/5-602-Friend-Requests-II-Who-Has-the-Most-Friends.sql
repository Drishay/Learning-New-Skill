# Write your MySQL query statement below
WITH table1 AS
(
    (
        SELECT
        requester_id AS people,
        COUNT(accepter_id) AS friend_count,
        GROUP_CONCAT(accepter_id ORDER BY accepter_id SEPARATOR ',') AS friends
        FROM RequestAccepted
        GROUP BY requester_id

    )
    /*
    | people | friend_count | friends |
    | ------ | ------------ | ------- |
    | 1      | 2            | 2,3     |
    | 2      | 1            | "3"     |
    | 3      | 1            | "4"     |
    */
    -- Quotes around single values like "3" or "4" are just display formatting; GROUP_CONCAT() returns all values as strings.

    UNION ALL 

    (
        SELECT
        accepter_id AS people,
        COUNT(requester_id) AS friend_count,
        GROUP_CONCAT(requester_id ORDER BY requester_id SEPARATOR ',') AS friends
        FROM RequestAccepted
        GROUP BY accepter_id
    )
    /*
    | people | friend_count | friends |
    | ------ | ------------ | ------- |
    | 2      | 1            | "1"     |
    | 3      | 2            | 1,2     |
    | 4      | 1            | "3"     |
    */

    # After Union ALL
    /*
    | people | friend_count | friends |
    | ------ | ------------ | ------- |
    | 1      | 2            | 2,3     |
    | 2      | 1            | "3"     |
    | 3      | 1            | "4"     |
    | 2      | 1            | "1"     |
    | 3      | 2            | 1,2     |
    | 4      | 1            | "3"     |
    */
)

-- SELECT people, SUM(friend_count) as friend_count, GROUP_CONCAT(friends ORDER BY friends SEPARATOR ',') AS all_friends
-- FROM table1 
-- GROUP BY people;
/*
| people | friend_count | all_friends |
| ------ | ------------ | ----------- |
| 1      | 2            | 2,3         |
| 2      | 2            | 1,3         |
| 3      | 3            | 1,2,4       |
| 4      | 1            | "3"         |
*/

SELECT people AS id, SUM(friend_count) as num
FROM table1 
GROUP BY people
ORDER BY num DESC
LIMIT 1;

/*
SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
) AS friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;
*/