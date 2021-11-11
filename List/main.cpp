#include <iostream>

#include "List.h"

// �������� ��������� message, ������� ����� ����� � ��������� ���
// ��� ����� ����� ������ �����, ������� ���� ����� ������� ��� �������� � ��� �������
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

	std::cout << "�������� ��������:\n";
	std::cout << "1. ���������� �������� � ������ ������.\n";
	std::cout << "2. ���������� �������� � ����� ������.\n";
	std::cout << "3. ���������� �������� ����� ��������� ����� (�� ��������).\n";
	std::cout << "4. �������� �������� �� ������ ������.\n";
	std::cout << "5. �������� �������� �� ����� ������.\n";
	std::cout << "6. �������� �������� ����� ����� (�� ��������).\n";
	std::cout << "7. ������� ������.\n";
	std::cout << "8. ������ ������.\n";
	std::cout << "9. ����� �������.\n";
	std::cout << "10. �����.\n";

	int action;

	do
	{
		std::cout << ">> ";
		std::cin >> action;

		switch (action)
		{
		// ���������� �������� � ������ ������
		case 1:
		{
			int val = print_and_scan("������� ��������: ");

			my_list.push_front(val);
			break;
		}
		// ���������� �������� � ����� ������
		case 2:
		{
			int val = print_and_scan("������� ��������: ");

			my_list.push_back(val);
			break;
		}
		// ���������� �������� ����� ��������� ����� (�� ��������)
		case 3:
		{
			int val = print_and_scan("������� ��������, ������� ������ ��������: ");
			int prev_elem = print_and_scan("������� �������� ��������, ����� �������� ����� ��������� ��������: ");

			List::Node* p_prev = my_list.find(prev_elem);
			my_list.push_after(p_prev, val);
			break;
		}
		// �������� �������� �� ������ ������
		case 4:
		{
			my_list.pop_front();
			break;
		}
		// �������� �������� �� ����� ������
		case 5:
		{
			my_list.pop_back();
			break;
		}
		// �������� �������� ����� ����� (�� ��������)
		case 6:
		{
			int prev_elem = print_and_scan("������� �������� ��������, ��������������� ���������� �����: ");

			List::Node* p_prev = my_list.find(prev_elem);
			my_list.pop_after(p_prev);
			break;
		}
		// ������� ������
		case 7:
		{
			my_list.clear();
			break;
		}
		// ������ ������
		case 8:
		{
			my_list.print_this_shit();
			break;
		}
		// ����� �������
		case 9:
		{
			int list_type;
			List list;
			std::cout << "27. ������� �������� ����������� ������. �� ������ ������� ��������� ������������� �������, � ����� �������� �������� ����� ����� ����������� ��������� ������ � ����� ������������ �������������� ��������. ���������� ������, ���������� ���������� ������.\n";
			std::cout << "������������ ������� ������(1) ��� ��������(2)?\n";
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
				std::cout << "�������� ����!\n";
				break;
			}

			// ������� ��������� ������������� �������
			List::Node* p_negative = nullptr;
			for (List::Node* itr = list.begin(); itr != nullptr; itr = itr->p_next)
				if (itr->val < 0)
					p_negative = itr;

			if (p_negative)
			{
				list.pop(p_negative);
			}
			
			// �������� �������� ����� ����� ����������� ��������� ������ � ����� ������������ �������������� ��������
			int num;
			std::cout << "����� ������� �� ������� �: ";
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
		// �����
		case 10:
		{
			break;
		}
		default:
		{
			std::cout << "�������� �������� �� ������������� ���� ������!\n";
			std::cout << "�������� ������ ���� �� 1 �� 10 ������������, �������: " << action << std::endl;
			break;
		}
		}

	} while (action != 10);

	return 0;
}