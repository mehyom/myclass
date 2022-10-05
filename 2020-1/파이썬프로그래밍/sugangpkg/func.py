import __init__
from tkinter import *
from tkinter.filedialog import *
from tkinter.filedialog import askopenfilename
from tkinter.filedialog import asksaveasfilename

stus = {}
subs = {}
grds = {}

def quit(self):
    self.destroy()

def corid(id): # 학생 아이디가 올바른지 검사
    id = id.get()
    result = id in stus
    return result
   
def save(): # 저장
    stufile = open("student.txt", "w")
    for i in stus.keys():
        stufile.write("%s %s %s\n" %(stus[i].id, stus[i].name, stus[i].dept))
    stufile.close()

    subfile = open("subject.txt", "w")
    for i in subs.keys():
        subfile.write("%s %s %s\n" %(subs[i].id, subs[i].name, subs[i].prof))
    subfile.close()
    subfile.close()

    grdfile = open("grade.txt", "w")
    for i in grds.keys():
        grdfile.write("%s %s\n" %(grds[i].id, grds[i].grade))
    grdfile.close()
    grdfile.close()

def load(): # 불러오기
    stufile = open("student.txt", "r")
    line = stufile.readline().rstrip()
    while line != "":
        a = __init__.Student()
        a.id = line[:6]
        a.name = line[7:10]
        a.dept = line[11:]
        stus[a.id] = a
        line = stufile.readline().rstrip()
    stufile.close()

    subfile = open("subject.txt", "r")
    line = subfile.readline().rstrip()
    while line != "":
        b = __init__.Subject()
        b.id = line[:6]
        b.name = line[7:-4]
        b.prof = line[-3:]
        subs[b.id] = b
        line = subfile.readline().rstrip()
    subfile.close()

    grdfile = open("grade.txt", "r")
    line = grdfile.readline().rstrip()
    while line != "":
        c = __init__.Grade()
        c.id = line[:12]
        c.grade = line[13:14]
        grds[c.id] = c
        line = grdfile.readline().rstrip()
    grdfile.close()
        

def omysub(id): # 학생이 id로 전체 과목과 수강중 과목 출력
    print("-" * 50)
    print("")
    print(" ***수강 중인 과목*** \n")
    id = id.get()
    for i in grds.keys():
        if (grds[i].id[:6] == id):
            if(grds[i].grade == ""):
                print("학수번호: %s   과목명: %s   담당교수: %s"
                    %(subs[i[6:]].id, subs[i[6:]].name, subs[i[6:]].prof))
    print("-" * 50)
    print("")
    print(" ***전체 과목 목록*** \n")
    for j in subs.keys():
        print("학수번호: %s   과목명: %s   담당교수: %s"
                    %(subs[j].id, subs[j].name, subs[j].prof))
    print("-" * 50)
    print("")

def oaddsub(stuid, subid, new): # 학생이 과목id로 수강 신청
    stuid = stuid.get()
    subid = subid.get()
    grdid = stuid + subid
    if((subid in subs) == False):
        print("존재하지 않는 과목입니다\n")
    elif((grdid in grds) == True):
        print("이미 수강한 과목입니다\n")
    else:
        a = __init__.Grade()
        a.id = grdid
        a.score = ""
        grds[grdid] = a
        print("정상적으로 수강신청 되었습니다\n")
    quit(new)

def odelsub(stuid, subid, new): # 학생이 과목id로 수강 철회
    stuid = stuid.get()
    subid = subid.get()
    grdid = stuid + subid
    if((subid in subs) == False):
        print("존재하지 않는 과목입니다\n")
    elif((grdid in grds) == False):
        print("수강한 적 없는 과목입니다\n")
    elif(grds[grdid].grade != ""):
        print("성적 등록이 되어 철회할 수 없습니다\n")
    else:
        del(grds[grdid])
        print("정상적으로 수강철회 되었습니다\n")
    quit(new)

def omygrd(id): # 학생이 id로 성적 출력
    print("-" * 50)
    print("")
    print(" ***성적 정보*** \n")
    id = id.get()
    for i in grds.keys():
        if (i[:6] == id):
            if(grds[i].grade != ""):
                print("학수번호: %s   과목명: %s   담당교수: %s   성적: %s"
                  %(subs[i[6:]].id, subs[i[6:]].name, subs[i[6:]].prof, grds[i].grade))
    print("-" * 50)
    print("")

def allstu():
    print("-" * 50)
    print("")
    print(" ***전체 학생 목록*** \n")
    for i in stus.keys():
        print("학번: %s   이름: %s   학과: %s"
              %(stus[i].id, stus[i].name, stus[i].dept))
    print("-" * 50)
    print("")

def schstu(id, new): # id로 학생 조회
    id = id.get()
    p = id in stus
    if(p == False):
        print("존재하지 않는 학생 정보입니다\n")
    else:
        print(" ***조회하신 학생 정보입니다*** ")
        print("학번: %s 이름: %s 학과: %s\n"
              %(stus[id].id, stus[id].name, stus[id].dept))
    quit(new)

def addstu(id, name, dept, new): # 학생 신규 등록
    id = id.get()
    name = name.get()
    dept = dept.get()
    p = id in stus
    if(p == True):
        print("이미 존재하는 학생 정보입니다\n")
    elif(id == "" or name == "" or dept == ""):
        print("학생 정보를 제대로 입력해주세요\n")
    else:
        a = __init__.Student()
        a.id = id
        a.name = name
        a.dept = dept
        stus[id] = a
        print("정상적으로 학생 정보가 등록 되었습니다\n")
    quit(new)

def edtstu(id, name, dept, new): # 학생 정보 편집
    id = id.get()
    name = name.get()
    dept = dept.get()
    p = id in stus
    if(p == False):
        print("존재하지 않는 학생 정보입니다\n")
    else:
        if(name == "" and dept == ""):
            print("변경 사항을 제대로 입력해주세요\n")
        else:
            if(name != ""):
                stus[id].name = name
            if(dept != ""):
                stus[id].dept = dept
            print("정상적으로 학생 정보가 수정 되었습니다\n")
    quit(new)

def delstu(id, new): # id로 학생 정보 삭제
    id = id.get()
    p = id in stus
    if(p == False):
        print("존재하지 않는 학생 정보입니다\n")
    else:
        del(stus[id])
        print("정상적으로 학생 정보가 삭제 되었습니다\n")
    quit(new)

def addsub(id, name, prof, new): # 강의 개설
    id = id.get()
    name = name.get()
    prof = prof.get()
    p = id in subs
    if(p == True):
        print("이미 개설된 강의입니다\n")
    elif(name != "" and prof != ""):
        a = __init__.Student()
        a.id = id
        a.name = name
        a.prof = prof
        subs[id] = a
        print("정상적으로 강의가 개설 되었습니다\n")
    else:
        print("과목명과 교수명을 제대로 입력해주세요\n")
    quit(new)

def delsub(id, new): # 폐강
    id = id.get()
    p = id in subs
    if(p == False):
        print("개설되지 않은 강의입니다\n")
    else:
        del(subs[id])
        print("정상적으로 강의가 폐강 되었습니다\n")
    quit(new)

def editgrd(stuid, subid, grade, new): # 성적 정정, 등록
    stuid = stuid.get()
    subid = subid.get()
    grade = grade.get()
    id = stuid + subid
    p = id in grds
    if(p == False):
        print("존재하지 않는 수강 정보입니다\n")
    else:
        if(grade != ""):
            grds[id].grade = grade
            print("정상적으로 성적 정보가 정정 되었습니다\n")
        else:
            print("성적 정보를 제대로 입력해주세요\n")
    quit(new)
