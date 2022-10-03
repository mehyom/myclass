DATA ex_4;
INPUT dice count;
CARDS;
 1 48
 2 51
 3 54
 4 45
 5 53
 6 49
;
RUN;
DATA ex_4_1;
SET ex_4;
prob = 50;
RUN;
PROC TTEST DATA=ex_4_1;
 PAIRED count*prob;
RUN;
