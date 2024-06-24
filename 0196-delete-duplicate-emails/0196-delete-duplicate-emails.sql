# Write your MySQL query statement below
DELETE a
FROM Person as a 
INNER JOIN Person as b
ON a.email=b.email
WHERE a.id>b.id
