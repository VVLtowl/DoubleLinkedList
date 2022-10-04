#include "double_linked_list.h"

/**<リストの先頭に向かって一つ進める*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--()
{
	node = node->prev;
	return *this;
}

/**<リストの末尾に向かって一つ進める*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++()
{
	node = node->next;
	return *this;
}

/**<イテレータの指す要素を取得する(const版)*/
const DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator*()
{
	const DoubleLinkedList::ConstIterator* constIterator =
		new const DoubleLinkedList::ConstIterator();

	return  *constIterator;
}

/**<コピーを行う*/
DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constIterator)
{
	node = new Node();

	//(*node).prev = (*constIterator.node).prev;
	//(*node).next = (*constIterator.node).next;
	//(*node).scoreData = (*constIterator.node).scoreData;
}
