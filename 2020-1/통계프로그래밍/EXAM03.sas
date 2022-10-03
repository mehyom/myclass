DATA ex5;
INPUT @1 id $1. @5 amount 4. @12 date MMDDYY8.;
CARDS;
a   1000   03/06/00
a    375   03/15/00
a    900   07/15/00
b    500   03/01/00
b    400   03/15/00
a    550   03/01/00
b   1050   06/01/00
b    330   07/15/00
a   1500   06/01/00
a    800   06/30/00
b    575   06/30/00
;
RUN;
PROC SORT data=ex5; BY id date; RUN;
DATA mydata;
SET ex5;
FORMAT date DATE7.;
BY id;
IF LAST.id=1;
RUN;
PROC PRINT data=mydata;
RUN;
