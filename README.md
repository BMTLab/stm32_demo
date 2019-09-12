### Для Димы

C этого я начинал на работе в качестве обучения, не очень добротно
Программа для какого-то STM32. Делал и проишивал с помощью Keil

По нажатию кнопки меняется частота мигания светодиода.
*(Суть в том, что обработчик нажатия кнопки и мигание светодиода - это отдельные задачи, выполняющиеся паралельно благодаря операционной системе FreeRTOS)*
1. Вначале научился передавать данные между задачами
2. Потом сделал светодиод, как отдельный объект, по типу ООП в C#
3. Потом сделал кроссплатформенную реализацию, один и тот же проект можно либо залить в контроллер, либо запустить в Visual Studio
  - Если запускать в Visual Studio, то вместо светодида и кнопки - нажатие клавиши и текстовое сообщение с выводом частоты мигания.
  - Достигается за счет того, что в коде разделяю платформо-зависимый код с помощью директив: <pre>#ifdef _MSVC  #ifdef _UVISION </pre>
  - Нужно это для отладки программы, чтобы не мучать контроллер постоянными перепрошивками, и с помощью консоли можно выводить дополнительную информацию например
4. Потом создал юнит-тесты, чтобы проверить каждую функцию
5. Потом создал Makefile, это штука нужна, чтобы собирать проект без IDE, используя один лишь компилятор
