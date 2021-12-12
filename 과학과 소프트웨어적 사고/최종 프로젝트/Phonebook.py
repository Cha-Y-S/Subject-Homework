import json
from Friend import Friend
from Message import print_modify_menu, print_invalid_input_error


class Phonebook():
    def __init__(self, info_list):
        self.info = list()
        for info in info_list:
            self.info.append(Friend(name=info['name'], age=info['age'], p_num=info['phoneNumber'], student_id=info['studentId'],
                                    club=info['club'], univ=info['university'], major=info['major'], gender=info['gender'], addr=info['address']))
        print(" ")
        print("연락처 개수: ", Friend.total_friend_cnt)
        print(" ")

    def modify_information(self):
        print_modify_menu()
        while(True):
            select_menu = input(" - 선택하려는 메뉴 번호를 입력해주세요: ")
            try:
                target = int(select_menu)
                if target == 1:
                    print("이름")
                elif target == 2:
                    print("주소")
                elif target == 3:
                    print("연락처")
                elif target == 4:
                    print("나이")
                elif target == 5:
                    print("학번")
                elif target == 6:
                    print("동아리")
                elif target == 7:
                    print("대학교")
                elif target == 8:
                    print("성별")
                elif target == 9:
                    print("종료")
                else:
                    print_invalid_input_error(scope=9)
            except ValueError:
                print_invalid_input_error(scope=9)

    def search_by_name(self, name):
        for info in self.info:
            if name == info.get_name():
                print(info)

    def search_all_information(self):
        for info in self.info:
            print(info)
            input(" -- 다음 목록을 보기 위해 키보드 아무 키를 눌러주세요.")
        print("")


if __name__ == '__main__':
    json_file = open('./data.json', 'r', encoding="utf-8")

    json_data = json.load(json_file)

    phonebook = Phonebook(json_data)

    phonebook.search_all_information()
