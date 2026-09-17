# Write your MySQL query statement below
-- does order by help in lexicographically smaller movie name?
/*
Yes, ORDER BY helps you find the lexicographically smaller movie name.When you apply ORDER BY movie_name ASC (or 
just ORDER BY movie_name, since ascending is the default), the database sorts the text strings alphabetically/
lexicographically from A to Z. This means the lexicographically smallest name (like "Frozen 2" vs "Joker") will 
appear at the very top of your result set

Lexicographically means arranged or compared in the same sequential order as words in a dictionary, which is similar to alphabetical order.
How It Works
- Letter by letter: Words or text strings are compared character by character from left to right (e.g., comparing the first letter, then the second letter if the first ones match).
- Beyond words: The concept applies to numbers, symbols, and sequences. For example, in lexicographical order, "10" comes before "2" because '1' comes before '2' alphabetically.
- Computer science: Most users on Stack Overflow agree that in programming, comparing strings lexicographically means checking their underlying character values (like ASCII or Unicode values) to see which sequence comes first
*/

# FIRST HALF OF THE SOLUTION BEGIN
-- SELECT m.user_id, u.name, m.movie_id
-- FROM MovieRating m
-- LEFT JOIN Users u
-- ON m.user_id = u.user_id;

/*
| user_id | name   | movie_id |
| ------- | ------ | -------- |
| 1       | Daniel | 1        |
| 2       | Monica | 1        |
| 3       | Maria  | 1        |
| 4       | James  | 1        |
| 1       | Daniel | 2        |
| 2       | Monica | 2        |
| 3       | Maria  | 2        |
| 1       | Daniel | 3        |
| 2       | Monica | 3        |
*/

-- SELECT m.user_id, u.name, COUNT(m.movie_id) AS No_of_movies_rated
-- FROM MovieRating m
-- LEFT JOIN Users u
-- ON m.user_id = u.user_id
-- GROUP BY m.user_id;

/*
| user_id | name   | No_of_movies_rated |
| ------- | ------ | ------------------ |
| 1       | Daniel | 3                  |
| 2       | Monica | 3                  |
| 3       | Maria  | 2                  |
| 4       | James  | 1                  |
*/

-- NOW, for "user who has rated the greatest number of movies" sort the table by No_of_movies_rated in ascending order, "In case of a tie" sort the table by user name in descending for lexicographically smaller user name.

-- SELECT m.user_id, u.name, COUNT(m.movie_id) AS No_of_movies_rated
-- FROM MovieRating m
-- LEFT JOIN Users u
-- ON m.user_id = u.user_id
-- GROUP BY m.user_id
-- ORDER BY COUNT(m.movie_id) DESC, u.name ASC;

/*
| user_id | name   | No_of_movies_rated |
| ------- | ------ | ------------------ |
| 1       | Daniel | 3                  |
| 2       | Monica | 3                  |
| 3       | Maria  | 2                  |
| 4       | James  | 1                  |
*/

# NOW, I can use limit 1 and can just store the name as results 

-- SELECT u.name AS results
-- FROM MovieRating m
-- LEFT JOIN Users u
-- ON m.user_id = u.user_id
-- GROUP BY m.user_id
-- ORDER BY COUNT(m.movie_id) DESC, u.name ASC
-- LIMIT 1;

# First half of the solution ends
/*
| results |
| ------- |
| Daniel  |
*/


# SECOND HALF OF THE SOLUTION BEGIN
-- SELECT m.movie_id, Movies.title, m.rating, m.created_at
-- FROM MovieRating m
-- LEFT JOIN Movies 
-- ON m.movie_id = Movies.movie_id;

/*
| movie_id | title    | rating | created_at |
| -------- | -------- | ------ | ---------- |
| 1        | Avengers | 3      | 2020-01-12 |
| 1        | Avengers | 4      | 2020-02-11 |
| 1        | Avengers | 2      | 2020-02-12 |
| 1        | Avengers | 1      | 2020-01-01 |
| 2        | Frozen 2 | 5      | 2020-02-17 |
| 2        | Frozen 2 | 2      | 2020-02-01 |
| 2        | Frozen 2 | 2      | 2020-03-01 |
| 3        | Joker    | 3      | 2020-02-22 |
| 3        | Joker    | 4      | 2020-02-25 |
*/

-- grouping by MOVIE_ID, extacting AVG(rating), extracting movie rating only in February 2020
-- SELECT m.movie_id, Movies.title, AVG(m.rating), m.created_at
-- FROM MovieRating m
-- LEFT JOIN Movies 
-- ON m.movie_id = Movies.movie_id
-- GROUP BY m.movie_id
-- HAVING m.created_at BETWEEN '2020-02-01' AND '2020-02-29';
/*
| movie_id | title    | AVG(m.rating) | created_at |
| -------- | -------- | ------------- | ---------- |
| 2        | Frozen 2 | 3             | 2020-02-17 |
| 3        | Joker    | 3.5           | 2020-02-22 |
*/

# HAVING, filters after group by, and due to that i missed few valid rows data and added few INVALID row data, So, using  WHERE, filter first, thus, I have the correct data for grouping.

-- SELECT m.movie_id, Movies.title, AVG(m.rating), m.created_at
-- FROM MovieRating m
-- LEFT JOIN Movies 
-- ON m.movie_id = Movies.movie_id
-- WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
-- GROUP BY m.movie_id;
/*
| movie_id | title    | AVG(m.rating) | created_at |
| -------- | -------- | ------------- | ---------- |
| 1        | Avengers | 3             | 2020-02-11 |
| 2        | Frozen 2 | 3.5           | 2020-02-17 |
| 3        | Joker    | 3.5           | 2020-02-22 |
*/


# NOW, "Find the movie name with the highest average rating", I have to SORT the table by AVG(m.rating) IN descending order and "In case of a tie" I can use ORDER BY name in Ascending order for lexicographically smaller movie name 

-- SELECT m.movie_id, Movies.title, AVG(m.rating), m.created_at
-- FROM MovieRating m
-- LEFT JOIN Movies 
-- ON m.movie_id = Movies.movie_id
-- WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
-- GROUP BY m.movie_id
-- ORDER BY AVG(m.rating) DESC, Movies.title ASC;

/*
| movie_id | title    | AVG(m.rating) | created_at |
| -------- | -------- | ------------- | ---------- |
| 2        | Frozen 2 | 3.5           | 2020-02-17 |
| 3        | Joker    | 3.5           | 2020-02-22 |
| 1        | Avengers | 3             | 2020-02-11 |
*/

-- and NOW, I can use limit 1 such that i can just store the title as results.

-- SELECT Movies.title as results 
-- FROM MovieRating m
-- LEFT JOIN Movies 
-- ON m.movie_id = Movies.movie_id
-- WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
-- GROUP BY m.movie_id
-- ORDER BY AVG(m.rating) DESC, Movies.title ASC
-- LIMIT 1;

# Secomd half of the solution ends
/*
| results  |
| -------- |
| Frozen 2 |
*/

-- NOW, just using UNION

# First HALF OF THE SOLUTION
(
    SELECT u.name AS results
    FROM MovieRating m
    LEFT JOIN Users u
    ON m.user_id = u.user_id
    GROUP BY m.user_id
    ORDER BY COUNT(m.movie_id) DESC, u.name ASC
    LIMIT 1
)

-- UNION, is not supposed to be used here, as Movie title and user name could be same, and in UNION there are no duplicates allowed, thus use UNION ALL

UNION ALL

-- # Second HALF OF THE SOLUTION

(
    SELECT Movies.title as results 
    FROM MovieRating m
    LEFT JOIN Movies 
    ON m.movie_id = Movies.movie_id
    WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id
    ORDER BY AVG(m.rating) DESC, Movies.title ASC
    LIMIT 1
);

-- When using LIMIT and ORDER BY inside individual UNION queries, wrapping each subquery in parentheses is 
-- required by most SQL dialects (like MySQL) to prevent syntax errors.

/*
UNION vs UNION ALL — Short Notes

| Feature        | UNION                         | UNION ALL                    |
|----------------|-------------------------------|------------------------------|
| Duplicates     | Removes duplicate rows        | Keeps duplicate rows         |
| Performance    | Slower                        | Faster                       |
| Memory Usage   | Higher                        | Lower                        |
| Use When       | Need unique results           | Need all results             |
| Example        | SELECT city FROM A            | SELECT city FROM A           |
|                | UNION SELECT city FROM B;     | UNION ALL SELECT city FROM B;|

UNION:
- Combines result sets and removes duplicates.
- Similar to DISTINCT.
- Use when only unique values are required.

UNION ALL:
- Combines result sets and keeps duplicates.
- Faster because no duplicate-checking is required.
- Use when all rows are meaningful or performance matters.

Rules for UNION / UNION ALL:
1. Same number of columns in every SELECT.
2. Corresponding columns must have compatible data types.
3. Columns must be in the same order.
4. ORDER BY can be used only once, at the end.
*/


/* OTHER user solution
(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating mr
        ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(mr.movie_id) DESC, u.name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM Movies m
    JOIN MovieRating mr
        ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01'
      AND mr.created_at < '2020-03-01'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
);
*/