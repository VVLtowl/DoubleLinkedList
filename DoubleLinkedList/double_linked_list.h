#pragma once
#include <string>

class DoubleLinkedList
{
public:
	/**成績データ構造体*/
	struct ScoreData
	{
		int score;			/**<スコア*/
		const std::string kName;	/**<ユーザー名*/
	};

	/**ノード構造体*/
	struct Node
	{
		Node* prev;				/**<目のノードへのポインタ*/
		Node* next;				/**<次のノードへのポインタ*/
		ScoreData scoreData;	/**<成績データ*/
	};

	/** コンストイテレータ*/
	class ConstIterator
	{
	private:
		Node* node;												/**< Node型のイテレータ*/
	public:
		ConstIterator() {};

		ConstIterator operator--();								/**<リストの先頭に向かって一つ進める*/
		ConstIterator operator++();								/**<リストの末尾に向かって一つ進める*/
		const ConstIterator operator*();						/**<イテレータの指す要素を取得する(const版)*/
		ConstIterator(const ConstIterator& constIterator);		/**<コピーを行う*/
		ConstIterator& operator=(ConstIterator& constIterator);	/**<代入を行う*/
		bool operator==(ConstIterator& constIterator);			/**<同一か比較する*/
		bool operator!=(ConstIterator& constIterator);			/**<異なるか比較する*/
	};

	/** イテレータ*/
	class Iterator :public ConstIterator
	{
	public:
		ConstIterator operator*();		/**<イテレータのさす要素を取得する(非const版)*/
	};

private:
	Iterator* node;						/**<ノードへのポインタ*/

public:
	void Size();						/**<データ数を取得する*/
	void Add(Iterator iterator);		/**<データの挿入*/
	void Remove(Iterator iterator);		/**<データの削除*/
	Iterator First();					/**<先頭イテレータ取得する*/
	ConstIterator ConstFirst();			/**<先頭コンストイテレータ取得*/
	Iterator Last();					/**<末尾イテレータ取得する*/
	ConstIterator ConstLast();			/**<末尾コンストイテレータ取得*/

};

