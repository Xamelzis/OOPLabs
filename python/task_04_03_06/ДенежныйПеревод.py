# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 1
#
# Выполнил: Автандилян В.С.
# Группа: ПИН-б-о-21-1
# E-mail: v.avtandilyan@mail.ru

class Денежныйперевод:

    def __init__(self, name):
        if not isinstance(name, str):
            raise TypeError("Название должно быть строкой")

        self._name = name

    def run(self):
        print(f"Перевод {self._name} выполнен\n")
        
    def stop(self):
        print(f"Перевод {self._name} отменён\n")