# Write your MySQL query statement below
SELECT name,bonus
FROM
Employee as a 
LEFT JOIN Bonus as b
ON a.empId=b.empId
WHERE bonus IS NULL 
OR bonus<1000

