class Person():
    def __init__(self, name="", addr=""):
        self.name = name
        self.addr = addr

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def set_address(self, addr):
        self.addr = addr

    def get_address(self):
        return self.addr

    def __str__(self):
        message = '''\n{top_bar} 사람 정보 {top_bar}\n* 이름: {name}\n* 주소: {addr}\n{bottom_bar}\n'''.format(top_bar="*"*30,
                                                                                                       bottom_bar="*"*71,
                                                                                                       name=self.name,
                                                                                                       addr=self.addr)
        return message


if __name__ == '__main__':
    p1 = Person()
    p2 = Person("차윤성", "경기도 남양주시 퇴계원면 퇴계원로 85번길 3-1")

    print(p1)
    print(p2)
