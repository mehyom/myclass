/*
3-4 데이터 정의어
*/
use madang;

CREATE TABLE newbook (
bookid INTEGER,
bookname VARCHAR(20),
publisher VARCHAR(20),
price INTEGER,
PRIMARY KEY (bookid));

drop table newbook;

CREATE TABLE newbook (
bookid INTEGER,
bookname VARCHAR(20),
publisher VARCHAR(20),
price INTEGER,
PRIMARY KEY (bookid));

#select *
#from newbook;

#show tables;
#show table status;
describe newbook;

drop table newbook;

CREATE TABLE newbook (
bookname VARCHAR(20),
publisher VARCHAR(20),
price INTEGER,
PRIMARY KEY (bookname,publisher));

describe newbook;
drop table newbook;

CREATE TABLE newbook (
bookname VARCHAR(20) not null,
publisher VARCHAR(20) unique,
price INTEGER default 10000 check(price>1000),
PRIMARY KEY (bookname,publisher));

describe newbook;

CREATE TABLE newcustomer(
custid integer primary key,
name varchar(40),
address varchar(40),
phone varchar(30));

CREATE TABLE neworders(
orderid integer,
custid integer not null,
bookid integer not null,
saleprice integer,
orderdate date,
primary key (orderid),
foreign key (custid) references newcustomer(custid) on delete cascade);

describe newcustomer;
describe neworders;

CREATE TABLE newbook (
bookid INTEGER,
bookname VARCHAR(20) not null,
publisher VARCHAR(20) unique,
price INTEGER default 10000 check(price>1000),
PRIMARY KEY (bookname,publisher));

alter table newbook add isbn varchar(13);
describe newbook;

alter table newbook modify isbn integer;
describe newbook;

alter table newbook drop column isbn;
describe newbook;

alter table newbook modify bookid integer not null;
describe newbook;

alter table newbook DROP primary key;
alter table newbook add primary key (bookid);
describe newbook;

drop table newbook;
drop table newcustomer;
#drop table neworders;

show tables;
#show table status;

/*
3-4 데이터 조작어
*/
insert into book(bookid, bookname, publisher, price)
	values (11,'스포츠 의학', '한솔의학서적', 90000);

insert into book values (12,'스포츠 의학', '한솔의학서적', 90000);

select *
from book;

insert into book(bookid, bookname, price, publisher)
	values (13,'스포츠 의학', 90000, '한솔의학서적');
    
insert into book(bookid, bookname, publisher)
	values (14,'스포츠 의학', '한솔의학서적');

select *
from book;

select *
from imported_book;

insert into book(bookid, bookname, publisher, price)
	select bookid, bookname, publisher, price
    from imported_book;

select *
from book;

select * from customer;

set sql_safe_updates=0;
update customer
set address='대한민국 부산'
where custid=5;

select * from customer;

update book
set publisher=(select publisher from imported_book where bookid=21)
where bookid=14;

select * from book;

delete from book
where bookid=11;

select * from book;

delete from customer;
