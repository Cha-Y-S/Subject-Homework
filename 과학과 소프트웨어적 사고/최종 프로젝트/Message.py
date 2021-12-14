def print_information():
    print("="*50, "HELP", "="*50)
    print("|", " ".rjust(15, " "), "- 연락처 관리 프로그램입니다.", "|".rjust(58))
    print("|", "|".rjust(104))
    print("|", " ".rjust(15, " "), "- 프로그램은 메뉴 번호 입력을 통해 진행됩니다.", "|".rjust(41))
    print("|", "|".rjust(104))
    print("|", " ".rjust(15, " "),
          "- 메뉴 번호 입력 및 목적에 따라 입력을 진행하며 지인들의 연락처를 관리할 수 있습니다.", "|".rjust(2))
    print("="*106, "\n")


def print_main_menu():
    top_bar = "*" * 20 + " 메인 메뉴 " + "*"*20
    print(top_bar.center(100))
    print("* 1. 연락처 추가".rjust(37), "\t5. 연락처 조회", "*".rjust(14))
    print("*".rjust(27), "*".rjust(49))
    print("* 2. 연락처 수정".rjust(37), "\t6. 연락처 전체 조회", "*".rjust(9))
    print("*".rjust(27), "*".rjust(49))
    print("* 3. 연락처 삭제".rjust(37), "\t7. 프로그램 종료", "*".rjust(12))
    print("*".rjust(27), "*".rjust(49))
    print("* 4. 연락처 초기화".rjust(38), "*".rjust(32))
    bottom_bar = "*"*51
    print(bottom_bar.center(104), "\n")


def print_modify_menu():
    top_bar = "*" * 20 + " 수정 메뉴 " + "*"*20
    print("")
    print(top_bar.center(100))
    print("* 1. 이름 수정".rjust(36), "\t6. 동아리 수정", "*".rjust(14))
    print("*".rjust(27), "*".rjust(49))
    print("* 2. 주소 수정".rjust(36), "\t7. 대학교 수정", "*".rjust(14))
    print("*".rjust(27), "*".rjust(49))
    print("* 3. 연락처 수정".rjust(37), "\t8. 전공 수정", "*".rjust(16))
    print("*".rjust(27), "*".rjust(49))
    print("* 4. 나이 수정".rjust(36), "\t9. 성별 종료", "*".rjust(16))
    print("*".rjust(27), "*".rjust(49))
    print("* 5. 학번 수정".rjust(36), "\t10. 수정 종료", "*".rjust(15))
    bottom_bar = "*"*51
    print(bottom_bar.center(104), "\n")


def print_search_menu():
    top_bar = "*" * 20 + " 조회 메뉴 " + "*"*20
    print("")
    print(top_bar.center(100))
    print("* 1. 이름 조회".rjust(36), "\t6. 대학교 조회", "*".rjust(14))
    print("*".rjust(27), "*".rjust(49))
    print("* 2. 주소 조회".rjust(36), "\t7. 전공 조회", "*".rjust(16))
    print("*".rjust(27), "*".rjust(49))
    print("* 3. 나이 조회".rjust(36), "\t8. 성별 조회", "*".rjust(16))
    print("*".rjust(27), "*".rjust(49))
    print("* 4. 학번 조회".rjust(36), "\t9. 조회 종료", "*".rjust(16))
    print("*".rjust(27), "*".rjust(49))
    print("* 5. 동아리 조회".rjust(37), "*".rjust(34))
    bottom_bar = "*"*51
    print(bottom_bar.center(104), "\n")


def print_add_message():
    message = "*"*30 + " 연락처 추가 단계입니다. " + "*"*30
    print("")
    print(message.center(100))
    print("")


def print_modify_message():
    message = "*"*30 + " 연락처 수정 단계입니다. " + "*"*30
    print("")
    print(message.center(100))
    print("")


def print_delete_message():
    message = "*"*30 + " 연락처 삭제 단계입니다. " + "*"*30
    print("")
    print(message.center(100))
    print("")


def print_init_message():
    print("")
    print("* 경고 *".center(100))
    print("  -- 연락처 초기화를 선택하셨습니다. 모든 연락처가 삭제됩니다.")
    print("")
    print("  -- 정말로 연락처를 초기화하시겠습니까? (예 / 아니오) : ", end="")


def print_before_exit_message():
    print("")
    print("  -- 프로그램의 종료를 선택하셨습니다.")
    print("")
    print("  -- 정말로 프로그램을 종료하시겠습니까? (예 / 아니오) : ", end="")


def print_cannot_find_info_message(param):
    print("")
    print("* \"{arg}\"에 해당되는 연락처 정보를 찾을 수 없습니다 *".format(arg=param).center(100))
    print("")


def print_invalid_input_error(scope):
    print("")
    print("*** 입력 오류 발생 ***".center(100))
    print("")
    print("잘못된 값을 입력하셨습니다.".center(96))
    print("")
    print("숫자 1 ~ {scope} 사이의 값을 입력해주세요.".center(100).format(scope=scope))
    print("")


def print_invalid_type_error():
    print("")
    print("*** 입력 오류 발생 ***".center(100))
    print("")
    print("잘못된 값을 입력하셨습니다.".center(96))
    print("")
    print("숫자만 입력해주세요".center(98))
    print("")


def print_invalid_gender_error():
    print("")
    print("*** 입력 오류 발생 ***".center(100))
    print("")
    print("잘못된 값을 입력하셨습니다.".center(96))
    print("")
    print("남성/여성 중 하나의 성별을 입력해주세요.".center(90))
    print("")


def print_tof_error_message():
    print("")
    print("** 입력 오류 **".center(100))
    print("")
    print("  -- 예 / 아니오 중 하나를 입력해주세요.")
    print("")


def print_file_error_message():
    print("")
    print("*** 파일 오류 발생 ***".center(100))
    print("")
    print(" 파일을 읽거나 쓰는 중 오류가 발생하였습니다".center(84))
    print("")
    print(" 프로그램을 종료하시거나 명령을 재 실행해주시기 바랍니다".center(76))


def print_store_message():
    print("")
    print("*** 수정 사항 저장 ***".center(100))
    print("")
    print(" -- 연락처의 수정 사항을 정말 저장하시겠습니까? (예/아니오): ", end="")
