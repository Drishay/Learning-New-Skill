# Write your MySQL query statement below

-- SELECT MIN(id) as id, email FROM Person GROUP BY email;
-- this fails, as questons specificaly says "For SQL users, please note that you are supposed to write a DELETE 
-- statement and not a SELECT one.", select logic is correct, its should give the same output, but we have to DELETE.

/*
To delete duplicate emails and keep only the row with the smallest ID in a SQL database, you can use a self-join.
 Match the duplicate email addresses where one row has a larger ID than another, and delete those larger ID rows.
*/

DELETE p1 
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id;


/*
# Write your MySQL query statement below
with cte as (
    select id 
    from (
        select email, min(id) as id from Person group by email
    )t
)

delete from Person where id not in (select * from cte);
*/