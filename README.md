Задача
============================================================
Задание 1
----------------
Имеется буфер произвольной длины, содержащий байты. Известно, что в этих байтах упакован набор значений, причем каждое значение занимает некоторое количество бит, в общем случае не кратное 8 и не выровнено по границе байта. К примеру, первое значение занимает 11 бит, включая первый байт в буфере и три бита второго байта, следующее значение имеет длину 6 бит, занимая 5 оставшихся бит второго байта и один третьего и т.п.
Нужно написать две функции для того, чтобы считывать и записывать отдельные значения в такой буфер. Прототипы функций:
short getdata(char *buf, int start, int len);
void putdata(char *buf, int start, int len, short value);
start и len задается в битах, start = 0 – младший бит самого первого байта в буфере.
Обратить внимание, что данные могут иметь знак. При этом старший бит в поле числа в буфере отвечает за знак, например если поле имеет длину 4 бита, то значение -5 там будет представлено как 1101, а 5 как 0101.

Задание 2
----------------
Существует массив байтов, в который упаковано множество различных данных. Эти данные объединены в логические блоки, к примеру, заголовок пакета с 0-го по 9-й байт, фиксированная часть сообщения с 10 по 15-й байт, переменная часть сообщения  с 16-го байта и т.п. Напишите простой класс на C++, который позволит работать с такими частями как с отдельным массивом, начинающимся с нуля. При этом он не должен копировать содержимое буфера в новую структуру памяти, а должен обращаться к исходному буферу. Класс должен позволять читать и записывать отдельные байты, создавать себя из существующего массива байт или из экземпляра такого же класса с добавлением смещения от его начала.
Добавьте в класс функции из п.1 так, чтобы они работали с битами этого буфера.

Решение
============================================================