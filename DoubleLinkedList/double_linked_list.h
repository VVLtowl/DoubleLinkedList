#pragma once
#include <string>

class DoubleLinkedList
{
public:
	/**���уf�[�^�\����*/
	struct ScoreData
	{
		int score;			/**<�X�R�A*/
		const std::string kName;	/**<���[�U�[��*/
	};

	/**�m�[�h�\����*/
	struct Node
	{
		Node* prev;				/**<�ڂ̃m�[�h�ւ̃|�C���^*/
		Node* next;				/**<���̃m�[�h�ւ̃|�C���^*/
		ScoreData scoreData;	/**<���уf�[�^*/
	};

	/** �R���X�g�C�e���[�^*/
	class ConstIterator
	{
	private:
		Node* node;												/**< Node�^�̃C�e���[�^*/
	public:
		ConstIterator() {};

		ConstIterator operator--();								/**<���X�g�̐擪�Ɍ������Ĉ�i�߂�*/
		ConstIterator operator++();								/**<���X�g�̖����Ɍ������Ĉ�i�߂�*/
		const ConstIterator operator*();						/**<�C�e���[�^�̎w���v�f���擾����(const��)*/
		ConstIterator(const ConstIterator& constIterator);		/**<�R�s�[���s��*/
		ConstIterator& operator=(ConstIterator& constIterator);	/**<������s��*/
		bool operator==(ConstIterator& constIterator);			/**<���ꂩ��r����*/
		bool operator!=(ConstIterator& constIterator);			/**<�قȂ邩��r����*/
	};

	/** �C�e���[�^*/
	class Iterator :public ConstIterator
	{
	public:
		ConstIterator operator*();		/**<�C�e���[�^�̂����v�f���擾����(��const��)*/
	};

private:
	Iterator* node;						/**<�m�[�h�ւ̃|�C���^*/

public:
	void Size();						/**<�f�[�^�����擾����*/
	void Add(Iterator iterator);		/**<�f�[�^�̑}��*/
	void Remove(Iterator iterator);		/**<�f�[�^�̍폜*/
	Iterator First();					/**<�擪�C�e���[�^�擾����*/
	ConstIterator ConstFirst();			/**<�擪�R���X�g�C�e���[�^�擾*/
	Iterator Last();					/**<�����C�e���[�^�擾����*/
	ConstIterator ConstLast();			/**<�����R���X�g�C�e���[�^�擾*/

};

