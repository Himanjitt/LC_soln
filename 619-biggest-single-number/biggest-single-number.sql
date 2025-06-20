# Write your MySQL query statement below
SELECT (
    SELECT num
    FROM mynumbers
    GROUP BY num
    HAVING COUNT(*) = 1 
    ORDER BY num desc limit 1
)
as num;