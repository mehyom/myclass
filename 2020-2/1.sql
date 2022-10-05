DROP TABLE IF EXISTS Summer; /* 기존 테이블이 있으면 삭제 */ 
CREATE TABLE Summer 
( sid INTEGER, 
class VARCHAR(20), 
price INTEGER 
); 
INSERT INTO Summer VALUES (100, 'FORTRAN', 20000); 
INSERT INTO Summer VALUES (150, 'PASCAL', 15000); 
INSERT INTO Summer VALUES (200, 'C', 10000); 
INSERT INTO Summer VALUES (250, 'FORTRAN', 20000); 
/* 생성된 Summer 테이블 확인 */ 
SELECT * 
FROM Summer; /* 기존 테이블이 있으면 삭제하고 새로 생성하기 위한 준비 */ 
DROP TABLE IF EXISTS SummerPrice; 
DROP TABLE IF EXISTS SummerEnroll; 
/* SummerPrice 테이블 생성 */ 
CREATE TABLE SummerPrice (class VARCHAR(20), price integer); 
INSERT INTO SummerPrice VALUES ('FORTRAN', 20000); 
INSERT INTO SummerPrice VALUES ('PASCAL', 15000); 
INSERT INTO SummerPrice VALUES ('C', 10000); 
SELECT * FROM SummerPrice; 
/* SummerEnroll 테이블 생성 */ 
CREATE TABLE SummerEnroll (sid integer, class VARCHAR(20)); 
INSERT INTO SummerEnroll VALUES (100, 'FORTRAN'); 
INSERT INTO SummerEnroll VALUES (150, 'PASCAL'); 
INSERT INTO SummerEnroll VALUES (200, 'C'); 
INSERT INTO SummerEnroll VALUES (250, 'FORTRAN'); 
SELECT * FROM SummerEnroll; 

