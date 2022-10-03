DATA ex_3;
INPUT raw $ ing gram;
CARDS;
 A 1 7.5
 A 2 7.8
 A 3 8.5
 A 4 8.7
 A 5 8.6
 A 6 7.9
 A 7 7.8
 A 8 7.7
 A 9 8.3
 A 10 8.2
 B 1 8.0
 B 2 7.6
 B 3 7.9
 B 4 7.6
 B 5 7.7
 B 6 8.0
 B 7 7.2
 B 8 7.3
 B 9 7.4
 B 10 8.1
;
RUN;
PROC TTEST DATA=ex_3;
 CLASS raw;
 VAR gram;
RUN;
