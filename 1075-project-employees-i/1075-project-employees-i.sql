# Write your MySQL query statement below
Select P.project_id,round(AVG(E.experience_years),2) as average_years
from Employee E, Project P
where E.employee_id= P.employee_id
group by P.project_id;