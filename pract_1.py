import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.detach(), encoding = 'utf-8')
sys.stderr = io.TextIOWrapper(sys.stderr.detach(), encoding = 'utf-8')


class studentList():
    """
    학원 학생 관리 클래스
    학생 정보 형식 : 딕셔너리
    {'이름':'듣는 수업', '나이': 나이 }
    """
    list_number = 0
    def __init__(self, list_name):
        self.list_name = list_name
        self.student_number = 0
        self.student_list =[]
        self.Info_list = []
        print("{}학원이 학생 관리를 시작합니다.".format(self.list_name))
    def add_student(self, student_Info):
        self.student_list.append(student_Info)
        self.Info_list.append(list(student_Info.keys()))
        print("{} 학생이 등록하였습니다".format(self.Info_list[self.student_number][0]))
        self.student_number+=1
    def sub_stuedent(self, student_Info):
        self.student_list.index(student_Info.key[0])
        self.del_student = self.student_Info.pop(student_Info(key[0]))
        print("{} 학생이 미등록 처리 되었습니다".format(self.del_student))

academy_1 = studentList('xacademy')
academy_1.add_student({'chae':'computer', 'Year':22})
