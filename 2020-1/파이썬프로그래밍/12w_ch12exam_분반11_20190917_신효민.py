#성신여자대학교 파이썬 프로그래밍 12주차 과제
#20190917 통계학과 신효민

from tkinter import *
from tkinter.filedialog import *

def func_open():
    filename = askopenfilename(parent = window,
                               filetypes = (("GIF 파일", "*.gif"), ("모든 파일","*.*")))
    photo = PhotoImage(file = filename)
    pLabel.configure(image = photo)
    pLabel.image = photo

def func_open():
    return

def func_save():
    return

def func_saveAs():
    return

def func_settings():
    return

def func_exit():
    window.quit()
    window.destroy()

def func_delete():
    return

def func_copy():
    return

def func_paste():
    return

def func_cut():
    return

def func_turn():
    return

def func_go():
    return

def func_for():
    return

def func_share():
    return

def func_print():
    return

def func_type():
    return

window = Tk()
window.geometry("400x400")
window.title("20190917 신효민 12주차 과제")

photo = PhotoImage()
pLabel = Label(window, image = photo)
pLabel.pack(expand = 1, anchor = CENTER)

mainMenu = Menu(window)
window.config(menu = mainMenu)

fileMenu = Menu(mainMenu)
mainMenu.add_cascade(label = "파일", menu = fileMenu)
fileMenu.add_command(label = "열기", command = func_open)
fileMenu.add_command(label = "저장", command = func_save)
fileMenu.add_command(label = "다른 이름으로 저장", command = func_saveAs)
fileMenu.add_command(label = "환경 설정", command = func_settings)
fileMenu.add_separator()
fileMenu.add_command(label = "종료", command = func_exit)

modifyMenu = Menu(mainMenu)
mainMenu.add_cascade(label = "편집", menu = modifyMenu)
modifyMenu.add_command(label = "삭제", command = func_delete)
modifyMenu.add_command(label = "복사", command = func_copy)
modifyMenu.add_command(label = "붙여넣기", command = func_paste)
modifyMenu.add_command(label = "자르기", command = func_cut)
modifyMenu.add_command(label = "회전", command = func_turn)

optionMenu = Menu(mainMenu)
mainMenu.add_cascade(label = "옵션", menu = optionMenu)
optionMenu.add_command(label = "바로가기 만들기", command = func_go)
optionMenu.add_command(label = "보내기", command = func_for)
optionMenu.add_command(label = "공유", command = func_share)
optionMenu.add_command(label = "인쇄하기", command = func_print)
optionMenu.add_command(label = "속성", command = func_type)

window.mainloop()
