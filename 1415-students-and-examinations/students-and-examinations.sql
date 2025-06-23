# Write your MySQL query statement below
WITH cte AS(
    SELECT * 
    FROM students
    CROSS join subjects
),

cte2 AS(
    SELECT student_id, subject_name, COUNT(*) as attended_exams
    FROM examinations 
    GROUP BY student_id, subject_name
)

SELECT cte.student_id,  cte.student_name, cte.subject_name,
CASE WHEN attended_exams IS NOT NULL THEN attended_exams
ELSE 0 END AS attended_exams
FROM cte
LEFT JOIN cte2
ON cte.student_id = cte2.student_id
AND cte.subject_name = cte2.subject_name
ORDER BY cte.student_id , cte.subject_name;
