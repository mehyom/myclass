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
98/09/30�� �̳�F23155442,440
01/09/03�� ����F21160521,940
95/08/06�� ȫ��M46172803,290
08/01/05ȫ ����M30180753,000
05/12/15�� ����F40165554,000
05/01/01�� ����M50177825,000
00/06/01�� ����F25170543,510
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
