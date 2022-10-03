DATA inform;
 INPUT @1 hiredate YYMMDD8.
       @9 name$ 7.
       @16 gender$ 1.
       @17 age 2.
       @19 height 3.
       @22 weight 2.
       @24 salary COMMA5.
;
CARDS;
98/09/30박 미나F23155442,440
01/09/03강 유정F21160521,940
95/08/06이 홍구M46172803,290
08/01/05홍 정기M30180753,000
05/12/15김 민희F40165554,000
05/01/01유 태종M50177825,000
00/06/01최 원주F25170543,510
;
RUN;
PROC PRINT data = inform;
RUN;

DATA name;
 SET inform;
firstname = SUBSTR(name,3,5);
lastname = SUBSTR(name,1,2);
new_name = CATX(' ',firstname,lastname);
KEEP name new_name;
RUN;
PROC PRINT data = name;
RUN;
