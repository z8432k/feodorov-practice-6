# Лабораторная Работа №5. Межсетевое взаимодействие между процессами
## Цель работы
Организация межсетевого взаимодействия средствами WinAPI и POSIX.

## Задание
Организовать взаимодействие типа клиент-сервер средствами WinAPI и POSIX в соответствии с индивидуальным заданием.

1. Выбрать индивидуальное задание в соответствии с номером варианта. По номеру варианта также определить: 
- протокол, с использованием которого должен происходить обмен данными между сервером и клиентом;
- операционную систему, под которую необходимо разработать приложение сервера;
- операционную систему, под которую необходимо разработать приложение клиента.
2. В разделе [Issues](../../issues) репозитория создать не менее трех задач. Например: "Разработка приложения сервера", "Разработка приложения клиента", "Отладка клиент-серверного взаимодействия". Последовательно выполнить эти задачи, написав код и разместив его в репозитории. Решению каждой задачи должен соответствовать свой отдельный коммит, который должен быть [привязан](https://github.blog/2011-04-09-issues-2-0-the-next-generation/#commits-issues) к конкретной задаче. Итого в репозитории должно быть не менее трех коммитов. При необходимости создать дополнительные задачи.

3. Код приложения клиента необходимо разместить в файле `client/client.cpp`, код приложения сервера - в файле `server/server.cpp`. При необходимости использовать дополнительные заголовочные файлы. Код, предназначенный для выполнения в ОС Linux, должен собираться командной `g++ client/client.cpp` или `g++ server/server.cpp`. 

4. В репозитории имеется тест, проверяющий корректность оформления кода в соответствии с [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). Данный тест запускает [линтер](https://ru.wikipedia.org/wiki/Lint), который проверяет соответствие кода стандарту языка и правилам оформления (отступы, разделители, комментарии и т.п.). В некоторых случаях линтер может дать совет, как улучшить код используя общепринятые практики.

5. Проект поддерживает автоматическое тестирование кода в части успешности сборки на платформах POSIX, WIN32. Для настройки автоматической сбороки используется CMake. Об особенностях читайте ниже в соответствующем разделе.

6. Необходимо загрузить рабочий код в репозиторий, а затем защитить лабораторную работу у преподавателя, продемонстрировав корректную совместную работу клиентского и серверного приложений.

7. Допускается выполнение задания не в полном объеме. Правила начисления рейтинга для этого случая приведены в разделе [Рейтинг](#Рейтинг).

8. **ВАЖНО!** Для успешной автоматической сборки проекта при тестировании необходимо указать под какую платформу в соответствии с заданием у вас собирается клиент и под какую сервер! Для этого обратите внимание на комментарии в файле `CMakeLists.txt` **в корне проекта**. 

### CMake
Это инструмент для автоматической настройки (генерации файлов) специфичной для разных платформ. Для успешной работы с проектом вам достаточно руководствоваться пунктом (3) из задания, однако, есть ряд удобств, которые вы получаете если уделите внимание CMake:

1. Все исполнимые файлы после автоматической сборки (Worflows) находятся в каталоге `build/bin` и имеют названия которые вы указали в `CMakeLists.txt` в директивах **add_executable**
2. Каталоги `tests/posix` и `tests/win32` предназначены для платформо-специфичных тестов. Для win32 библиотека сокетов линкуется автоматически.
3. Локальный запуск сборки осуществляется командами: `cmake -S . -B build` - Подготовить сборочную информацию из исходного кода в текущем каталоге и разместить её в подкаталоге `build`, `cmake --build build` - выполнить сборку проекта в каталоге build 

---

**NB1!** Для получения максимально возможного количества баллов на защите лабораторной работы необходимо продемонстрировать работу системы на нескольких компьютерах, объединенных в локальную сеть. Для этого можно использовать локальную сеть между машинами в аудитории университета или виртуальную локальную сеть в системе виртуализации VM Ware или Virtual Box. Следует продемонстрировать корректную совместную работу по сети приложений клиента и сервера, запущенных в разных операционных системах (Windows и Linux/Mac OS).

**NB2!** Коммит не будет засчитан в качестве решения конкретной задачи из раздела [Issues](../../issues) репозитория, если он к ней не привязан. Для привязки коммита к задаче необходимо при создании коммита в commit message упомянуть номер задачи используя [специальный синтаксис](https://docs.github.com/en/github/writing-on-github/autolinked-references-and-urls#issues-and-pull-requests). Например, `Add server code for #2`, `Fix issue #9` и т.д.

---

## Содержание отчета
- Титульный лист 
- Цель работы
- Задание на лабораторную работу
- Схема взаимодействия между клиентом и сервером
- Результат выполнения лабораторной работы
- Исходный код программы с комментариями
- Выводы

## Варианты заданий
| № варианта    | Индивидуальное задание | Протокол  | Сервер  | Клиент  |
| ------------- |:----------------------:|:---------:|:-------:|:-------:|
| **1**         | 1                      | TCP       | Windows | Linux   |
| **2**         | 2                      | UDP       | Linux   | Windows |
| **3**         | 3                      | TCP       | Windows | Linux   |
| **4**         | 4                      | UDP       | Linux   | Windows |
| **5**         | 5                      | TCP       | Windows | Linux   |
| **6**         | 6                      | UDP       | Linux   | Windows |
| **7**         | 7                      | TCP       | Windows | Linux   |
| **8**         | 8                      | UDP       | Linux   | Windows |
| **9**         | 9                      | TCP       | Windows | Linux   |
| **10**        | 10                     | UDP       | Linux   | Windows |
| **11**        | 11                     | TCP       | Windows | Linux   |
| **12**        | 12                     | UDP       | Linux   | Windows |
| **13**        | 13                     | TCP       | Windows | Linux   |
| **14**        | 14                     | UDP       | Linux   | Windows |
| **15**        | 15                     | TCP       | Windows | Linux   |
| **16**        | 15                     | UDP       | Linux   | Windows |
| **17**        | 14                     | TCP       | Windows | Linux   |
| **18**        | 13                     | UDP       | Linux   | Windows |
| **19**        | 12                     | TCP       | Windows | Linux   |
| **20**        | 11                     | UDP       | Linux   | Windows |
| **21**        | 10                     | TCP       | Windows | Linux   |
| **22**        | 9                      | UDP       | Linux   | Windows |
| **23**        | 8                      | TCP       | Windows | Linux   |
| **24**        | 7                      | UDP       | Linux   | Windows |
| **25**        | 6                      | TCP       | Windows | Linux   |
| **26**        | 5                      | UDP       | Linux   | Windows |
| **27**        | 4                      | TCP       | Windows | Linux   |
| **28**        | 3                      | UDP       | Linux   | Windows |
| **29**        | 2                      | TCP       | Windows | Linux   |
| **30**        | 1                      | UDP       | Linux   | Windows |

## Индивидуальные задания
Общие требования для всех заданий:
- клиент и сервер являются консольными приложениями;
- номер порта, на котором работает сервер, указывается при его запуске в качестве аргумента командной строки;
- доменное имя (ip-адрес), на котором работает сервер, а также его номер порта указываются в качестве аргументов командной строки при запуске клиента;
- сервер выводит в консоль все сообщения, которые получает от клиента;
- клиент выводит в консоль все сообщения, которые получает от сервера.

1.  **Калькулятор**. Приложение-клиент запрашивает у пользователя ввод строки вида `<число> <математическая_операция> <число>` и передает ее на сервер. Сервер выполняет математическую операцию и возвращает результат клиенту. Примеры:  
    Пользователь вводит: `1 + 2`. Ответ сервера: `3`  
    Пользователь вводит: `2 * 3`. Ответ сервера: `6`  
    Пользователь вводит: `4 - 7`. Ответ сервера: `-3`  
    Пользователь вводит: `30 / 10`. Ответ сервера: `3`
2.  **Удаленный просмотр файлов**. Приложение-клиент запрашивает у пользователя ввод одной из трех комманд: `dir`, `get <filename>`, `quit` и отправляет ее на сервер. Сервер возвращает результат выполнения полученной команды клиенту. Команды:  
    `dir` - сервер запрашивает у операционной системы список файлов в текущей директории и отправляет результат клиенту; имена файлов должны быть разделены символом перевода строки;  
    `get <filename>` - сервер пересылает содержимое файла с указанным именем клиенту; если файл не найден или у сервера нет доступа к нему, сервер отправляет клиенту цифру 1; если файл найден, сервер отправляет цифру 0, затем размер файла в байтах, а затем содержимое файла;  
    `quit` - клиент запрашивает окончание работы; сервер отправляет клиенту цифру 0 и завершает свою работу; клиент получает ответ сервера и также завершает свою работу.
3.  **Подсчет слов**. Приложение-клиент запрашивает у пользователя ввод имени текстового файла и пересылает содержимое этого файла на сервер. Для этого сначала передается размер файла в байтах, а затем его содержимое. Сервер возвращает клиенту количество слов в полученном файле.
4.  **Проверка типа файла**. Приложение-клиент запрашивает у пользователя ввод имени файла и пересылает содержимое этого файла на сервер. Сервер анализирует [сигнатуру файла (магическое число)](https://ru.wikipedia.org/wiki/Список_сигнатур_файлов) и возвращает клиенту тип файла в виде одной из следующих строк: `exe`, `elf`, `png`, `pdf`, `zip`, `unknown`.
5.  **Поиск файлов по маске**. Приложение-клиент запрашивает у пользователя ввод двух строк: путь и расширение файла. Эти строки передаются на сервер, который запрашивает у операционной системы список всех файлов с указанным расширением по указанному пути. В ответ клиенту сервер посылает версию операционной системы, количество найденных файлов и их имена. Разделитель между именами файлов - символ перевода строки. Для определения версии операционной системы в ОС Windows можно использовать [`GetVersionEx()`](https://docs.microsoft.com/en-gb/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexa) или `Version Helper functions` (см. [пример](https://docs.microsoft.com/en-gb/windows/win32/sysinfo/getting-the-system-version)), в ОС Linux и MacOS - системный вызов [`uname()`](https://linux.die.net/man/2/uname);  
6.  **Треугольники**. Приложение-клиент запрашивает у пользователя ввод числа, которое пересылается на сервер. Сервер генерирует 3 случайных числа. Если эти числа образуют стороны треугольника, то они передаются клиенту, иначе сервер выводит их в консоль. Процедура повторяется до тех пор, пока сервер не сгенерирует столько троек чисел, образующих стороны треугольника, сколько изначально запросил клиент.
7.  **Повторения слов**. Приложение-клиент запрашивает у пользователя ввод двух строк: слово и имя текстового файла, расположенного на сервере. Эти строки передаются на сервер, который подсчитывает количество повторений указанного слова в выбранном текстовом файле. Полученное число возвращается клиенту.
8.  **Изменение регистра**. Приложение-клиент запрашивает у пользователя ввод строки, которая передается на сервер. Сервер изменяет регистр всех буквенных символов полученной строки на противоположный и возвращает результат клиенту. Примеры:  
    Пользователь вводит: `AbCd`. Ответ сервера: `aBcD`.  
    Пользователь вводит: `1q2/A`. Ответ сервера: `1Q2/a`.  
    Пользователь вводит: `Я-g`. Ответ сервера: `я-G`.
9.  **Характеристики сервера**. Приложение-клиент запрашивает у пользователя ввод одной из трех комманд: `date`, `ps`, `quit` и отправляет ее на сервер. Сервер возвращает результат выполнения полученной команды клиенту. Команды:  
    `date` - сервер возвращает клиенту текущую дату и время в виде строки в [формате ISO](https://ru.wikipedia.org/wiki/ISO_8601) `YYYY-MM-DDThh:mm:ss±hh`;  
    `ps` - сервер пересылает клиенту количество запущенных процессов и их имена, разделенные символом перевода строки; в ОС Windows можно воспользоваться функцией [`EnumProcess()`](https://docs.microsoft.com/en-us/windows/win32/api/psapi/nf-psapi-enumprocesses) (см. [пример](https://docs.microsoft.com/en-us/windows/win32/psapi/enumerating-all-processes)), в ОС Linux - прочитать содержимое файлов `/proc/<pid>/cmdline` для всех имеющихся идентификаторов процессов `<pid>`, а в ОС MacOS X и BSD использовать код из [QA1123](https://developer.apple.com/library/archive/qa/qa2001/qa1123.html) (см. также  [ответ с примером](https://stackoverflow.com/a/12433047) использования функции `GetBSDProcessList` и  [полный код](https://pastebin.com/etd3kxJD) примера);  
    `quit` - клиент запрашивает окончание работы; сервер отправляет клиенту цифру 0 и завершает свою работу; клиент получает ответ сервера и также завершает свою работу.
10. **Авторизация**. Приложение-клиент запрашивает у пользователя ввод двух строк: логин и пароль. Эти строки передаются на сервер, который проверяет правильность введенных данных. После третьей неудачной попытки подряд прислать верную пару `<логин, пароль>` сервер должен блокировать IP-адрес клиента на 1 минуту. Продемонстрировать, что во время блокировки одного клиента, к серверу может подключиться клиент с другим IP-адресом.
11. **Напоминание**. Приложение-клиент запрашивает у пользователя ввод строки и целого числа N и передает их на сервер. Сервер начинает отправлять клиенту полученную строку каждые N секунд до тех пор, пока клиент не отключится.
12. **Шифровка**. Приложение-клиент запрашивает у пользователя ввод строки и целого числа N и передает их на сервер. Сервер преобразует строку при помощи [шифра Цезаря](https://ru.wikipedia.org/wiki/Шифр_Цезаря) со сдвигом N и отправляет зашифрованную строку обратно клиенту. Клиент проверяет, что может восстановить полученную строку.
13. **Простые числа**. Приложение-клиент запрашивает у пользователя ввод числа и передает его на сервер. Сервер проверяет является ли полученное число простым и сообщает результат клиенту. Также сервер присылает клиенту строку, содержащую полученное ранее число, записанное прописью. Например:
    Пользователь вводит: `37`. Ответ сервера: `1 тридцать семь` (или `1 thirty seven`).
    Пользователь вводит: `10`. Ответ сервера: `0 десять` (или `0 ten`).
14. **Регистрация**. Приложение-клиент запрашивает у пользователя ввод одной из трех комманд: `reg <username>`, `list`, `quit` и отправляет ее на сервер. Сервер возвращает результат выполнения полученной команды клиенту. Команды:  
    `reg <username>` - сервер добавляет в список зарегистрированных пользователей нового пользователя с указанным именем, а также сохраняет IP-адрес и порт, идентифицирующие данного клиента; если пользователь с таким именем уже существует, сервер отправляет клиенту цифру 1; если это новый пользователь, сервер отправляет цифру 0 и сохраняет тройку значений `<username>`, IP-адрес клиента, порт клиента;  
    `list` - сервер отправляет клиенту количество всех зарегистрированных пользователей и их список с указанием имени пользователя, IP-адреса и порта подключения для каждого из них; информация о разных пользователях должна быть разделена символом перевода строки;  
    `quit` - клиент запрашивает окончание работы; сервер отправляет клиенту цифру 0 и переходит в режим ожидания подключения новых клиентов; клиент получает ответ сервера и завершает свою работу.
15. **Свободное место**. Приложение-клиент запрашивает у пользователя ввод пути и передает его на сервер. Сервер с помощью системного вызова определяет свободное место на том диске, на который указывает полученный путь. Клиенту передаются два числа: информация об объеме свободного и занятого места на диске сервера (в байтах). В Linux и MacOS использовать [`statvfs`]() (см. [пример](https://stackoverflow.com/a/12686166)), в Windows - [`GetDiskFreeSpaceA`](https://docs.microsoft.com/en-gb/windows/win32/api/fileapi/nf-fileapi-getdiskfreespacea).


## Рейтинг
За 100% принято максимальное количество баллов, которое студент может получить при выполнении данной лабораторной работы (указано в журнале). Например, если студент набрал 90% рейтинга, а максимальное количество баллов равно 10, то итоговое количество баллов за эту лабораторную составит `10*90% = 9` без учета штрафных баллов за пропуск срока сдачи лабораторной работы.

| Пункт задания                                                                                                     | Рейтинг |
| ----------------------------------------------------------------------------------------------------------------- |:-------:|
| 1. В разделе Issues репозитория создано не менее трех осмысленных задач и они оформлены в соответствии с заданием | 15%     |
| 2. В репозитории присутствует не менее трех осмысленных коммитов                                                  | 15%     |
| 3. Клиентское и серверное приложения компилируются и успешно запускаются без ошибок                               | 10%     |
| 4. Продемонстрирована корректная совместная работа клиента и сервера по сети с разных IP-адресов                  | 50%     |
| 5. Сервер является многопоточным и поддерживает одновременное подключение нескольких клиентов                     | 10%     |


# Лабораторная Работа №6. Непрерывная интеграция в облаке с использованием GitHub Actions
## Цель работы
Изучение принципов организации непрерывной интеграции приложений с использованием облачных технологий.

## Задание
1. Добавить в репозиторий предыдущей лабораторной работы файл конфигурации `.github/workflows/tests.yml`, управляющий созданием виртуальной машины в облаке, на которой автоматически будет запускаться сборка и тестирование проекта. Примеры оформления файла конфигурации можно найти в репозиториях лабораторных работ №№1-5, в [официальной документации](https://docs.github.com/en/actions), а также с помощью поиска в Интернете. Задачу (`job`) в файле конфигурации необходимо назвать `test`, использование других имен приведет к потере баллов. Команды в разделе `steps` задачи должны запускать сборку той части предыдущей лабораторной работы, которая в соответствии с вариантом была выполнена в ОС Linux (или Mac OS). Например, если по варианту задания на предыдущую лабораторную работу необходимо было разработать серверную часть приложения под ОС Linux, а клиентскую часть приложения под ОС Windows, то в данной лабораторной работе необходимо осуществить автоматическую сборку серверной части приложения. Сборка должна осуществляться упешно (без ошибок).
2. (**NB**! Этот пункт задания необязателен к выполнению) *Разработать как минимум один тест для проверки правильности функционирования приложения, автоматическая сборка которого была обеспечена на предыдущем шаге. Добавить сборку и запуск теста (-ов) в файл конфигурации `tests.yml`.*
3. По аналогии с предыдущей работой процесс выполнения задания должен быть разбит на задачи, которые должны быть описаны в разделе Issues репозитория. Решению каждой задачи должен соответствовать как минимум один коммит. Название задач должно начинаться с префикса `Lab6:`, такой же префикс должен быть в названии коммита (-ов). Коммиты и задачи без префикса засчитаны не будут.


## Содержание отчета
- Титульный лист 
- Цель работы
- Задание на лабораторную работу
- Описание структуры конфигурационного файла
- Содержимое написанного конфигурационного файла
- Логи сборки проекта в облаке
- Исходный код тестов (при наличии)
- Выводы


## Рейтинг
За 100% принято максимальное количество баллов, которое студент может получить при выполнении данной лабораторной работы (указано в журнале). Например, если студент набрал 20% рейтинга, а максимальное количество баллов равно 8, то итоговое количество баллов за эту лабораторную составит `8*20% = 1,6` без учета штрафных баллов.

| Пункт задания                                                                                                  | Рейтинг |
| -------------------------------------------------------------------------------------------------------------- |:-------:|
| 1. В разделе Issues репозитория создано не менее одной осмысленной задачи в соответствии с заданием               | 10%     |
| 2. В репозитории присутствует не менее одного осмысленного коммита (помимо тех, что были сделаны ранее)           | 10%     |
| 3. При создании нового коммита запускается процесс сборки приложения под ОС Linux. Сборка проходит без ошибок     | 20%     |
| 4. В репозитории присутствуют тесты, проверяющие аварийное завершение работы программы при следующих ситуациях: неправильное количество аргументов командной строки, неправильные значения аргументов командной строки (обработать минимум два разных случая с неправильными значениями). См. [пример подхода](#footnote1) ниже     | 30%     |
| 5. В зависимости от варианта реализовать приложение-заглушку для клиента или сервера под ОС Linux для тестирования факта установления соединения между клиентом и сервером по интерфейсу обратной петли (loopback). Задача: протестировать под ОС Linux правильность работы клиента (сервера), разработанного в рамках предыдущей лабораторной работы, и заглушки сервера (или клиента), написанной для данного теста. Заглушка не обязана реализовывать весь функционал сервера/клиента. | 30%     |

---

<a name="footnote1">Пример</a> подхода к тестированию аргументов командной строки. 

Пусть необходимо протестировать работу сервера. Если сервер принимает на вход одно число (номер порта), то это число должно быть целым и лежать в определенном диапазоне. В этом случае потенциальными тестами могут быть: 
- проверка, что программа завершится аварийно, если количество аргументов командной строки равно нулю или более одного;
- проверка, что программа завершится аварийно, если аргумент командной строки не является целым числом;
- проверка, что программа завершится аварийно, если аргумент командной строки является числом, не соответствующим допустимым значениям для номера порта.

В случае тестирования аргументов командной строки клиента действовать по аналогии.
