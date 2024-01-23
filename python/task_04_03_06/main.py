# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 8
#
# Выполнил: Мужчинский В.Е.
# Группа: ПИН-б-о-21-1
# E-mail: xamelzis@gmail.com

import ДенежныйПеревод
from БанковскийПеревод import Банковскийперевод
from ВалютныйПеревод import Валютныйперевод
from ПочтовыйПеревод import Почтовыйперевод

if __name__ == "__main__":
    while True:
        typeOfContent = input(f"Выберите тип перевода: 1 - Банковский, 2 - Почтовый, 3 - Валютный:\n ")
        if typeOfContent == '1':
            print("1. Банковский перевод")
            name = str(input("Введите сумму: "))
            summa = Банковскийперевод(name)

            while True:
                runOrStop = input(f"1 - выполнить перевод: {name}; \n0 -  отменить перевод: {name};\nдругое - выбрать другой перевод:\n ")
                if runOrStop == '0':
                    summa.stop()
                elif runOrStop == '1':
                    summa.run()
                else:
                    break

        if typeOfContent == '2':
            print("2. Почтовый")
            name = str(input("Введите сумму: "))
            summa = Валютныйперевод(name)

            while True:
                runOrStop = input(f"1 - выполнить перевод: {name}; \n0 - отменить перевод: {name};\nдругое - выбрать другой перевод:\n ")
                if runOrStop == '0':
                    summa.stop()
                elif runOrStop == '1':
                    summa.run()
                else:
                    break
        if typeOfContent == '3':
            print("3. Банковский перевод")
            name = str(input("Введите сумму: "))
            summa = Почтовыйперевод(name)

            while True:
                runOrStop = input(f"1 - выполнить перевод: {name}; \n0 -  отменить перевод: {name};\nдругое - выбрать другой перевод:\n ")
                if runOrStop == '0':
                    summa.stop()
                elif runOrStop == '1':
                    summa.run()
                else:
                    break
