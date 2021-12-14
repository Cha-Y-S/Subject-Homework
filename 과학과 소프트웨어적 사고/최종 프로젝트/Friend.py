from Person import Person


class Friend(Person):
    total_friend_cnt = 0

    def __init__(self, name="", addr="", age=0, p_num="", student_id="", club="", univ="", major="", gender=""):
        super().__init__(name, addr)
        self.age = age
        self.p_num = p_num
        self.student_id = student_id
        self.club = club
        self.univ = univ
        self.major = major
        self.gender = gender
        Friend.total_friend_cnt += 1

    def get_name(self):
        return super().get_name()

    def get_address(self):
        return super().get_address()

    def get_age(self):
        return self.age

    def get_phone_number(self):
        return self.p_num

    def get_student_id(self):
        return self.student_id

    def get_club(self):
        return self.club

    def get_university(self):
        return self.univ

    def get_gender(self):
        return self.gender

    def get_major(self):
        return self.major

    def set_name(self, name):
        super().set_name(name)

    def set_address(self, addr):
        super().set_address(addr)

    def set_age(self, age):
        self.age = age

    def set_phone_number(self, p_num):
        self.p_num = p_num

    def set_student_id(self, student_id):
        self.student_id = student_id

    def set_club(self, club):
        self.club = club

    def set_university(self, univ):
        self.univ = univ

    def set_gender(self, gender):
        self.gender = gender

    def set_major(self, major):
        self.major = major

    def __eq__(self, other):
        if other == None:
            return False
        return self.name == other.name and self.p_num == other.p_num

    def __str__(self):
        message = '''\n{top_bar} 연락처 정보 {top_bar}
* 이름: {name}\t\t\t* 나이: {age}\t\t* 성별: {gender}
*
* 학번: {student_id}\t\t* 전공: {major}
*
* 대학교: {univ}\t\t* 동아리: {club}
*
* 연락처: {p_num}\t\t* 주소: {addr}
{bottom_bar}\n'''.format(
            top_bar="*"*40,
            bottom_bar="*"*93,
            name=self.name,
            age=self.age,
            gender=self.gender,
            student_id=self.student_id,
            major=self.major,
            p_num=self.p_num,
            addr=self.addr,
            univ=self.univ,
            club=self.club)

        return message
