#pragma once

const int WORD_SIZE = 50;/**<文字列読み取の上限*/

class DoubleLinkedList
{
public:
	/**成績データ構造体*/
	struct ScoreData
	{
		int score;				/**<スコア*/
		char name[WORD_SIZE];	/**<ユーザー名*/

		/**コンストラクタでメンバー変数を初期設定*/
		//ScoreData(int _score, string _kName) :
		//	score(_score),
		//	kName(_kName) {};
	};

	/**ノード構造体*/
	struct Node
	{
		Node* prev = nullptr;			/**<目のノードへのポインタ*/
		Node* next = nullptr;			/**<次のノードへのポインタ*/
		ScoreData scoreData;			/**<成績データ*/
	};

	/** コンストイテレータ*/
	class ConstIterator
	{
	private:
		Node* node;												/**< Node型のイテレータ*/
		Node n;
	public:
		ConstIterator() { node = new Node(); };
		void CopyNode(Node* node);								/**<ノードポインタを設定*/
		Node* GetNode() { return node; };						/**<ノードポインタを取得*/

		ConstIterator operator--();								/**<リストの先頭に向かって一つ進める*/
		ConstIterator operator++();								/**<リストの末尾に向かって一つ進める*/
		const ConstIterator operator*();						/**<イテレータの指す要素を取得する(const版)*/
		ConstIterator(const ConstIterator& constIterator);		/**<コピーを行う（コピーコンストラクタ）*/
		ConstIterator& operator=(ConstIterator& constIterator);	/**<代入を行う*/
		bool operator==(ConstIterator& constIterator);			/**<同一か比較する*/
		bool operator!=(ConstIterator& constIterator);			/**<異なるか比較する*/
	};

	/** イテレータ*/
	class Iterator :public ConstIterator
	{
	public:
		Iterator operator*();		/**<イテレータのさす要素を取得する(非const版)*/
	};

private:
	Node* head;							/**<先頭ノードへのポインタ*/
	Node* tail;							/**<末尾ノードへのポインタ*/
	Iterator* iterator;					/**<ノードのイテレータ*/
	ConstIterator* constIterator;		/**<ノードのコンストイテレータ*/

public:
	~DoubleLinkedList(){
		delete iterator;
		delete constIterator;
	}
	DoubleLinkedList(){
		head = nullptr;
		tail = nullptr;
		iterator = new Iterator();
		constIterator = new ConstIterator();
	}

	Node* GetHead() { return head; };
	Node* GetTail() { return tail; };

	void PushBack(Node* newNode);		/**<データを末尾後に追加*/

	int Size();							/**<データ数を取得する*/
	void Add(Iterator iterator);		/**<データの挿入*/
	void Remove(Iterator iterator);		/**<データの削除*/
	Iterator Head();					/**<先頭イテレータ取得する*/
	ConstIterator ConstHead();			/**<先頭コンストイテレータ取得*/
	Iterator Tail();					/**<末尾イテレータ取得する*/
	ConstIterator ConstTail();			/**<末尾コンストイテレータ取得*/
};

