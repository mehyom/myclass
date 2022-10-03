DATA data;
 INPUT id 1-3 gender $ 4 agegrp 5 item1 6 item2 7 item3 8; item= item1+item2+item3;
 CARDS;
001M1123
002F3452
003M2421
004F4531
005F4321
;
RUN;
PROC SORT DATA=data OUT=new_data;
BY DESCENDING item;
RUN;
DATA F_data;
SET new_data; 
IF gender='F';
RUN;
PROC PRINT DATA=F_data;
RUN;
PROC FORMAT;
 VALUE $new_gender 'M' = 'Male' 'F' = 'Female';
 VALUE new_agegrp 1 = '20세이하' 2 = '21세이상 40세이하' 3 = '41세이상 50세이하' 4 = '51세이상' 5 = '60세이상';
RUN;
PROC PRINT DATA=data;
FORMAT gender $new_gender. agegrp new_agegrp.;
RUN;
