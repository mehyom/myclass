DATA Hw1_1;
 INFILE 'C:\Users\FAMILY\Desktop\hw1_1.csv'
        DLM=',' DSD FIRSTOBS=3;
 INPUT local$ numboy;
 LABEL local="�ñ�����" numboy="����(��)";
RUN;
DATA Hw1_2;
 INFILE 'C:\Users\FAMILY\Desktop\hw1_2.csv'
        DLM=',' DSD FIRSTOBS=3;
 INPUT local$ numgirl;
 LABEL local="�ñ�����" numgirl="����(��)";
RUN;
PROC SORT data=Hw1_1; BY local; RUN;
PROC SORT data=Hw1_2; BY local; RUN;
DATA Hw1_3;
  MERGE Hw1_1 Hw1_2;
  BY local;
RUN;
DATA Hw1_4;
  SET Hw1_3;
  state = '������';
  IF local="��û�ϵ�" then state="��û��";
  IF local="��û����" then state="��û��";
  IF local="����ϵ�" then state="����";
  IF local="���󳲵�" then state="����";
  IF local="���ϵ�" then state="���";
  IF local="��󳲵�" then state="���";
RUN;
