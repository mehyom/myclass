DATA exercise;
 INPUT method$ id score;
 CARDS;
  A 1 3.8
  A 2 5.0
  A 3 3.2
  A 4 3.4
  A 5 4.0
  A 6 3.8
  A 7 4.1
  A 8 2.9
  A 9 3.7
  B 1 3.9
  B 2 4.5
  B 3 4.3
  B 4 4.9
  B 5 3.5
  B 6 4.5
  B 7 4.3
  B 8 3.9
  B 9 4.1
;
RUN;
PROC TTEST DATA=exercise;
 CLASS method;
 VAR score;
RUN;
