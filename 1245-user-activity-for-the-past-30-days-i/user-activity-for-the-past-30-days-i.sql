# Write your MySQL query statement below

SELECT activity_date as day, COUNT(DISTINCT user_id) as active_users
FROM activity
WHERE activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY) 
AND '2019-07-27'
GROUP BY activity_date;