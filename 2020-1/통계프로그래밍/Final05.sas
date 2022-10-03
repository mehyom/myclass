DATA ex_5;
INPUT candid $ gender $ edu $ count;
CARDS;
 park m 1 89
 park m 2 159
 park m 3 232
 park f 1 137
 park f 2 172
 park f 3 167
 moon m 1 28
 moon m 2 102
 moon m 3 278
 moon f 1 37
 moon f 2 93
 moon f 3 217
;
RUN;
PROC TABULATE DATA=ex_5 ORDER=DATA FORMAT=3.0;
 CLASS gender edu candid;
 VAR count;
 TABLE gender*edu, candid*count;
RUN;
PROC FREQ DATA=ex_5;
 WEIGHT count;
 TABLES candid*gender/ NOCOL NOPERCENT CHISQ MEASURES;
RUN;
