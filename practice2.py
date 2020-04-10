#practice_1의 함수화 + 작업 수행 방법 선택
#모든 학생 정보 수정
def allNew():
    for i in range(len(studInfo)):
        print("{}학생의 새로운 학번을 입력하시오 : ".format(name[i]), end='')
        idNum[i] = int(input())
        studInfo[name[i]] = idNum[i]
#일부 학생 정보 수정
def anyNew():
    numb = int(input("학생 정보를 수정할 학생 수를 입력하시오 : "))
    for i in range(numb):
        # print(i)
        nameM = input("학번 수정을 원하는 학생의 이름을 입력하시오 : ")
        if nameM in studInfo:
            newId = int(input("새로운 학번을 입력하시오 : "))
            #studInfo.update(nameM = newId)
            studInfo[nameM] = newId
        else:
            print("해당 학생이 존재하지 않아 무시됩니다.")
            # i=i-1
#학생 정보 찾기
def findStu():
    nameF = input("찾고 싶은 학생의 이름을 입력하시오 : ")
    if nameF in studInfo:
        print("{} 학생의 학번은 {} 입니다.".format(nameF,studInfo.get(nameF)))
#showStudInfo
def showStudInfo():
    print(studInfo.items())
    print()

#main
studInfo = {'CHM':0, "KCM": 1,"PCY" : 2, "BHL" :3, "JHJ":4}
name = list(studInfo.keys())
idNum =list(studInfo.values())
while 1:
    mod = input("작업 수행 모드를 선택하시오 (all,any,find,end) : ")
    if mod == "all":
        allNew()
        showStudInfo()
    elif mod == "any":
        anyNew()
        showStudInfo()
    elif mod == "find":
        findStu()
        showStudInfo()
    elif mod == "end":
        break
