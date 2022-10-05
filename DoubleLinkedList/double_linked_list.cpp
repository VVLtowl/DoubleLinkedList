#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "double_linked_list.h"

/**<ノードポインタを設定*/
void DoubleLinkedList::ConstIterator::CopyNode(Node* node)
{
	(*this->node).prev = (*node).prev;
	(*this->node).next = (*node).next;
	(*this->node).scoreData.score = (*node).scoreData.score;
	strcpy((*this->node).scoreData.name, (*node).scoreData.name);
}

/**リストの先頭に向かって一つ進める*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--()
{
	node = (node->prev != nullptr) ?  node->prev : nullptr;
	return (*this);
}

/**リストの末尾に向かって一つ進める*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++()
{
	node = (node->next != nullptr) ? node->next : nullptr;
	return (*this);
}

/**イテレータの指す要素を取得する(const版)*/
const DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator*()
{
	const DoubleLinkedList::ConstIterator* constIterator =
		new const DoubleLinkedList::ConstIterator();

	return  *constIterator;
}

/**
* コピーを行う（コピーコンストラクタ）
* 宣言時、引数、戻り値の3つの動作でコピーがとられた時に実行されます
* 
*/
DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constIterator)
{
	node = new Node();

	if (constIterator.node == nullptr) return;

	(*node).prev = (*constIterator.node).prev;
	(*node).next = (*constIterator.node).next;
	(*node).scoreData.score = (*constIterator.node).scoreData.score;
	strcpy((*node).scoreData.name, (*constIterator.node).scoreData.name);
}

/**代入を行う*/
DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator=(ConstIterator& constIterator)
{
	//node = constIterator.node;
	(*node).prev = (*constIterator.node).prev;
	(*node).next = (*constIterator.node).next;
	(*node).scoreData.score = (*constIterator.node).scoreData.score;
	strcpy((*node).scoreData.name, (*constIterator.node).scoreData.name);

	return *this;
}

/**同一か比較する*/
bool DoubleLinkedList::ConstIterator::operator==(ConstIterator& constIterator)
{
	return strcmp(node->scoreData.name, constIterator.node->scoreData.name) == 0;
}

/**異なるか比較する*/
bool DoubleLinkedList::ConstIterator::operator!=(ConstIterator& constIterator)
{
	return strcmp(node->scoreData.name, constIterator.node->scoreData.name) != 0;
}

/**イテレータのさす要素を取得する(非const版)*/
DoubleLinkedList::Iterator DoubleLinkedList::Iterator::operator*()
{
	return *this;
}

/**<データを末尾後に追加*/
void DoubleLinkedList::PushBack(DoubleLinkedList::Node* newNode)
{
	/**
	* ノードポインタの指すところが空の場合、新しいノードへさす
	* 指すところ対象ががある場合、新ノードをこの対象の直後に追加し、
	* ノードポインタを新ノードへ指す
	*/
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

#if 1
	printf(":\n");//test
#endif
}

/**データ数を取得する*/
int DoubleLinkedList::Size()
{
	return 0;
}

/**データの挿入*/
void DoubleLinkedList::Add(Iterator iterator)
{
}

/**データの削除*/
void DoubleLinkedList::Remove(Iterator iterator)
{
}

/**先頭イテレータ取得する*/
DoubleLinkedList::Iterator DoubleLinkedList::Head()
{
	iterator->CopyNode(head);
	return (*iterator);/**<コピーコンストラクタよびだされる*/
}

/**先頭コンストイテレータ取得*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstHead()
{
	constIterator->CopyNode(head);
	return (*constIterator);
}

/**末尾イテレータ取得する*/
DoubleLinkedList::Iterator DoubleLinkedList::Tail()
{
	iterator->CopyNode(tail);
	return (*iterator);
}

/**末尾コンストイテレータ取得*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstTail()
{
	constIterator->CopyNode(tail);
	return (*constIterator);
}
