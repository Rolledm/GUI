# GUI
GroupWork :package:
### Стиль :rainbow: :
- названия переменных пишем целиком, т.е. position а не pos, width а не w
- везде CamelCase, по правилам Кожевникова, т.е.:
```
ClassName
Class.methodName
Class.fieldName
variableName
CONSTANT_VARIABLE_NAME
```
- если у вас есть сеттер для переменной variable, то он конечно принимает аргумет. Тогда пишем (это не я придумал, почаны, не бейте):
```
void variableSetter (type variable_)
{
    //какой-то еще код, есл нужен
    variable = variable_;
}
```
- комментарии пишем на русском, раз договорлись
- но в именах переменных, классов и т.д. транслит не юзаем
### Создание своих элементов :hammer_and_pick: :
- элементы состоящие из нескольих наследуем от IDisplayable
- одиночные элементы - от GUIBox
- для своих элементов создаем подпапку с названием "ТипЭлемента" в папке Elements, и там уже храним файлы .h и .cpp
- .h своих элементов добавляем в Headers.h (чтобы в include подняться на папку выше пишите "../", примеры применения раскиданы по проекту)
- для каждого типа элементов добавляем вектор этого типа в GUILayer и там же создаем его "конструкторы" (может изменится, но пока так)
- эти конструкторы должны создавать элемент, помещать его в вектор и возвращать shared_ptr<типЭлемента>
- остальные технически подробности важны, но их смотрите в комментах (я их потом добавлю сюда прост, пока так)

Пример кастомного элемента - Elements/Button/GUIButton. Функционально еще не закончен, но общий смысл для всех элементов (кроме составных) примерно такой
