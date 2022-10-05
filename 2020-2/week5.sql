/*
3-2 SQL 개요
*/
use madang;

show tables;
show table status;
describe book;
/* desc book; */
/*
select *
from book;
*/

select bookname, publisher, price
from book
where bookname LIKE '축구의 역사';

select phone
from customer
where name='김연아';

/*
3-3-1 select 문
*/

select bookname, price
from book;

select price, bookname
from book;

select bookid, bookname, publisher, price
from book;

select *
from book;

select publisher
from book;

select distinct publisher
from book;

select *
from book
where price < 20000;

select *
from book
where price between 10000 and 20000;

select *
from book
where price >= 10000 and price <= 20000;

select *
from book
where publisher in ('굿스포츠', '대한미디어');

select *
from book
where publisher not in ('굿스포츠', '대한미디어');

select bookname, publisher
from book
where bookname like '축구의 역사';

select bookname, publisher
from book
where bookname like '%축구%';
#where bookname like '축구%';
#where bookname like '%축구';

select *
from book
where bookname like '_구%';
#where bookname like '__구%';

select *
from book
where bookname like '%축구%' and price >= 20000;

select *
from book
where publisher='굿스포츠' or publisher='대한미디어';

select *
from book
order by bookname;

select *
from book
order by price, bookname;

select *
from book
order by price desc, publisher asc;
#order by price desc, publisher;

select * from orders;

select sum(saleprice)
from orders;

select sum(saleprice) as 총매출
#select sum(saleprice) as '총매출'
from orders;

select sum(saleprice) as 총매출
from orders
where custid=2;

select sum(saleprice) as Total, avg(saleprice) as Average, min(saleprice) as Minimum, max(saleprice) as Maximum
from orders;

select count(*)
from orders;

select custid, count(*) as 도서수량, sum(saleprice) as 총액
from orders
group by custid;

select custid, count(*) as 도서수량
from orders
where saleprice >= 8000
group by custid
having count(*) >= 2;

/*
연습문제
*/

#1-1
select bookname
from book
where bookid =1;
#where bookid like 1;

#1-2
select bookname, price
from book
where price >= 20000
order by price;

#1-3
select custid, name
from customer
where name like '%박지성%';

select sum(saleprice)
from orders
where custid = 1;

select custid, sum(saleprice)
from orders
group by custid;

#1-4
select count(*)
from orders
where custid=1;

select custid, count(*)
from orders
group by custid;
