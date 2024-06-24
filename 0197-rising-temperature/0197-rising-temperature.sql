# Write your MySQL query statement below
SELECT DISTINCT a.id 
FROM
Weather as a
INNER JOIN Weather as b
ON  DATEDIFF(a.recordDate,b.recordDate)=1
AND a.temperature >b.temperature 
ORDER BY id ASC;