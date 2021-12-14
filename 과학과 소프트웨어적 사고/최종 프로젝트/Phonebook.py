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
        info = self.__search_for_md()

        if info == None:
            return

        while(True):
            print_modify_menu()
            select_menu = input(" - 선택하려는 메뉴 번호를 입력해주세요: ")
            try:
                target = int(select_menu)
                func_list = [self.modify_info_name, self.modify_info_address, self.modify_info_phone_number,
                             self.modify_info_age, self.modify_info_student_id, self.modify_info_club,
                             self.modify_info_university, self.modify_info_major, self.modify_info_gender]
                if 1 <= target <= 9:
                    func_list[target-1](info)
                elif target == 10:
                    print(info)

                    while True:
                        print("")
                        store = input(" -- 해당 수정 사항을 정말 저장하시겠습니까? (예/아니오): ")
                        print("")
                        if store == "예":
                            try:
                                json_file = open(
                                    './info.json', 'w', encoding='utf-8')
                                write_list = list()
                                for obj in self.info:
                                    write_list.append({"name": obj.get_name(), "age": obj.get_age(), "phoneNumber": obj.get_phone_number(),
                                                       "studentId": obj.get_student_id(), "club": obj.get_club(), "university": obj.get_university(),
                                                       "major": obj.get_major(), "gender": obj.get_gender(), "address": obj.get_address()})

                                json.dump(write_list, json_file, indent="\t")
                                json_file.close()
                            except IOError:
                                print_file_error_message()
                            finally:
                                print("* 수정 사항이 저장되었습니다 *".center(100))
                                print("")
                                print("* 연락처 수정을 종료합니다. *".center(100))
                                print("")
                                return
                        elif store == "아니오":
                            print("")
                            return
                        else:
                            print_tof_error_message()
                else:
                    print_invalid_input_error(scope=10)
            except ValueError:
                print_invalid_input_error(scope=10)

    def modify_info_name(self, target):
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        name = input("\n -- 이름의 수정값을 입력해주세요: ")
        if name == "":
            return
        prev = target.get_name()
        target.set_name(name)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=name))

    def modify_info_address(self, target):
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        addr = input("\n -- 주소의 수정값을 입력해주세요(읍/면/동 까지): ")
        if addr == "":
            return
        prev = target.get_address() if target.get_address() != "" else "공백"
        target.set_address(addr)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=addr))

    def modify_info_phone_number(self, target):
        p_num = ""
        while(True):
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            p_num = input("\n -- 연락처의 수정값을 입력해주세요: ")
            if p_num == "":
                return
            try:
                int(p_num)
            except ValueError:
                print_invalid_type_error()
            else:
                p_num = p_num[:3]+"-"+p_num[3:-4]+"-"+p_num[-4:]
                break
        prev = target.get_phone_number()
        target.set_phone_number(p_num)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=p_num))

    def modify_info_age(self, target):
        age = ""
        while(True):
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            age = input("\n -- 나이의 수정값을 입력해주세요: ")
            if age == "":
                return
            try:
                int(age)
            except ValueError:
                print_invalid_type_error()
            else:
                break
        prev = target.get_age() if target.get_age() != "" else "공백"
        target.set_age(age)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=age))

    def modify_info_student_id(self, target):
        id = ""
        while(True):
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            id = input("\n -- 학번의 수정값을 입력해주세요: ")
            if id == "":
                return
            try:
                int(id)
            except ValueError:
                print_invalid_type_error()
            else:
                break
        prev = target.get_student_id() if target.get_student_id() != "" else "공백"
        target.set_student_id(id)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=id))

    def modify_info_club(self, target):
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        club = input("\n -- 동아리의 수정값를 입력해주세요: ")
        if club == "":
            return
        prev = target.get_club() if target.get_club() != "" else "공백"
        target.set_club(club)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=club))

    def modify_info_university(self, target):
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        univ = input("\n -- 대학교의 수정값 입력해주세요: ")
        if univ == "":
            return
        prev = target.get_university() if target.get_university() != "" else "공백"
        target.set_university(univ)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=univ))

    def modify_info_major(self, target):
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        major = input("\n -- 전공의 수정값을 입력해주세요: ")
        if major == "":
            return
        prev = target.get_major() if target.get_major() != "" else "공백"
        target.set_major(major)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=major))

    def modify_info_gender(self, target):
        gender = ""
        while(True):
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            gender = input("\n -- 조회하려는 성별을 입력해주세요(남성/여성): ")
            if gender == "":
                return
            if(gender == '남성' or gender == '여성'):
                break
            else:
                print_invalid_gender_error()
        prev = target.get_gender() if target.get_gender() != "" else "공백"
        target.set_gender(gender)

        print(
            "\n  -- {prev}에서 {next}으로 수정이 완료되었습니다.\n".format(prev=prev, next=gender))

    def delete_information(self):
        param = self.__search_for_md()

        if param == None:
            return

        print(param)
        while True:
            print("")
            remove = input(" -- 해당 연락처를 정말 삭제하시겠습니까? (예/아니오): ")
            if remove == "예":
                self.info.remove(param)
                Friend.total_friend_cnt -= 1
                print("\n -- 해당 연락처가 삭제되었습니다.")
                print("")
                try:
                    json_file = open('./info.json', 'w', encoding='utf-8')
                    write_list = list()
                    for obj in self.info:
                        write_list.append({"name": obj.get_name(), "age": obj.get_age(), "phoneNumber": obj.get_phone_number(),
                                           "studentId": obj.get_student_id(), "club": obj.get_club(), "university": obj.get_university(),
                                           "major": obj.get_major(), "gender": obj.get_gender(), "address": obj.get_address()})

                    json.dump(write_list, json_file, indent="\t")
                    json_file.close()
                except IOError:
                    print_file_error_message()
                finally:
                    break
            elif remove == "아니오":
                print("")
                return
            else:
                print_tof_error_message()

    def delete_all_information(self):
        try:
            json_file = open('./info.json', 'w', encoding='utf-8')
            self.info = list()
            json.dump(self.info, json_file, indent="\t")
            json_file.close()
            Friend.total_friend_cnt = 0
            print("  -- 연락처가 초기화되었습니다.\n")
        except IOError:
            print_file_error_message()

    def __search_for_md(self):
        print("\n  -- 수정/삭제를 취소하려면 \"엔터\"를 눌러주세요.\n")
        name = input(" -- 수정/삭제하려는 이름을 검색해주세요: ")
        print("")

        if name == "":
            return None

        candidate = []
        for info in self.info:
            if info.name == name:
                candidate.append(info)

        if len(candidate) == 0:
            print("")
            print("* 수정/삭제 대상을 찾을 수 없습니다. *".center(100))
            print("")
            input(" -- 프로그램을 진행시키기 위해 \"엔터\"를 눌러주세요.")
            print("")
            return None

        if len(candidate) == 1:
            return candidate[0]

        flag = True
        temp = None
        while flag:
            print(" -- 목록을 확인하고, 수정/삭제하려는 정보의 번호를 입력해주세요")
            print("")
            print(" -- 수정/삭제를 취소하려면 \"엔터\"를 눌러주세요.")
            for info in candidate:
                print(info)

            p_num = input(" -- 수정/삭제 대상 번호: ")

            if p_num == "":
                break

            try:
                int(p_num)
            except ValueError:
                print_invalid_type_error()
            else:
                p_num = p_num[:3]+"-"+p_num[3:-4]+"-"+p_num[-4:]
                temp = Friend(name=name, p_num=p_num)
                Friend.total_friend_cnt -= 1
                for info in candidate:
                    if info == temp:
                        temp = info
                        flag = False
                        return info

                print("")
                print("{name}, {p_num}에 해당하는 정보를 찾을 수 없습니다.".format(
                    name=name, p_num=p_num))
                print("")
                input("다시 진행하기 위해 \"엔터\"를 눌러주세요.")
                print("")

    def search_information(self):
        while(True):
            print_search_menu()
            select_menu = input(" - 선택하려는 메뉴 번호를 입력해주세요: ")
            try:
                target = int(select_menu)
                func_list = [self.search_by_name, self.search_by_address, self.search_by_age,
                             self.search_by_id, self.search_by_club, self.search_by_university,
                             self.search_by_major, self.search_by_gender]
                if 1 <= target <= 8:
                    func_list[target-1]()
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
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        name = input("\n -- 조회하려는 이름을 입력해주세요: ")
        if name == "":
            return
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
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        addr = input("\n -- 조회하려는 주소를 입력해주세요(읍/면/동 까지): ")
        if addr == "":
            return
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
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            age = input("\n -- 조회하려는 나이를 입력해주세요: ")
            if age == "":
                return
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
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            id = input("\n -- 조회하려는 학번을 입력해주세요: ")
            if id == "":
                return
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
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        club = input("\n -- 조회하려는 동아리를 입력해주세요: ")
        if club == "":
            return
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
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        univ = input("\n -- 조회하려는 대학교를 입력해주세요: ")
        if univ == "":
            return
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
        print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
        major = input("\n -- 조회하려는 전공을 입력해주세요: ")
        if major == "":
            return
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
            print("\n  -- 취소하려면 \"엔터\"를 눌러주세요.")
            gender = input("\n -- 조회하려는 성별을 입력해주세요(남성/여성): ")
            if gender == "":
                return
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
