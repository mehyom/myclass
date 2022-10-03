DATA ex_1;
 INPUT id 1-3 gender $ 4 agegrp 5 item1 6 item2 7 item3 8; item= item1+item2+item3;
 CARDS;
001M1123
002F3452
003M2421
004F4531
005F4321
;
RUN;
PROC SORT DATA=ex_1 OUT=data;
BY DESCENDING item;
RUN;
DATA F_data;
SET data; 
IF gender='F';
RUN;
PROC PRINT DATA=F_data;
RUN;
PROC FORMAT;
 VALUE $new_gender 'M' = 'Male' 'F' = 'Female';
 VALUE new_agegrp 1 = '20세이하' 2 = '21세이상 40세이하' 3 = '41세이상 50세이하' 4 = '51세이상' 5 = '60세이상';
RUN;
PROC PRINT DATA=ex_1;
FORMAT gender $new_gender. agegrp new_agegrp.;
RUN;
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
