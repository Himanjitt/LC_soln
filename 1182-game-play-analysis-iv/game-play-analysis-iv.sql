# Write your MySQL query statement below

SELECT ROUND(COUNT(a2.player_id) / COUNT(DISTINCT a1.player_id), 2) as fraction
FROM activity a1
LEFT JOIN (
    SELECT player_id, MIN(event_date) as start_date
    FROM activity 
    GROUP BY player_id
) as a2
ON a1.player_id = a2.player_id
AND DATE_SUB(a1.event_date, INTERVAL 1 DAY) = a2.start_date;

