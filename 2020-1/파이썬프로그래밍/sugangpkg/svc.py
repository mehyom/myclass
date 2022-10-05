import func
from tkinter import *
from tkinter.filedialog import *
from functools import partial
import tkinter as tk

def stuaddsub(stuid):
    new = tk.Toplevel()
    new.geometry("250x30")
    new.resizable(width=FALSE, height=FALSE)
    new.title("수강 신청")

    subid = StringVar()
    subidLabel = Label(new, text="학수번호")
    subidLabel.grid(row=0,column=0)
    subidEntry = Entry(new, textvariable=subid)
    subidEntry.grid(row=0,column=1)

    com = partial(func.oaddsub, stuid, subid, new)
    button = tk.Button(new, text = " 신청 ", command = com)
    button.grid(row=0,column=2)
    
def studelsub(stuid):
    new = tk.Toplevel()
    new.geometry("250x30")
    new.resizable(width=FALSE, height=FALSE)
    new.title("수강 철회")

    subid = StringVar()
    subidLabel = Label(new, text="학수번호")
    subidLabel.grid(row=0,column=0)
    subidEntry = Entry(new, textvariable=subid)
    subidEntry.grid(row=0,column=1)

    com = partial(func.odelsub, stuid, subid, new)
    button = tk.Button(new, text = " 철회 ", command = com)
    button.grid(row=0,column=2)
    
def adminsch():
    func.allstu()
    new = tk.Toplevel()
    new.geometry("250x30")
    new.resizable(width=FALSE, height=FALSE)
    new.title("학생 조회")

    id = StringVar()
    idLabel = Label(new, text="학번")
    idLabel.grid(row=0,column=0)
    idEntry = Entry(new, textvariable=id)
    idEntry.grid(row=0,column=1)

    com = partial(func.schstu, id, new)
    button = tk.Button(new, text = " 조회 ", command = com)
    button.grid(row=0,column=2)

def adminstu():
    new = tk.Toplevel()
    new.geometry("250x80")
    new.resizable(width=FALSE, height=FALSE)
    new.title("학생 정정")

    mainMenu = Menu(new)
    new.config(menu = mainMenu)

    mainMenu.add_command(label="학생 정보 삭제 시 학번만 입력해도 됩니다")

    id = StringVar()
    name = StringVar()
    dept = StringVar()

    idLabel = Label(new, text="학번")
    nameLabel = Label(new, text="이름")
    deptLabel = Label(new, text="학과")
    idLabel.grid(row=0,column=0)
    nameLabel.grid(row=1,column=0)
    deptLabel.grid(row=2,column=0)
    
    idEntry = Entry(new, textvariable=id)
    nameEntry = Entry(new, textvariable=name)
    deptEntry = Entry(new, textvariable=dept)
    idEntry.grid(row=0,column=1)
    nameEntry.grid(row=1,column=1)
    deptEntry.grid(row=2,column=1)
    
    com1 = partial(func.addstu, id, name, dept, new)
    button = tk.Button(new, text = " 등록 ", command = com1)
    button.grid(row=0,column=2)

    com2 = partial(func.edtstu, id, name, dept, new)
    button = tk.Button(new, text = " 정정 ", command = com2)
    button.grid(row=1,column=2)
    
    com3 = partial(func.delstu, id, new)
    button = tk.Button(new, text = " 삭제 ", command = com3)
    button.grid(row=2,column=2)

def adminsub():
    new = tk.Toplevel()
    new.geometry("250x120")
    new.resizable(width=FALSE, height=FALSE)
    new.title("과목 정정")

    id = StringVar()
    name = StringVar()
    prof = StringVar()
    id_ = StringVar()

    idLabel = Label(new, text="학수번호")
    nameLabel = Label(new, text="과목명")
    profLabel = Label(new, text="교수명")
    idLabel.grid(row=0,column=0)
    nameLabel.grid(row=1,column=0)
    profLabel.grid(row=2,column=0)
    
    idEntry = Entry(new, textvariable=id)
    nameEntry = Entry(new, textvariable=name)
    profEntry = Entry(new, textvariable=prof)
    idEntry.grid(row=0,column=1)
    nameEntry.grid(row=1,column=1)
    profEntry.grid(row=2,column=1)

    addcom = partial(func.addsub, id, name, prof, new)
    button = tk.Button(new, text = " 등록 ", command = addcom)
    button.grid(row=2,column=2)

    sepLabel1 = Label(new, text="--------")
    sepLabel2 = Label(new, text="-----------------------------")
    sepLabel3 = Label(new, text="--------")
    sepLabel1.grid(row=3,column=0)
    sepLabel2.grid(row=3,column=1)
    sepLabel3.grid(row=3,column=2)

    idLabel_ = Label(new, text="학수번호")
    idLabel_.grid(row=4,column=0)
    idEntry = Entry(new, textvariable=id_)
    idEntry.grid(row=4,column=1)
    
    delcom = partial(func.delsub, id_, new)
    button = tk.Button(new, text = " 삭제 ", command = delcom)
    button.grid(row=4,column=2)

def admingrd():
    new = tk.Toplevel()
    new.geometry("250x70")
    new.resizable(width=FALSE, height=FALSE)
    new.title("성적 정정")

    stuid = StringVar()
    subid = StringVar()
    grd = StringVar()

    stuidLabel = Label(new, text="학번")
    subidLabel = Label(new, text="학수번호")
    grdLabel = Label(new, text="성적정정")
    stuidLabel.grid(row=0,column=0)
    subidLabel.grid(row=1,column=0)
    grdLabel.grid(row=2,column=0)
    
    stuidEntry = Entry(new, textvariable=stuid)
    subidEntry = Entry(new, textvariable=subid)
    grdEntry = Entry(new, textvariable=grd)
    stuidEntry.grid(row=0,column=1)
    subidEntry.grid(row=1,column=1)
    grdEntry.grid(row=2,column=1)
    
    com = partial(func.editgrd, stuid, subid, grd, new)
    button = tk.Button(new, text = " 입력 ", command = com)
    button.grid(row=2,column=2)

def studentlogin(id, window):
    func.quit(window)
    stulog = Tk()
    stulog.geometry("350x60")
    stulog.resizable(width=FALSE, height=FALSE)
    stulog.title("수강신청 학생 로그인")

    mainMenu = Menu(stulog)
    stulog.config(menu = mainMenu)

    mainMenu.add_command(label = "저장", command = func.save)
    mainMenu.add_command(label = "불러오기", command = func.load)

    stusub = partial(func.omysub, id)
    stugrd = partial(func.omygrd, id)
    stuadd = partial(stuaddsub, id)
    studel = partial(studelsub, id)
    
    subsch = Button(stulog, text="과목조회", command = stusub)
    addsub = Button(stulog, text="수강신청", command = stuadd)
    delsub = Button(stulog, text="수강철회", command = studel)
    mygrd  = Button(stulog, text="성적정보", command =  stugrd)

    subsch.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    addsub.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    delsub.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    mygrd.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)

    stulog.mainloop()

def adminlogin(window):
    func.quit(window)
    admin = Tk()
    admin.geometry("350x60")
    admin.resizable(width=FALSE, height=FALSE)
    admin.title("수강신청 관리자 로그인")

    mainMenu = Menu(admin)
    admin.config(menu = mainMenu)

    mainMenu.add_command(label = "저장", command = func.save)
    mainMenu.add_command(label = "불러오기", command = func.load)

    schmenu = Button(admin, text="학생조회", command = adminsch)
    stumenu = Button(admin, text="학생정정", command = adminstu)
    submenu = Button(admin, text="과목정정", command = adminsub)
    grdmenu = Button(admin, text="성적정정", command = admingrd)

    schmenu.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    stumenu.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    submenu.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)
    grdmenu.pack(side=LEFT, fill = X, ipadx = 5, ipady=5, padx=10)

    admin.mainloop()

def login(id, window):
    func.load()
    if id.get() == "admin":
        adminlogin(window)
    else:
        if(func.corid(id)==False):
            error = Label(window, text = "올바르지 않은 아이디입니다!", fg="red")
            error.place(x=20, y=70)
        else:
            studentlogin(id, window)

def mainsvc():
    window = Tk()
    window.geometry("300x100")
    window.resizable(width=FALSE, height=FALSE)
    window.title("수강신청 프로그램")

    idLabel = Label(window, text="ID")
    id = StringVar()
    idEntry = Entry(window, textvariable=id)
    mylogin = partial(login, id, window)
    loginButton = Button(window, text="Login", command=mylogin)

    idLabel.place(x=30, y=30)
    idEntry.place(x=60, y=30)
    loginButton.place(x=215, y=55)

    window.mainloop()
