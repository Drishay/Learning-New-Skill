-- SELECT: Specifies which columns to retrieve from the table.
-- * means "all columns" in the Cinema table.

-- FROM: Indicates the source table from which data is fetched.
-- Here, data is being retrieved from the Cinema table.

-- WHERE: Filters rows based on given conditions.
-- id % 2 != 0 → selects rows where id is odd (not divisible by 2).
-- description != 'boring' → excludes rows where description is 'boring'.

-- ORDER BY: Sorts the result set.
-- rating DESC → sorts rows by rating in descending order (highest first).

SELECT *
FROM Cinema
WHERE id % 2 != 0 AND description != 'boring'
ORDER BY rating DESC;


-- =========================
-- QUERY EXECUTION FLOW
-- =========================

-- 1. FROM Cinema
--    → The database first identifies and accesses the Cinema table.

-- 2. WHERE id % 2 != 0 AND description != 'boring'
--    → Rows are filtered:
--       - Keep only rows with odd id values.
--       - Remove rows where description is 'boring'.

-- 3. SELECT *
--    → From the filtered rows, all columns are selected.

-- 4. ORDER BY rating DESC
--    → Final result is sorted by rating in descending order.

-- Final Output:
-- A list of all columns from Cinema table,
-- containing only non-boring movies with odd IDs,
-- sorted from highest to lowest rating.