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
