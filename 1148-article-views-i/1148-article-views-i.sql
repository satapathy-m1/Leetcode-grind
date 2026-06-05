/* Write your PL/SQL query statement below */
select unique(author_id) as id from Views where author_id = viewer_id order by author_id;