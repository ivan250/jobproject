Мой первый проект представляет собой набор манипуляторов ,классов и вспомогательных функций ,для того чтобы помочь пользователью и 
ускорить процесс создания своего автоматизированного формата для вывода какой-то информации в файл.При создании я хотел чтобы 
мои манипуляторы были похожи на стандартные манипуляторы ,для того чтобы пользователю не нужно было изучать документацию прежде
чем  работать с ними.
Это ранняя версия проекта,в нет многих вещей которых я бы хотел реализовать,например пока нет обработки исключений и 
проверки ошибок.
По мере возможности проект будет активно развиваться.
Приставка - p означает что манипулятор берет информацию из потока.
Приставка - g означает что манипулятор передает какую-то информацию в поток.
Названия будут меняться :
prow -  пока что такой манипулятор один,он считывает количество строк из файла и передает ее
нужным манипуляторам в случае их использования.
gwstr  - принимает ширину и применяет ее к своему второму аргументу и передает в поток.
gsetwl/r - делает тоже самое что gwstr и смещает свой аргумент в указанную сторону.
gtime/gdate - передает в поток текущее время или дату.
gline - первый аргумент означает сколько раз продублировать второй аргумент,потом созданную строку в поток.
grus - преобразует строку на Русском языке для того чтобы она корректно отображалась в файле.
gnumstr - динамически определяет  сколько в вашем текстовом файле НЕ пустых строк и возвращает N+1 строку в поток,
что позволяет использовать его для нумерации строк.(То есть если вы закроете программу написав сколько то строк и 
продолжите работу он правильно определит текущий номер следующей строки.) 
Перед началом работы gnumstr нужно проинициализировать ,это делается примерно так - ifstream fin; fin>>prow;
Поэксперементируйте сами чтобы лучше понять о чем я говорю.
gdesc - первый аргумент инициализирует счетчик,второй аргумент помещается в поток только тогда-когда счетчик обнулится,
затем счетчик начинает работать заного.Например можно через 100 ставить \n  чтобы разделять строки .
Если вы запишите пару строк и выйдите из программы или сделайте так пару раз ,манипулятор будет все-равно 
верно ставить свой второй аргумент,поэксперементируйте сами чтобы лучше понять о чем я говорю.
Перед началом работы gnumstr нужно проинициализировать ,это делается примерно так - ifstream fin; fin>>prow;
______________________________________________________________________________________________________________________________

Целью второго проекта было показать применение ооп.

