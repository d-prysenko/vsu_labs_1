#include "List.h"

List::List()
// Ёто список инициализации, если не знаешь про него - почитай на ravesli
	: p_head(nullptr), p_last(nullptr), _size(0)
{}

// ѕри создании списка можно в конструктор сразу передать число и оно закинетс€ в список(хз зачем, но пусть будет)
List::List(Type val)
	: List()
{
	push_back(val);
}

// ƒеструктор
// ”дал€ем всЄ к ебене фене
List::~List()
{
	clear();
}

size_t List::get_size()
{
	return _size;
}

bool List::is_empty()
{
	return _size == 0;
}

List::Node* List::begin()
{
	return p_head;
}

List::Node* List::find(Type val)
{
	// ≈сли ниче нет, то возвращаем nullptr(это почти как обычный 0, только немножко покруче. тоже можешь про него почитать)
	if (p_head == nullptr)
		return nullptr;

	Node* p_node = p_head;

	// ѕеребираем все узлы пока не дойдем до конца или не найдем нужный
	while (p_node && p_node->val != val)
		p_node = p_node->p_next;

	// ≈сли дошли до конца, значит нужного не встретили
	if (p_node == nullptr)
		return nullptr;
	
	// ј если не дошли, значит вот оно золото
	return p_node;
}

void List::push_back(Type val)
{
	// ≈сли до этого список был пустой, то создаем первый элемент
	if (p_head == nullptr)
	{
		p_head = p_last = new Node(val);
		_size++;
		return;
	}

	// ¬от тот момент оптимизации
	// ћы не перебираем все элементы, пока не встретим последний, а просто используем указатель на последний элемент
	p_last->p_next = new Node(val);
	// Ќе забываем его изменить, чтобы он указывал на действительно последний элемент
	p_last = p_last->p_next;

	_size++;
}

void List::push_front(Type val)
{
	// ≈сли до этого список был пустой, то создаем первый элемент
	if (p_head == nullptr)
	{
		p_head = p_last = new Node(val);
		_size++;
		return;
	}

	Node* temp = p_head;
	p_head = new Node(val, temp);
	_size++;
}

void List::push_after(Node* p_node, Type val)
{
	if (p_node == nullptr)
		return;

	Node* temp = p_node->p_next;
	p_node->p_next = new Node(val, temp);

	if (p_node == p_last)
		p_last = p_node->p_next;

	_size++;
}

Type List::pop_front()
{
	if (p_head == nullptr)
	{
		return Type();
	}

	Node* temp = p_head;
	Type val = p_head->val;

	p_head = p_head->p_next;

	delete temp;

	_size--;
	return val;
}

Type List::pop_back()
{

	return pop(p_last);

}

Type List::pop_after(Node* p_node)
{
	Node* to_delete = p_node->p_next;
	Type val = to_delete->val;

	p_node->p_next = to_delete->p_next;

	delete to_delete;

	_size--;
	return val;
}

Type List::pop(Node* p_node)
{
	Node* temp = p_head;
	Type val = p_node->val;

	while ((temp != nullptr) && (temp->p_next != p_node)) temp = temp->p_next;

	if (temp == nullptr)
	{
		return Type();
	}

	if (p_node == p_last)
		p_last = temp;

	temp->p_next = p_node->p_next;

	delete p_node;

	_size--;
	return val;
}

void List::clear()
{
	while (p_head != nullptr) pop_front();
}

void List::print_this_shit()
{
	Node* p_temp = p_head;
	int i = 0;
	while (p_temp != nullptr)
	{
		printf("%d => %d\n", i, p_temp->val);
		p_temp = p_temp->p_next;
		i++;
	}
}
