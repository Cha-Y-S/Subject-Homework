from Friend import Friend
from Person import Person
from Message import *

# def print_add_menu():

# def print_modify_menu():

# def print_delete_menu():

# def print_store_menu():

# def print_exit_program():

if __name__ == '__main__':
    select_menu = 0
    print_information()

    while(True):
        print_main_menu()
        select_menu = input(" - 선택하려는 메뉴 번호를 입력해주세요: ")

        try:
            page_num = int(select_menu)
            if page_num == 1:
                # print("연락처 추가")
                print("TODO: 연락처 추가".center(100))
                print_add_message()
            elif page_num == 2:
                # print("연락처 수정")
                print("TODO: 연락처 수정".center(100))
                print_modify_message()
            elif page_num == 3:
                # print("연락처 삭제")
                print("TODO: 연락처 삭제".center(100))
                print_delete_message()
            elif page_num == 4:
                init_flag = False
                while(True):
                    print_init_message()
                    init_input = input()
                    print("")

                    if init_input == "예":
                        init_flag = True
                        break
                    elif init_input == "아니오":
                        init_flag = False
                        break
                    else:
                        print_tof_error_message()
                        continue
                if init_flag:
                    print("== TODO: 연락처 초기화")

            elif page_num == 5:
                # 연락처 조회
                print("TODO: 연락처 조회".center(100))

            elif page_num == 6:
                # 연락처 전체 조회
                print("TODO: 연락처 전체 조회".center(100))

            elif page_num == 7:
                exit_flag = False

                while(True):
                    print_before_exit_message()
                    exit_input = input()
                    print("")

                    if exit_input == "예":
                        exit_flag = True
                        break
                    elif exit_input == "아니오":
                        exit_flag = False
                        break
                    else:
                        exit_flag = False
                        print_tof_error_message()
                        continue

                if exit_flag:
                    print(" ----- 프로그램을 종료합니다. -----".center(100))
                    print("")
                    break

            else:
                print_error()
        except ValueError as e:
            print_error()
