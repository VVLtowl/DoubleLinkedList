#include "double_linked_list.h"

/**<���X�g�̐擪�Ɍ������Ĉ�i�߂�*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--()
{
	node = node->prev;
	return *this;
}

/**<���X�g�̖����Ɍ������Ĉ�i�߂�*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++()
{
	node = node->next;
	return *this;
}

/**<�C�e���[�^�̎w���v�f���擾����(const��)*/
const DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator*()
{
	const DoubleLinkedList::ConstIterator* constIterator =
		new const DoubleLinkedList::ConstIterator();

	return  *constIterator;
}

/**<�R�s�[���s��*/
DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constIterator)
{
	node = new Node();

	//(*node).prev = (*constIterator.node).prev;
	//(*node).next = (*constIterator.node).next;
	//(*node).scoreData = (*constIterator.node).scoreData;
}
