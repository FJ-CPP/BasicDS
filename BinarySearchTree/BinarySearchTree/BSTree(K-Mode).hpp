#pragma once
template <class K>
struct BSTreeNode
{
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;
	BSTreeNode(K key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template <class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	bool insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;//���ɲ�����ͬ��ֵ
			}
		}
		if (key > parent->_key)
		{
			parent->_right = new Node(key);
		}
		else
		{
			parent->_left = new Node(key);
		}
		return true;
	}
	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur)//��Ҫɾ���Ľڵ�
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//ɾ���ڵ����ҵ�����������
			{
				//1��ɾ���ڵ����Ϊ�ջ������Ҷ�Ϊ�գ�Ҷ�ӽ�㣩
				if (cur->_left == nullptr)
				{
					//ɾ���ڵ���_root
					if (cur == _root)
					{
						_root = _root->_right;
					}
					//�ж�cur��parent����������������������������
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}
				//2��ɾ���ڵ����Ϊ��
				else if (cur->_right == nullptr)
				{
					//ɾ���ڵ���_root
					if (cur == _root)
					{
						_root = _root->_left;
					}
					//�ж�cur��parent����������������������������
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				//3��ɾ���ڵ�����Ҷ���Ϊ��
				else
				{
					//�ҵ������������ڵ��������������С�ڵ���������keyֵ����
					//����ѡ�񽻻������������ڵ�
  					Node* leftMax = cur->_left;
					parent = leftMax;
					while (leftMax->_right)//�����������ڵ�϶���_right��֧
					{
						parent = leftMax;
						leftMax = leftMax->_right;
					}
					swap(leftMax->_key, cur->_key);
					//keyֵ������ɺ�ɾ��leftMax	
					if (cur->_left == leftMax)//leftMax����cur����ڵ��Ҫͨ��cur->_leftɾ��
					{
						cur->_left = leftMax->_left;
					}
					else//�������ͨ��parentɾ��
					{
						parent->_right = leftMax->_left;
					}
					delete leftMax;
				}
				return true;
			}
		}
		//ɾ���ڵ�δ�ҵ�
		return false;
	}
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	void inorder()const
	{
		if (_root == nullptr)//����������Ϊ��
		{
			cout << "NULL" << endl;
			return;
		}
		_inorder(_root);
		cout << endl;
	}
private:
	Node* _root;
	void _inorder(const Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		cout << root->_key << " ";
		_inorder(root->_right);
	}
};