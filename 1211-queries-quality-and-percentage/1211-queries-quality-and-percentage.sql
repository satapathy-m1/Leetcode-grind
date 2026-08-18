# Write your MySQL query statement below
select DISTINCT q1.query_name, 
round((select sum(q2.rating/q2.position) from Queries q2 where 
        q1.query_name = q2.query_name) / (select count(*) from Queries q3 
        where q1.query_name = q3.query_name), 2) as quality,
round((select count(*) from Queries q2 where q2.rating < 3 and q2.query_name = q1.query_name)*100/(select count(*) from Queries q3 
        where q1.query_name = q3.query_name), 2) as poor_query_percentage
from Queries q1;
