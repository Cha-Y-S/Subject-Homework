import json
from Friend import Friend


class Phonebook():
    def __init__(self, info_list):
        self.info = dict()
        for info in info_list:
            key = info['name'] + ','+info['address']
            self.info[key] = Friend(name=info['name'], age=info['age'], p_num=info['phoneNumber'], student_id=info['studentId'],
                                    club=info['club'], univ=info['university'], major=info['major'], gender=info['gender'], addr=info['address'])

    def search_all_information(self):
        for key, _ in self.info.items():
            print(self.info[key])


if __name__ == '__main__':
    json_file = open('./data.json', 'r', encoding="utf-8")

    json_data = json.load(json_file)

    phonebook = Phonebook(json_data)

    phonebook.search_all_information()
