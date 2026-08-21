-- 1
with table1 as (select managerID, count(*) as report
from employee
group by managerId),

table2 as (select managerId
from table1
where report>=5)

select e.name
from employee as e
join table2 as t
on e.id = t.managerId;

--2
with table1 as (select managerID, count(*) as report
from employee
group by managerId),

table2 as (select managerId
from table1
where report>=5)

select e.name
from employee as e
join table2 as t
on e.id = t.managerId;

--3
with table1 as (select managerID, count(*) as report
from employee
group by managerId),

table2 as (select managerId
from table1
where report>=5)

select e.name
from employee as e
join table2 as t
on e.id = t.managerId;

--4
with table1 as (select managerID, count(*) as report
from employee
group by managerId),

table2 as (select managerId
from table1
where report>=5)

select e.name
from employee as e
join table2 as t
on e.id = t.managerId;

--5
with table1 as (select managerID, count(*) as report
from employee
group by managerId),

table2 as (select managerId
from table1
where report>=5)

select e.name
from employee as e
join table2 as t
on e.id = t.managerId;





