import json
from Friend import Friend
from Message import print_modify_menu, print_invalid_input_error, print_cannot_find_info_message, print_search_menu, print_invalid_gender_error, print_invalid_type_error, print_store_message, print_file_error_message, print_tof_error_message


class Phonebook():
    def __init__(self, info_list):
        self.info = list()
        for info in info_list:
            self.info.append(Friend(name=info['name'], age=info['age'], p_num=info['phoneNumber'], student_id=info['studentId'],
                                    club=info['club'], univ=info['university'], major=info['major'], gender=info['gender'], addr=info['address']))

    def add_information(self):
        print("-- 연락처를 추가합니다. --".center(100))
        print("")
        print("** 필수 정보 : 이름, 전화번호 **".center(100))
        print("")
        print("필수 정보를 제외한 정보들은 입력을 원치 않으면 \"엔터\"를 눌러주세요".center(80))
        print("")

        name, age, p_num, student_id, club, univ, major, gender, addr = self.get_information_from_user()
        temp = Friend(name=name, age=age, p_num=p_num, student_id=student_id,
                      club=club, univ=univ, major=major, gender=gender, addr=addr)

        for info in self.info:
            if info == temp:
                print("* 동일한 전화번호를 가지는 사람이 이미 존재합니다.*".center(100))
                print("")
                print("* 다시 진행해주세요 *".center(114))
                print("")
                Friend.total_friend_cnt -= 1
                return False

        flag = True
        while flag:
            print_store_message()
            store = input()
            if store == "예":
                try:
                    self.info.append(temp)
                    json_file = open('./info.json', 'w', encoding='utf-8')
                    write_list = list()
                    for obj in self.info:
                        write_list.append({"name": obj.get_name(), "age": obj.get_age(), "phoneNumber": obj.get_phone_number(),
                                           "studentId": obj.get_student_id(), "club": obj.get_club(), "university": obj.get_university(),
                                           "major": obj.get_major(), "gender": obj.get_gender(), "address": obj.get_address()})

                    json.dump(write_list, json_file, indent="\t")
                    json_file.close()
                    flag = False
                except IOError:
                    print_file_error_message()
                    break
            elif store == "아니오":
                flag = False
                Friend.total_friend_cnt -= 1
            else:
                print_tof_error_message()

        print("")
        return True

    def get_information_from_user(self):
        while True:
            name = input("-- *이름을 입력해주세요: ")

            if (name == ""):
                print("\n이름은 필수 정보입니다. 다시 한번 입력해주세요.\n")
            else:
                print("")
                break

        while True:
            age = input("-- 나이를 입력해주세요: ")

            if age != "":
                try:
                    int(age)
                except ValueError:
                    print_invalid_type_error()
                else:
                    print("")
                    break
            else:
                print("")
                break

        while True:
            p_num = input("-- *전화번호를 입력해주세요: ")
            if p_num == "":
                print("\n전화번호는 필수 정보입니다. 다시 한번 입력해주세요.\n")
            else:
                try:
                    int(p_num)
                except ValueError:
                    print_invalid_type_error()
                else:
                    p_num = p_num[:3] + "-" + p_num[3:-4] + "-" + p_num[-4:]
                    print("")
                    break

        while True:
            student_id = input("-- 학번을 입력해주세요: ")
            if student_id != "":
                try:
                    int(age)
                except ValueError:
                    print_invalid_type_error()
                else:
                    print("")
                    break
            else:
                print("")
                break

        club = input("-- 동아리를 입력해주세요: ")
        print("")

        univ = input("-- 대학교를 입력해주세요: ")
        print("")

        major = input("-- 전공을 입력해주세요: ")
        print("")

        while True:
            gender = input("-- 성별을 입력해주세요(남성/여성): ")

            if(gender != "남성" and gender != "여성" and gender != ""):
                print_invalid_gender_error()
            else:
                print("")
                break

        addr = input("-- 주소를 입력해주세요(읍/면/동 까지): ")
        print("")

        return (name, age, p_num, student_id, club, univ, major, gender, addr)

    def modify_information(self):
        while(True):
            print_modify_menu()
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
                    print("전공")
                elif target == 9:
                    print("성별")
                elif target == 10:
                    print("종료")
                else:
                    print_invalid_input_error(scope=10)
            except ValueError:
                print_invalid_input_error(scope=10)

    def search_information(self):
        while(True):
            print_search_menu()
            select_menu = input(" - 선택하려는 메뉴 번호를 입력해주세요: ")
            try:
                target = int(select_menu)
                if target == 1:
                    self.search_by_name()
                elif target == 2:
                    self.search_by_address()
                elif target == 3:
                    self.search_by_age()
                elif target == 4:
                    self.search_by_id()
                elif target == 5:
                    self.search_by_club()
                elif target == 6:
                    self.search_by_university()
                elif target == 7:
                    self.search_by_major()
                elif target == 8:
                    self.search_by_gender()
                elif target == 9:
                    print("")
                    print("* 연락처 정보 조회를 종료합니다 *".center(100))
                    print("")
                    break
                else:
                    print_invalid_input_error(scope=9)
            except ValueError:
                print_invalid_input_error(scope=9)

    def search_by_name(self):
        name = input("\n -- 조회하려는 이름을 입력해주세요: ")
        flag = False
        for info in self.info:
            if name == info.get_name():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(name)

    def search_by_address(self):
        addr = input("\n -- 조회하려는 주소를 입력해주세요(읍/면/동 까지): ")
        flag = False
        for info in self.info:
            if addr == info.get_address():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(addr)

    def search_by_age(self):
        age = ""
        while(True):
            age = input("\n -- 조회하려는 나이를 입력해주세요: ")
            try:
                int(age)
            except ValueError:
                print_invalid_type_error()
            else:
                break

        flag = False
        for info in self.info:
            if age == info.get_age():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(age)

    def search_by_id(self):
        id = ""
        while(True):
            id = input("\n -- 조회하려는 학번을 입력해주세요: ")
            try:
                int(id)
            except ValueError:
                print_invalid_type_error()
            else:
                break

        flag = False
        for info in self.info:
            if id == info.get_student_id():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(id)

    def search_by_club(self):
        club = input("\n -- 조회하려는 동아리를 입력해주세요: ")
        flag = False
        for info in self.info:
            if club == info.get_club():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(club)

    def search_by_university(self):
        univ = input("\n -- 조회하려는 대학교를 입력해주세요: ")
        flag = False
        for info in self.info:
            if univ == info.get_university():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(univ)

    def search_by_major(self):
        major = input("\n -- 조회하려는 전공을 입력해주세요: ")
        flag = False
        for info in self.info:
            if major == info.get_major():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(major)

    def search_by_gender(self):
        gender = ""
        while(True):
            gender = input("\n -- 조회하려는 성별을 입력해주세요(남성/여성): ")
            if(gender == '남성' or gender == '여성'):
                break
            else:
                print_invalid_gender_error()
        flag = False
        for info in self.info:
            if gender == info.get_gender():
                print(info)
                input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")
                flag = True
        print("")

        if not flag:
            print_cannot_find_info_message(gender)

    def search_all_information(self):
        for info in self.info:
            print(info)
            input(" -- 확인이 완료되었다면 \"엔터\" 키를 눌러주세요.")

        print("")
        print(
            "-- 전체 연락처 정보 개수: {total}개 --".format(total=Friend.total_friend_cnt).center(100))
        print("")


if __name__ == '__main__':
    json_file = open('./data.json', 'r', encoding="utf-8")

    json_data = json.load(json_file)

    phonebook = Phonebook(json_data)

    phonebook.search_all_information()
