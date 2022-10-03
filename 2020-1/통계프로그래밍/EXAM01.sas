DATA Hw1_1;
 INFILE 'C:\Users\FAMILY\Desktop\hw1_1.csv'
        DLM=',' DSD FIRSTOBS=3;
 INPUT local$ numboy;
 LABEL local="시군구별" numboy="남자(명)";
RUN;
DATA Hw1_2;
 INFILE 'C:\Users\FAMILY\Desktop\hw1_2.csv'
        DLM=',' DSD FIRSTOBS=3;
 INPUT local$ numgirl;
 LABEL local="시군구별" numgirl="여자(명)";
RUN;
PROC SORT data=Hw1_1; BY local; RUN;
PROC SORT data=Hw1_2; BY local; RUN;
DATA Hw1_3;
  MERGE Hw1_1 Hw1_2;
  BY local;
RUN;
DATA Hw1_4;
  SET Hw1_3;
  state = '지역명';
  IF local="충청북도" then state="충청도";
  IF local="충청남도" then state="충청도";
  IF local="전라북도" then state="전라도";
  IF local="전라남도" then state="전라도";
  IF local="경상북도" then state="경상도";
  IF local="경상남도" then state="경상도";
RUN;
