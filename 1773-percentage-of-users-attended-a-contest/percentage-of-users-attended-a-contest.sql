# Write your MySQL query statement below

SELECT r.contest_id ,ROUND(COUNT(*) * 100 / (SELECT COUNT(*) FROM users), 2)
AS percentage 
FROM users u
JOIN register r
ON u.user_id = r.user_id
GROUP BY contest_id
ORDER BY percentage DESC, r.contest_id;