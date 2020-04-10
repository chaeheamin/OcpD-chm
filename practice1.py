#딕셔너리 형태로 보관된 학생 초기 정보(이름, 학번) 수정하기
studInfo = {'CHM':0, "KCM": 1,"PCY" : 2, "BHR" :3, "JHJ":4}
name = list(studInfo.keys())
idNum =list(studInfo.values())

for i in range(len(studInfo)):
    print("{}학생의 새로운 학번을 입력하시오 : ".format(name[i]), end='')
    idNum[i] = int(input())
    studInfo[name[i]] = idNum[i]

print(studInfo.keys())
print(studInfo.values())
print(studInfo.items())

#학생 확인하기
nameF = input("찾고 싶은 학생의 이름을 입력하시오 : ")
if nameF in studInfo:
    print("{} 학생의 학번은 {} 입니다.".format(nameF,studInfo.get(nameF)))
