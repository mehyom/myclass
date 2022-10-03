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
 VALUE new_agegrp 1 = '20������' 2 = '21���̻� 40������' 3 = '41���̻� 50������' 4 = '51���̻�' 5 = '60���̻�';
RUN;
PROC PRINT DATA=data;
FORMAT gender $new_gender. agegrp new_agegrp.;
RUN;
