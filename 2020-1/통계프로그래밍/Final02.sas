DATA ex_2;
INPUT class $ place $ num;
CARDS;
H 1 30
H 2 20
H 3 10
M 1 20
M 2 40
M 3 10
L 1 10
L 2 40
L 3 20
;
RUN;
PROC FREQ data=ex_2;
 WEIGHT num;
 TABLES class*place/ NOPERCENT CHISQ MEASURES;
RUN;
