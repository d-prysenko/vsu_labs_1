#include <iostream>

#include "List.h"

// печатает сообщение message, ожидает ввода числа и считывает его
// так нужно будет делать часто, поэтому есть смысл вынести эти действия в эту функцию
int print_and_scan(std::string message)
{
	int temp;
	std::cout << message;
	std::cin >> temp;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "");

	List my_list;

	std::cout << "Выберите действие:\n";
	std::cout << "1. Добавление элемента в начало списка.\n";
	std::cout << "2. Добавление элемента в конец списка.\n";
	std::cout << "3. Добавление элемента после заданного звена (по значению).\n";
	std::cout << "4. Удаление элемента из начала списка.\n";
	std::cout << "5. Удаление элемента из конца списка.\n";
	std::cout << "6. Удаление элемента после звена (по значению).\n";
	std::cout << "7. Очистка списка.\n";
	std::cout << "8. Печать списка.\n";
	std::cout << "9. Текст задания.\n";
	std::cout << "10. Выход.\n";

	int action;

	do
	{
		std::cout << ">> ";
		std::cin >> action;

		switch (action)
		{
		// Добавление элемента в начало списка
		case 1:
		{
			int val = print_and_scan("Введите значение: ");

			my_list.push_front(val);
			break;
		}
		// Добавление элемента в конец списка
		case 2:
		{
			int val = print_and_scan("Введите значение: ");

			my_list.push_back(val);
			break;
		}
		// Добавление элемента после заданного звена (по значению)
		case 3:
		{
			int val = print_and_scan("Введите значение, которое хотите добавить: ");
			int prev_elem = print_and_scan("Введите значение элемента, после которого будет вставлено значение: ");

			List::Node* p_prev = my_list.find(prev_elem);
			my_list.push_after(p_prev, val);
			break;
		}
		// Удаление элемента из начала списка
		case 4:
		{
			my_list.pop_front();
			break;
		}
		// Удаление элемента из конца списка
		case 5:
		{
			my_list.pop_back();
			break;
		}
		// Удаление элемента после звена (по значению)
		case 6:
		{
			int prev_elem = print_and_scan("Введите значение элемента, предшествующего удаляемому звену: ");

			List::Node* p_prev = my_list.find(prev_elem);
			my_list.pop_after(p_prev);
			break;
		}
		// Очистка списка
		case 7:
		{
			my_list.clear();
			break;
		}
		// Печать списка
		case 8:
		{
			my_list.print_this_shit();
			break;
		}
		// Текст задания
		case 9:
		{
			int list_type;
			List list;
			std::cout << "27. Создать линейный односвязный список. Из списка удалить последний отрицательный элемент, а затем вставать заданное число перед минимальным элементом списка и после минимального положительного элемента. Освободить память, занимаемую элементами списка.\n";
			std::cout << "Использовать текущий список(1) или тестовый(2)?\n";
			std::cout << "[1, 2] >> ";
			std::cin >> list_type;

			if (list_type == 1)
			{
				list = my_list;
			}
			else if (list_type == 2)
			{
				list.push_back(-1);
				list.push_back(2);
				list.push_back(-5);
				list.push_back(43);
			}
			else
			{
				std::cout << "Неверный ввод!\n";
				break;
			}

			// удалить последний отрицательный элемент
			List::Node* p_negative = nullptr;
			for (List::Node* itr = list.begin(); itr != nullptr; itr = itr->p_next)
				if (itr->val < 0)
					p_negative = itr;

			if (p_negative)
			{
				list.pop(p_negative);
			}
			
			// вставить заданное число перед минимальным элементом списка и после минимального положительного элемента
			int num;
			std::cout << "Число задайте по братски э: ";
			std::cin >> num;

			List::Node* p_min = nullptr;
			List::Node* p_pos_min = nullptr;
			List::Node* p_prev_min = nullptr;
			for (List::Node* itr = list.begin(); itr != nullptr; itr = itr->p_next)
			{
				List::Node* next = itr->p_next;

				if (!p_min)
					p_min = itr;

				else if (!p_pos_min && itr->val >= 0)
					p_pos_min = itr;

				else if (next && next->val < p_min->val)
				{
					p_min = next;
					p_prev_min = itr;
				}
				else if (p_pos_min && itr->val < p_pos_min->val && itr->val > 0)
				{
					p_pos_min = itr;
				}
			}

			if (p_min == list.begin())
			{
				list.push_front(num);
			}
			else
			{
				list.push_after(p_prev_min, num);
			}

			list.push_after(p_pos_min, num);

			list.print_this_shit();

			break;
		}
		// Выход
		case 10:
		{
			break;
		}
		default:
		{
			std::cout << "Выберите действие из предложенного выше списка!\n";
			std::cout << "Значение должно быть от 1 до 10 включительно, введено: " << action << std::endl;
			break;
		}
		}

	} while (action != 10);

	return 0;
}