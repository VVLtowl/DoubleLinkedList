#pragma once

const int WORD_SIZE = 50;/**<������ǂݎ�̏��*/

class DoubleLinkedList
{
public:
	/**���уf�[�^�\����*/
	struct ScoreData
	{
		int score;				/**<�X�R�A*/
		char name[WORD_SIZE];	/**<���[�U�[��*/

		/**�R���X�g���N�^�Ń����o�[�ϐ��������ݒ�*/
		//ScoreData(int _score, string _kName) :
		//	score(_score),
		//	kName(_kName) {};
	};

	/**�m�[�h�\����*/
	struct Node
	{
		Node* prev = nullptr;			/**<�ڂ̃m�[�h�ւ̃|�C���^*/
		Node* next = nullptr;			/**<���̃m�[�h�ւ̃|�C���^*/
		ScoreData scoreData;			/**<���уf�[�^*/
	};

	/** �R���X�g�C�e���[�^*/
	class ConstIterator
	{
	private:
		Node* node;												/**< Node�^�̃C�e���[�^*/
		Node n;
	public:
		ConstIterator() { node = new Node(); };
		void CopyNode(Node* node);								/**<�m�[�h�|�C���^��ݒ�*/
		Node* GetNode() { return node; };						/**<�m�[�h�|�C���^���擾*/

		ConstIterator operator--();								/**<���X�g�̐擪�Ɍ������Ĉ�i�߂�*/
		ConstIterator operator++();								/**<���X�g�̖����Ɍ������Ĉ�i�߂�*/
		const ConstIterator operator*();						/**<�C�e���[�^�̎w���v�f���擾����(const��)*/
		ConstIterator(const ConstIterator& constIterator);		/**<�R�s�[���s���i�R�s�[�R���X�g���N�^�j*/
		ConstIterator& operator=(ConstIterator& constIterator);	/**<������s��*/
		bool operator==(ConstIterator& constIterator);			/**<���ꂩ��r����*/
		bool operator!=(ConstIterator& constIterator);			/**<�قȂ邩��r����*/
	};

	/** �C�e���[�^*/
	class Iterator :public ConstIterator
	{
	public:
		Iterator operator*();		/**<�C�e���[�^�̂����v�f���擾����(��const��)*/
	};

private:
	Node* head;							/**<�擪�m�[�h�ւ̃|�C���^*/
	Node* tail;							/**<�����m�[�h�ւ̃|�C���^*/
	Iterator* iterator;					/**<�m�[�h�̃C�e���[�^*/
	ConstIterator* constIterator;		/**<�m�[�h�̃R���X�g�C�e���[�^*/

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

	void PushBack(Node* newNode);		/**<�f�[�^�𖖔���ɒǉ�*/

	int Size();							/**<�f�[�^�����擾����*/
	void Add(Iterator iterator);		/**<�f�[�^�̑}��*/
	void Remove(Iterator iterator);		/**<�f�[�^�̍폜*/
	Iterator Head();					/**<�擪�C�e���[�^�擾����*/
	ConstIterator ConstHead();			/**<�擪�R���X�g�C�e���[�^�擾*/
	Iterator Tail();					/**<�����C�e���[�^�擾����*/
	ConstIterator ConstTail();			/**<�����R���X�g�C�e���[�^�擾*/
};

