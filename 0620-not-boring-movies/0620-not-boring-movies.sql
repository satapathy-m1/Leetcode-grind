# Write your MySQL query statement below
select * from cinema c
where c.id%2 <> 0 and c.description <> 'boring'
order by rating desc;