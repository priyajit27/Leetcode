# Write your MySQL query statement below
SELECT user_id,concat(upper(substring(name,1,1)),lower(substring(name,2,LENGTH(name)))) AS name FROM 
Users ORDER BY user_id ASC;