/*
3-3-3 두 개 이상 테이블에서의 SQL 질의
*/
use madang;

select *
from customer, orders;

select *
from customer, orders
where customer.custid = orders.custid;

select *
from customer, orders
where customer.custid = orders.custid
order by customer.custid desc;

select name, saleprice
from customer, orders
where customer.custid = orders.custid;

select name, sum(saleprice)
from customer, orders
where customer.custid = orders.custid
group by customer.name
order by customer.name;


select customer.name, book.bookname
from customer, orders, book
where customer.custid = orders.custid
and orders.bookid = book.bookid;

#select *
#from orders;

select customer.name, book.bookname
from customer, orders, book
where customer.custid = orders.custid
and orders.bookid = book.bookid
and book.price = 20000;

select customer.custid, customer.name, orders.saleprice
from customer left outer join orders
on customer.custid = orders.custid;

/*
# right outer join
select orders.saleprice, book.price
from orders right outer join book
on orders.bookid = book.bookid;
*/

/*
# inner join 1
select name, saleprice
from customer, orders
where customer.custid = orders.custid;
# inner join 2
select name, saleprice
from customer inner join orders 
on customer.custid = orders.custid;
*/

select bookname
from book
where price = (
select max(price)
from book);

select customer.name 
from customer
where custid in (
select custid
from orders);

select name
from customer
where custid in (
select custid
from orders
where bookid in (
select bookid
from book
where publisher = '대한미디어'));

select b1.bookname
from book b1
where b1.price > (
select avg(b2.price)
from book b2
where b2.publisher=b1.publisher);

/*
select bookname, price
from book
where price > (
select avg(price)
from book);
*/

select name
from customer
where address like '대한민국%'
union
#union all
select name
from customer
where custid in (select custid from orders);

select name
from customer
where address like '대한민국%' and
name not in (
#name in (
select name
from customer
where custid in (select custid from orders));

select name, address
from customer cs
where exists(
select *
from orders od
where cs.custid = od.custid);

/*
연습문제
*/
# 1-5
select name, count(publisher)
from book, customer, orders
where book.bookid=orders.bookid
and customer.custid = orders.custid
and customer.name like '박지성';

# 1-6
select name as '이름', bookname as '책이름', (price-saleprice) as '정가와 판매가격의 차이'
from book, customer, orders
where book.bookid=orders.bookid
and customer.custid = orders.custid
and customer.name like '박지성';

# 1-7
select name, bookname
from book, customer, orders
where book.bookid=orders.bookid
and customer.custid = orders.custid
and customer.name not in ('박지성');

