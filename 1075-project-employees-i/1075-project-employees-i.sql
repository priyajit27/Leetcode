# Write your MySQL query statement below
SELECT project_id,ROUND(avg(experience_years),2) as average_years FROM 
Project as a LEFT JOIN Employee as b
ON a.employee_id=b.employee_id
GROUP BY project_id;

